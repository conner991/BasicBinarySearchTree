/* -----------------------------------------------------------------------------
FILE NAME:         
DESCRIPTION:       A class of nodes for a link-based binary tree.
USAGE:             
COMPILER:          GNU g++ compiler on Linux
NOTES:             

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Conner Fissell     **-**-2020         1.0  Original version
----------------------------------------------------------------------------- */
#ifndef __BINARY_NODE_TREE_CPP__
#define __BINARY_NODE_TREE_CPP__

#include "BinaryNodeTree.h"

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:          Protected method getHeightHelper called by method getHeight. Defines
            Height as the number of nodes on the longest path from the root to a leaf.
            If we were defining it as the num of edges, then the base case would 
            return -1.
------------------------------------------------------------------------------- */
template <class DT>
int BinaryNodeTree<DT>::getHeightHelper(std::shared_ptr<BinaryNode<DT>> subTreePtr) const
{
    if (subTreePtr == nullptr)
        return 0;
    else
    {
        return 1 + std::max(getHeightHelper(subTreePtr->getLeftChildPtr()), getHeightHelper(subTreePtr->getRightChildPtr()));
    }
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:          Protected method getHeightHelper called by method getHeight   
------------------------------------------------------------------------------- */
template <class DT>
int BinaryNodeTree<DT>::getNumberOfNodesHelper(std::shared_ptr<BinaryNode<DT>> subTreePtr) const
{
    return 0;
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:           uses a recursive postorder traversal to delete each node 
                in the tree. A postorder traversal is appropriate here because 
                you can delete a node only after you have first traversed and 
                deleted both of its subtrees
------------------------------------------------------------------------------- */
template <class DT>
void BinaryNodeTree<DT>::destroyTree(std::shared_ptr<BinaryNode<DT>> subTreePtr)
{
    if (subTreePtr != nullptr)
    {
        destroyTree(subTreePtr->getLeftChildPtr());
        destroyTree(subTreePtr->getRightChildPtr());
        subTreePtr.reset(); // Decrement refernce count to node
    }
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:         The recursive call to balancedAdd adds the new node and returns a
            pointer to the revised subtree. However, we need to link this subtree
            to the rest of the tree. This is done through setRightChildPtr.    
------------------------------------------------------------------------------- */
template <class DT>
std::shared_ptr<BinaryNode<DT>> BinaryNodeTree<DT>::balancedAdd(std::shared_ptr<BinaryNode<DT>> subTreePtr, std::shared_ptr<BinaryNode<DT>> newNodePtr)
{
    if (subTreePtr == nullptr)
        return newNodePtr;

    else
    {
        auto leftPtr = subTreePtr->getLeftChildPtr();
        auto rightPtr = subTreePtr->getRightChildPtr();

        if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr))
        {
            rightPtr = balancedAdd(rightPtr, newNodePtr);
            subTreePtr->setRightChildPtr(rightPtr);
        }
        else
        {
            leftPtr = balancedAdd(leftPtr, newNodePtr);
            subTreePtr->setLeftChildPtr(leftPtr);
        }

        return subTreePtr;
    }
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
std::shared_ptr<BinaryNode<DT>> BinaryNodeTree<DT>::removeValue(std::shared_ptr<BinaryNode<DT>> subtreePtr,
                                                                const DT target, bool &success)
{
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
std::shared_ptr<BinaryNode<DT>> BinaryNodeTree<DT>::moveValuesUpTree(std::shared_ptr<BinaryNode<DT>> subtreePtr)
{
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:         Recursively searches for target value in the tree by using a
                preorder traversal.   
------------------------------------------------------------------------------- */
template <class DT>
std::shared_ptr<BinaryNode<DT>> BinaryNodeTree<DT>::findNode(std::shared_ptr<BinaryNode<DT>> treePtr,
                                                             const DT &target, bool &success) const
{
    if (treePtr == nullptr)
        return nullptr; // Not found

    else if (treePtr->getItem() == target)
        return treePtr; // Found

    else if (treePtr->getItem() > target)
        return findNode(treePtr->getLeftChildPtr(), target); // Search left sub tree

    else
        return findNode(treePtr->getRightChildPtr(), target); // Search right sub tree
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       Protected method copyTree called by copy constructor
RETURNS:           
NOTES:             Must be linked together by using new pointers. You 
                cannot simply copy the pointers in the nodes of the original tree. Deep Copy
------------------------------------------------------------------------------- */
template <class DT>
std::shared_ptr<BinaryNode<DT>> BinaryNodeTree<DT>::copyTree(const std::shared_ptr<BinaryNode<DT>> oldTreerootPtr) const
{
    std::shared_ptr<BinaryNode<DT>> newTreePtr;

    // Copy tree nodes during a preorder traversal
    if (oldTreerootPtr != nullptr)
    {
        // Copy Node
        newTreePtr = std::make_shared<BinaryNode<DT>>(oldTreerootPtr->getItem(), nullptr, nullptr);
        newTreePtr->setLeftChildPtr(copyTree(oldTreerootPtr->getLeftChildPtr()));
        newTreePtr->setRightChildPtr(copyTree(oldTreerootPtr->getRightChildPtr()));
    }
    return newTreePtr;
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
void BinaryNodeTree<DT>::preorder(void visit(DT &), std::shared_ptr<BinaryNode<DT>> treePtr) const
{
    if (treePtr != nullptr)
    {
        DT theItem = treePtr->getItem();
        visit(theItem);
        preorder(visit, treePtr->getLeftChildPtr());
        preorder(visit, treePtr->getRightChildPtr());
    }
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:           Protected method that enables recursive traversals. 
            Public traversal methods will call these protected methods.  
------------------------------------------------------------------------------- */
template <class DT>
void BinaryNodeTree<DT>::inorder(void visit(DT &), std::shared_ptr<BinaryNode<DT>> treePtr) const
{
    if (treePtr != nullptr)
    {
        inorder(visit, treePtr->getLeftChildPtr());
        DT theItem = treePtr->getItem();
        visit(theItem); // Client can not only access but can also modify it
        inorder(visit, treePtr->getRightChildPtr());
    }
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
void BinaryNodeTree<DT>::postorder(void visit(DT &), std::shared_ptr<BinaryNode<DT>> treePtr) const
{
    if (treePtr != nullptr)
    {
        postorder(visit, treePtr->getLeftChildPtr());
        postorder(visit, treePtr->getRightChildPtr());
        DT theItem = treePtr->getItem();
        visit(theItem);
    }
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
BinaryNodeTree<DT>::BinaryNodeTree()
    : rootPtr(nullptr)
{
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             rootPtr = new BinaryNode<ItemType>(rootItem, nullptr, nullptr);
                If there were no smart pointers^
------------------------------------------------------------------------------- */
template <class DT>
BinaryNodeTree<DT>::BinaryNodeTree(const DT &rootItem)
    : rootPtr(std::shared_ptr<BinaryNode<DT>>(rootItem, nullptr, nullptr))
{
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             Requires implicit use of traversal. Role of the protected
                    method copyTree
------------------------------------------------------------------------------- */
template <class DT>
BinaryNodeTree<DT>::BinaryNodeTree(const DT &rootItem, const std::shared_ptr<BinaryNode<DT>> leftTreePtr,
                                   const std::shared_ptr<BinaryNode<DT>> rightTreePtr)
    : rootPtr(std::shared_ptr<BinaryNode<DT>>(rootItem, copyTree(leftTreePtr->rootPtr), copyTree(rightTreePtr->rootPtr)))
{
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       Copy Constructor
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
BinaryNodeTree<DT>::BinaryNodeTree(const BinaryNodeTree<DT> &treePtr)
{
    rootPtr = copyTree(treePtr.rootPtr);
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:              
------------------------------------------------------------------------------- */
template <class DT>
BinaryNodeTree<DT>::~BinaryNodeTree()
{
    
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
void BinaryNodeTree<DT>::visit(DT &theItem)
{
    std::cout << theItem << std::endl;
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
bool BinaryNodeTree<DT>::isEmpty() const
{
    return true;
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
int BinaryNodeTree<DT>::getHeight() const
{
    return getHeightHelper(rootPtr);
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:        The method getNumberOfNodes has a similar definition.
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
int BinaryNodeTree<DT>::getNumberOfNodes() const
{
    return 0;
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
DT BinaryNodeTree<DT>::getRootData() const
{
    DT thing;
    return thing;
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
void BinaryNodeTree<DT>::setRootData(const DT &newData)
{
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
bool BinaryNodeTree<DT>::add(const DT &newData)
{
    auto newNodePtr = std::make_shared<BinaryNode<DT>>(newData);
    rootPtr = balancedAdd(rootPtr, newNodePtr);

    return true;
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       ***
RETURNS:           
NOTES:            
------------------------------------------------------------------------------- */
template <class DT>
bool BinaryNodeTree<DT>::remove(const DT &data)
{
    return true;
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:            
------------------------------------------------------------------------------- */
template <class DT>
void BinaryNodeTree<DT>::clear()
{
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:            
------------------------------------------------------------------------------- */
template <class DT>
DT BinaryNodeTree<DT>::getEntry(const DT &anEntry) const
{
    DT thing1;
    return thing1;
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:            
------------------------------------------------------------------------------- */
template <class DT>
bool BinaryNodeTree<DT>::contains(const DT &anEntry) const
{
    return true;
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:            
------------------------------------------------------------------------------- */
template <class DT>
void BinaryNodeTree<DT>::preorderTraverse(void visit(DT &)) const
{
    preorder(visit, rootPtr);
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:            
------------------------------------------------------------------------------- */
template <class DT>
void BinaryNodeTree<DT>::inorderTraverse(void visit(DT &)) const
{
    inorder(visit, rootPtr);
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:            
------------------------------------------------------------------------------- */
template <class DT>
void BinaryNodeTree<DT>::postorderTraverse(void visit(DT &)) const
{
    postorder(visit, rootPtr);
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:            
------------------------------------------------------------------------------- 
template <class DT>
BinaryNodeTree<DT> &BinaryNodeTree<DT>::operator=(const BinaryNodeTree<DT> &rightHandSide)
{
}*/

#endif
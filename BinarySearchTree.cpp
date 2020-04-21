/* -----------------------------------------------------------------------------
FILE NAME:         
DESCRIPTION:       Link-based implementation of the ADT binary search tree.
USAGE:             
COMPILER:          GNU g++ compiler on Linux
NOTES:             

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Conner Fissell     **-**-2020         1.0  Original version
----------------------------------------------------------------------------- */
#ifndef __BINARY_SEARCH_TREE_CPP__
#define __BINARY_SEARCH_TREE_CPP__

#include "BinarySearchTree.h"

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:            Recursively places a given new node at its proper position in 
                a binary search tree  
------------------------------------------------------------------------------- */
template <class DT>
std::shared_ptr<BinaryNode<DT>> BinarySearchTree<DT>::placeNode(std::shared_ptr<BinaryNode<DT>> subTreePtr,
                                                                std::shared_ptr<BinaryNode<DT>> newsubTreePtr)
{
    if (subTreePtr == nullptr)
        return newsubTreePtr;

    else if (subTreePtr->getItem() > newsubTreePtr->getItem())
    {
        std::shared_ptr<BinaryNode<DT>> tempPtr = placeNode(subTreePtr->getLeftChildPtr(), newsubTreePtr);
        subTreePtr->setLeftChildPtr(tempPtr);
    }
    else
    {
        std::shared_ptr<BinaryNode<DT>> tempPtr = placeNode(subTreePtr->getRightChildPtr(), newsubTreePtr);
        subTreePtr->setRightChildPtr(tempPtr);
    }

    return subTreePtr;
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
std::shared_ptr<BinaryNode<DT>> BinarySearchTree<DT>::removeValue(std::shared_ptr<BinaryNode<DT>> subTreePtr,
                                                                  const DT target, bool &isSuccessful)
{

    if (subTreePtr == nullptr)
    {
        isSuccessful = false;
        return nullptr;
    }

    else if (subTreePtr->getItem() == target)
    {
        // Item is in the root of some sub tree
        subTreePtr = removeNode(subTreePtr); // Remove the item
        isSuccessful = true;
    }

    else if (subTreePtr->getItem() > target)
    {
        // Search the left sub tree
        std::shared_ptr<BinaryNode<DT>> tempPtr = removeValue(subTreePtr->getLeftChildPtr(), target, isSuccessful);
        subTreePtr->setLeftChildPtr(tempPtr);
    }

    else
    {
        // search the right subtree
        std::shared_ptr<BinaryNode<DT>> tempPtr = removeValue(subTreePtr->getRightChildPtr(), target, isSuccessful);
        subTreePtr->setRightChildPtr(tempPtr);
    }

    return subTreePtr;
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:        Removes the data item in the node N to which subTreePtr points.
            Returns a pointer to the node at this tree location after the removal     
------------------------------------------------------------------------------- */
template <class DT>
std::shared_ptr<BinaryNode<DT>> BinarySearchTree<DT>::removeNode(std::shared_ptr<BinaryNode<DT>> nodePtr)
{
    DT newNodeValue;

    if ((nodePtr->getLeftChildPtr() == nullptr) && (nodePtr->getRightChildPtr() == nullptr)) // Node is a leaf
    {
        // Remove leaf from the tree
        return nodePtr;
    }

    else if ((nodePtr->getLeftChildPtr() == nullptr) || (nodePtr->getRightChildPtr() == nullptr)) // Node has one child
    {
        std::shared_ptr<BinaryNode<DT>> nodeToConnectPtr;

        if (nodePtr->getRightChildPtr() == nullptr) // If the node has a left child
            nodeToConnectPtr = nodePtr->getLeftChildPtr();

        else
        {
            nodeToConnectPtr = nodePtr->getRightChildPtr();
            nodePtr = nullptr;
        }

        return nodeToConnectPtr;
    }

    else // Node has two children
    {
        // Find the inorder successor of the entry in subTreePtr Node: it is in the left
        // subtree rooted at N’s right child
        std::shared_ptr<BinaryNode<DT>> tempPtr = removeLeftmostNode(nodePtr->getRightChildPtr(), newNodeValue);
        nodePtr->setRightChildPtr(tempPtr);
        nodePtr->setItem(newNodeValue); // Put replacement value in node
        return nodePtr;
    }
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:        Removes the leftmost node in the left subtree of the node pointed to by subTreePtr.
            Sets inorder Successor to the value in this node. Returns a pointer to the revised subtree     
------------------------------------------------------------------------------- */
template <class DT>
std::shared_ptr<BinaryNode<DT>> BinarySearchTree<DT>::removeLeftmostNode(std::shared_ptr<BinaryNode<DT>> subTreePtr,
                                                                         DT &inorderSuccessor)
{
    if (subTreePtr->getLeftChildPtr() == nullptr)
    {
        // This is the node we want, it has no left child, but it might have a right sub tree
        inorderSuccessor = subTreePtr->getItem();
        return removeNode(subTreePtr);
    }

    else
    {
        std::shared_ptr<BinaryNode<DT>> tempPtr = removeLeftmostNode(subTreePtr->getLeftChildPtr(), inorderSuccessor);
        subTreePtr->setLeftChildPtr(tempPtr);
        return subTreePtr;
    }
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:         Locates the node in the binary search tree to which treePtr 
            points that contains the value target. Returns either a pointer to 
            the located node or nullptr if such a node is not found.   
------------------------------------------------------------------------------- */
template <class DT>
std::shared_ptr<BinaryNode<DT>> BinarySearchTree<DT>::findNode(std::shared_ptr<BinaryNode<DT>> treePtr,
                                                               const DT &target) const
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
DESCRIPTION:       
RETURNS:           
NOTES:            
------------------------------------------------------------------------------- */
template <class DT>
BinarySearchTree<DT>::BinarySearchTree()
    : rootPtr(nullptr)
{
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:            
------------------------------------------------------------------------------- */
template <class DT>
BinarySearchTree<DT>::BinarySearchTree(const DT &rootItem)
    : rootPtr(std::shared_ptr<BinaryNode<DT>>(rootItem, nullptr, nullptr))
{
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:            
------------------------------------------------------------------------------- */
template <class DT>
BinarySearchTree<DT>::BinarySearchTree(const BinarySearchTree<DT> &treePtr)
{
    rootPtr = std::shared_ptr<BinaryNodeTree<DT>>(treePtr);
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:            
------------------------------------------------------------------------------- */
template <class DT>
BinarySearchTree<DT>::~BinarySearchTree()
{
    // clear method?
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
-------------------------------------------------------------------------------*/
template <class DT>
void BinarySearchTree<DT>::visit(DT &theItem)
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
bool BinarySearchTree<DT>::isEmpty() const
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
int BinarySearchTree<DT>::getHeight() const
{
    return this->getHeightHelper(rootPtr);
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:            
------------------------------------------------------------------------------- */
template <class DT>
int BinarySearchTree<DT>::getNumberOfNodes() const
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
DT BinarySearchTree<DT>::getRootData() const
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
void BinarySearchTree<DT>::setRootData(const DT &newData)
{
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
bool BinarySearchTree<DT>::add(const DT &newData)
{   
    auto newsubTreePtr = std::make_shared<BinaryNode<DT>>(newData);
    rootPtr = placeNode(rootPtr, newsubTreePtr);

    return true;
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:            
------------------------------------------------------------------------------- */
template <class DT>
bool BinarySearchTree<DT>::remove(const DT &target)
{
    bool isSuccessful = false;
    rootPtr = removeValue(rootPtr, target, isSuccessful);
    return isSuccessful;
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:            
------------------------------------------------------------------------------- */
template <class DT>
void BinarySearchTree<DT>::clear()
{
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:            
------------------------------------------------------------------------------- */
template <class DT>
DT BinarySearchTree<DT>::getEntry(const DT &anEntry) const
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
bool BinarySearchTree<DT>::contains(const DT &anEntry) const
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
void BinarySearchTree<DT>::preorderTraverse(void visit(DT &, std::fstream&), std::fstream& fileOut) const
{   
    
    this->preorder(visit, rootPtr, fileOut);

}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:            
------------------------------------------------------------------------------- */
template <class DT>
void BinarySearchTree<DT>::inorderTraverse(void visit(DT &, std::fstream&), std::fstream& fileOut) const
{   

    this->inorder(visit, rootPtr, fileOut);

}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:            
------------------------------------------------------------------------------- */
template <class DT>
void BinarySearchTree<DT>::postorderTraverse(void visit(DT &, std::fstream&), std::fstream& fileOut) const
{   
    
    this->postorder(visit, rootPtr, fileOut);

}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:            
------------------------------------------------------------------------------- 
template <class DT>
BinarySearchTree<DT> &BinarySearchTree<DT>::operator=(const BinarySearchTree<DT> &rightHandSide)
{
}*/

#endif
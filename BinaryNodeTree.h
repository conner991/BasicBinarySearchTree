/* -----------------------------------------------------------------------------
FILE NAME:         
DESCRIPTION:        ADT binary tree: Link-based implementation. 
USAGE:             
COMPILER:          GNU g++ compiler on Linux
NOTES:             

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Conner Fissell     **-**-2020         1.0  Original version
----------------------------------------------------------------------------- */
#ifndef __BINARY_NODE_TREE_H__
#define __BINARY_NODE_TREE_H__

#include "BinaryTreeInterface.h"
#include "BinaryNode.h"

template <class DT>
class BinaryNodeTree : public BinaryTreeInterface<DT>
{
private:
    std::shared_ptr<BinaryNode<DT>> rootPtr;

protected:
    //------------------------------------------------------------
    // Protected Utility Methods Section:
    // Recursive helper methods for the public methods.
    //------------------------------------------------------------
    int getHeightHelper(std::shared_ptr<BinaryNode<DT>> subTreePtr) const;
    int getNumberOfNodesHelper(std::shared_ptr<BinaryNode<DT>> subtreePtr) const;

    // Recursively deletes all nodes from the tree.
    void destroyTree(std::shared_ptr<BinaryNode<DT>> subTreePtr);

    // Recursively adds a new node to the tree in a left/right fashion to
    // keep the tree balanced.
    std::shared_ptr<BinaryNode<DT>> balancedAdd(std::shared_ptr<BinaryNode<DT>> subTreePtr, std::shared_ptr<BinaryNode<DT>> newNodePtr);

    // Removes the target value from the tree by calling moveValuesUpTree
    // to overwrite value with value from child.
    std::shared_ptr<BinaryNode<DT>> removeValue(std::shared_ptr<BinaryNode<DT>> subtreePtr, const DT target, bool &success);

    // Copies values up the tree to overwrite value in current node until
    // a leaf is reached; the leaf is then removed, since its value is
    // stored in the parent.
    std::shared_ptr<BinaryNode<DT>> moveValuesUpTree(std::shared_ptr<BinaryNode<DT>> subTreePtr);

    // Recursively searches for target value in the tree by using a
    // preorder traversal.
    std::shared_ptr<BinaryNode<DT>> findNode(std::shared_ptr<BinaryNode<DT>> treePtr, const DT &target, bool &success) const;

    // Copies the tree rooted at treePtr and returns a pointer to
    // the copy.
    std::shared_ptr<BinaryNode<DT>> copyTree(const std::shared_ptr<BinaryNode<DT>> treePtr) const;

    // Recursive traversal helper methods:
    void preorder(void visit(DT &), std::shared_ptr<BinaryNode<DT>> treePtr) const;
    void inorder(void visit(DT &), std::shared_ptr<BinaryNode<DT>> treePtr) const;
    void postorder(void visit(DT &), std::shared_ptr<BinaryNode<DT>> treePtr) const;

public:
    //------------------------------------------------------------
    // Constructor and Destructor Section.
    //------------------------------------------------------------
    BinaryNodeTree();
    BinaryNodeTree(const DT &rootItem);
    BinaryNodeTree(const DT &rootItem, const std::shared_ptr<BinaryNode<DT>> leftTreePtr, const std::shared_ptr<BinaryNode<DT>> rightTreePtr);
    BinaryNodeTree(const BinaryNodeTree<DT> &tree);
    virtual ~BinaryNodetree();

    //------------------------------------------------------------
    // Public BinaryTreeInterface Methods Section.
    //------------------------------------------------------------
    bool isEmpty() const;
    int getHeight() const;
    int getNumberOfNodes() const;
    DT getRootData() const;
    void setRootData(const DT &newData);
    bool add(const DT &newData);
    bool remove(const DT &data);
    void clear();
    DT getEntry(const DT &anEntry) const;
    bool contains(const DT &anEntry) const;

    //------------------------------------------------------------
    // Public Traversal Section.
    //------------------------------------------------------------
    void preorderTraverse(void visit(DT &)) const;
    void inorderTraverse(void visit(DT &)) const;
    void postorderTraverse(void visit(DT &)) const;

    //------------------------------------------------------------
    // Overloaded Operator Section.
    //------------------------------------------------------------
    BinaryNodeTree &operator=(const BinaryNodeTree &rightHandSide);
};

#include "BinaryNodeTree.cpp"

#endif
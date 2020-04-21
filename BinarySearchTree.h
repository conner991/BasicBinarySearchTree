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
#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "BinaryNodeTree.h"

template <class DT>
class BinarySearchTree : public BinaryNodeTree<DT>
{
private:
    std::shared_ptr<BinaryNode<DT>> rootPtr;

protected:
    //------------------------------------------------------------
    // Protected Utility Methods Section:
    // Recursive helper methods for the public methods.
    //------------------------------------------------------------
    // Recursively finds where the given node should be placed and
    // inserts it in a leaf at that point.
    std::shared_ptr<BinaryNode<DT>> placeNode(std::shared_ptr<BinaryNode<DT>> subTreePtr, std::shared_ptr<BinaryNode<DT>> newNodePtr);

    // Removes the given target value from the tree while maintaining a
    // binary search tree.
    std::shared_ptr<BinaryNode<DT>> removeValue(std::shared_ptr<BinaryNode<DT>> subTreePtr, const DT target, bool &isSuccessful);

    // Removes a given node from a tree while maintaining a binary search tree.
    std::shared_ptr<BinaryNode<DT>> removeNode(std::shared_ptr<BinaryNode<DT>> nodePtr);

    // Removes the leftmost node in the left subtree of the node
    // pointed to by nodePtr.
    // Sets inorderSuccessor to the value in this node.
    // Returns a pointer to the revised subtree.
    std::shared_ptr<BinaryNode<DT>> removeLeftmostNode(std::shared_ptr<BinaryNode<DT>> nodePtr, DT &inorderSuccessor);

    // Returns a pointer to the node containing the given value,
    // or nullptr if not found.
    std::shared_ptr<BinaryNode<DT>> findNode(std::shared_ptr<BinaryNode<DT>> treePtr, const DT &target) const;

public:
    //------------------------------------------------------------
    // Constructor and Destructor Section.
    //------------------------------------------------------------
    BinarySearchTree();
    BinarySearchTree(const DT &rootItem);
    BinarySearchTree(const BinarySearchTree<DT> &tree);
    virtual ~BinarySearchTree();

    void visit(DT &theItem);

    //------------------------------------------------------------
    // Public Methods Section. From Interface
    //------------------------------------------------------------
    bool isEmpty() const override;
    int getHeight() const override;
    int getNumberOfNodes() const override;
    DT getRootData() const override;
    void setRootData(const DT &newData) override;
    bool add(const DT &newEntry) override;
    bool remove(const DT &target) override;
    void clear() override;
    DT getEntry(const DT &anEntry) const override;
    bool contains(const DT &anEntry) const override;

    //------------------------------------------------------------
    // Public Traversals Section. From Interface
    //------------------------------------------------------------
    void preorderTraverse(void visit(DT &)) const override;
    void inorderTraverse(void visit(DT &)) const override;
    void postorderTraverse(void visit(DT &)) const override;

    //------------------------------------------------------------
    // Overloaded Operator Section.
    //------------------------------------------------------------
    // BinarySearchTree<DT> &operator=(const BinarySearchTree<DT> &rightHandSide) override;
};

#include "BinarySearchTree.cpp"

#endif
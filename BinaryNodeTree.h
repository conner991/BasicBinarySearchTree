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
    void preorder(void visit(DT &, std::fstream&), std::shared_ptr<BinaryNode<DT>> treePtr, std::fstream&) const;
    void inorder(void visit(DT &, std::fstream&), std::shared_ptr<BinaryNode<DT>> treePtr, std::fstream&) const;
    void postorder(void visit(DT &, std::fstream&), std::shared_ptr<BinaryNode<DT>> treePtr, std::fstream&) const;

public:
    //------------------------------------------------------------
    // Constructor and Destructor Section.
    //------------------------------------------------------------
    BinaryNodeTree();                                                                                                                          // Default Constructor
    BinaryNodeTree(const DT &rootItem);                                                                                                        // Paramaterized Con 1
    BinaryNodeTree(const DT &rootItem, const std::shared_ptr<BinaryNode<DT>> leftTreePtr, const std::shared_ptr<BinaryNode<DT>> rightTreePtr); // Paramaterized Con 2
    BinaryNodeTree(const BinaryNodeTree<DT> &tree);                                                                                            // Copy Constructor
    virtual ~BinaryNodeTree();

    // -----------------------------------------------------------
    void visit(DT &theItem);

    //------------------------------------------------------------
    // Public BinaryTreeInterface Methods Section.
    //------------------------------------------------------------
    virtual bool isEmpty() const;
    virtual int getHeight() const;
    virtual int getNumberOfNodes() const;
    virtual DT getRootData() const;
    virtual void setRootData(const DT &newData);
    virtual bool add(const DT &newData);
    virtual bool remove(const DT &data);
    virtual void clear();
    virtual DT getEntry(const DT &anEntry) const;
    virtual bool contains(const DT &anEntry) const;

    //------------------------------------------------------------
    // Public Traversal Section.
    //------------------------------------------------------------
    // virtual void preorderTraverse(void visit(DT &, std::fstream&)) const;
    // virtual void inorderTraverse(void visit(DT &, std::fstream&)) const;
    // virtual void postorderTraverse(void visit(DT &, std::fstream&)) const;

    //------------------------------------------------------------
    // Overloaded Operator Section.
    //------------------------------------------------------------
    // virtual BinaryNodeTree<DT> &operator=(const BinaryNodeTree<DT> &rightHandSide);
};

#include "BinaryNodeTree.cpp"

#endif
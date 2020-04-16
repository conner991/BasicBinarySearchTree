/* -----------------------------------------------------------------------------
FILE NAME:         
DESCRIPTION:       
USAGE:             
COMPILER:          GNU g++ compiler on Linux
NOTES:             

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Conner Fissell     **-**-2020         1.0  Original version
----------------------------------------------------------------------------- */
#ifndef __BINARY_TREE_INTERFACE_H__
#define __BINARY_TREE_INTERFACE_H__

template <class DT>
class BinaryTreeInterface
{
public:
    virtual bool isEmpty() const = 0;
    virtual int getHeight() const = 0;
    virtual int getNumberOfNodes() const = 0;
    virtual DT getRootData() const = 0;
    virtual void setRootData(const DT &newData) = 0;
    virtual bool add(const DT &newData) = 0;
    virtual bool remove(const DT &data) = 0;
    virtual void clear() = 0;
    virtual DT getEntry(const DT &anEntry) const = 0;
    virtual bool contains(const DT &anEntry) const = 0;
    virtual void preorderTraverse(void visit(DT &)) const = 0;
    virtual void inorderTraverse(void visit(DT &)) const = 0;
    virtual void postorderTraverse(void visit(DT &)) const = 0;
};

#endif

/* Tests whether this binary tree is empty.
 @return True if the binary tree is empty, or false if not. */

/* Gets the height of this binary tree.
 @return The height of the binary tree. */

/* Gets the number of nodes in this binary tree.
 @return The number of nodes in the binary tree. */

/* Gets the data that is in the root of this binary tree.
 @pre The binary tree is not empty.
 @post The root’s data has been returned, and the binary tree is unchanged.
 @return The data in the root of the binary tree. */

/* Replaces the data item in the root of this binary tree
 with the given data, if the tree is not empty. However, if the tree is empty, 
 inserts a new root node containing the
 given data into the tree.
 @pre None.
 @post The data in the root of the binary tree is as given.
 @param newData The data for the root. */

/* Adds a new node containing the given data to this binary tree.
 @param newData The data for the new node. 
 @post The binary tree contains a new node.
 @return True if the addition is successful, or false not. */

/* Removes the node containing the given data item from this binary tree.
 @param data The data value to remove from the binary tree.
 @return True if the removal is successful, or false not. */

/** Removes all nodes from this binary tree. */

/* Gets a specific entry in this binary tree.
 @post The desired entry has been returned, and the binary tree
 is unchanged. If no such entry was found, an exception is thrown.
 @param anEntry The entry to locate.
 @return The entry in the binary tree that matches the given entry.
 @throw NotFoundException if the given entry is not in the tree. */

/* Tests whether a given entry occurs in this binary tree.
 @post The binary search tree is unchanged.
 @param anEntry The entry to find.
 @return True if the entry occurs in the tree, or false if not. */

/* Traverses this binary tree in preorder (inorder, postorder) and
 calls the function visit once for each node.
 @param visit A client-defined function that performs an operation on
 or with the data in each visited node. */

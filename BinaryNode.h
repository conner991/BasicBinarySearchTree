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
#ifndef __BINARY_NODE_H__
#define __BINARY_NODE_H__

#include "BinaryTreeInterface.h"

#include <iostream>
#include <memory>
#include <algorithm>
#include <ctime>
#include <fstream>

template <class DT>
class BinaryNode
{
private:
    DT item;                                       // Data Portion
    std::shared_ptr<BinaryNode<DT>> leftChildPtr;  // Pointer to the Left Child
    std::shared_ptr<BinaryNode<DT>> rightChildPtr; // Pointer to the Right Child

public:
    BinaryNode();
    BinaryNode(const DT &anItem);
    BinaryNode(const DT &anItem, std::shared_ptr<BinaryNode<DT>> leftPtr, std::shared_ptr<BinaryNode<DT>> rightPtr);
    virtual ~BinaryNode();
    void setItem(const DT &anItem);
    DT getItem() const;
    bool isLeaf() const;
    std::shared_ptr<BinaryNode<DT>> getLeftChildPtr() const;
    std::shared_ptr<BinaryNode<DT>> getRightChildPtr() const;
    void setLeftChildPtr(std::shared_ptr<BinaryNode<DT>> leftPtr);
    void setRightChildPtr(std::shared_ptr<BinaryNode<DT>> rightPtr);
};

#include "BinaryNode.cpp"

#endif
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
#ifndef __BINARY_NODE_CPP__
#define __BINARY_NODE_CPP__

#include "BinaryNode.h"

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:              
------------------------------------------------------------------------------- */
template <class DT>
BinaryNode<DT>::BinaryNode()
    : leftChildPtr(nullptr), rightChildPtr(nullptr)
{
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:              
------------------------------------------------------------------------------- */
template <class DT>
BinaryNode<DT>::BinaryNode(const DT &anItem)
    : item(anItem), leftChildPtr(nullptr), rightChildPtr(nullptr)
{
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:              
------------------------------------------------------------------------------- */
template <class DT>
BinaryNode<DT>::BinaryNode(const DT &anItem, std::shared_ptr<BinaryNode<DT>> leftPtr,
                           std::shared_ptr<BinaryNode<DT>> rightPtr)
    : item(anItem), leftChildPtr(leftPtr), rightChildPtr(rightPtr)
{
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:              
------------------------------------------------------------------------------- */
template <class DT>
BinaryNode<DT>::~BinaryNode()
{
    
}
/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:              
------------------------------------------------------------------------------- */
template <class DT>
void BinaryNode<DT>::setItem(const DT &anItem)
{
    item = anItem;
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:              
------------------------------------------------------------------------------- */
template <class DT>
DT BinaryNode<DT>::getItem() const
{
    return item;
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:              
------------------------------------------------------------------------------- */
template <class DT>
bool BinaryNode<DT>::isLeaf() const
{
    if ((leftChildPtr == nullptr) && (rightChildPtr == nullptr))
        return true;

    else
        return false;
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:              
------------------------------------------------------------------------------- */
template <class DT>
std::shared_ptr<BinaryNode<DT>> BinaryNode<DT>::getLeftChildPtr() const
{
    return leftChildPtr;
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:              
------------------------------------------------------------------------------- */
template <class DT>
std::shared_ptr<BinaryNode<DT>> BinaryNode<DT>::getRightChildPtr() const
{
    return rightChildPtr;
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:              
------------------------------------------------------------------------------- */
template <class DT>
void BinaryNode<DT>::setLeftChildPtr(std::shared_ptr<BinaryNode<DT>> leftPtr)
{
    leftChildPtr = leftPtr;
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:              
------------------------------------------------------------------------------- */
template <class DT>
void BinaryNode<DT>::setRightChildPtr(std::shared_ptr<BinaryNode<DT>> rightPtr)
{
    rightChildPtr = rightPtr;
}

#endif
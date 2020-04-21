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
#include "BinarySearchTree.h"

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])

// #pragma warning(disable : 4996)

// Prototypes
void RNG(int treeNums[], int range);
void visit(int &num);
/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
int main()
{
    int range = 25;
    int treeNums[range];

    // Generate random numbers, insert in array
    RNG(treeNums, range);

    // Insert numbers into a BST
    BinarySearchTree<int> *tree;

    for (int i = 0; i < ARRAY_SIZE(treeNums); i++)
    {
        if (!tree->add(treeNums[i]))
        {
            std::cout << "Value(s) not entered correctly\n\n";
            break;
        }
    }

    // traverse and display
    tree->preorderTraverse(visit);
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
void RNG(int treeNums[], int range)
{

    //RNG
    unsigned seed = time(0);
    srand(seed);

    for (int i = 0; i < range; i++)
    {
        treeNums[i] = (rand() % range) + 1;
    }
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
void visit(int &num)
{
    std::cout << num << std::endl;
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
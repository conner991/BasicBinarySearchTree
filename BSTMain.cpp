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
void RNG(std::vector<int>& treeNums);
void visit(int &num);
/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
int main()
{
    
    std::vector<int> treeNums;
    
    // Generate random numbers, insert into a vector
    RNG(treeNums);
    
    // Insert numbers into a BST
     std::shared_ptr<BinarySearchTree<int>> tree = std::make_shared<BinarySearchTree<int>>();

    // BinarySearchTree<int> tree;//std::cout << "HERE\n";

    for (int i = 0; i < treeNums.size(); i++)
    {   
        if (!(tree->add(treeNums[i])))
        {
            std::cout << "Value(s) not entered correctly\n\n";
            break;
        }
    }

    // traverse and display
    tree->inorderTraverse(visit);
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
void RNG(std::vector<int>& treeNums)
{   
    int uValues = 200;

    //RNG
    unsigned seed = time(0);
    srand(seed);

    for (int i = 1; i < uValues; i++)
    {
        treeNums.push_back(i);
        //std::cout << treeNums[i] << std::endl;
    }

    std::shuffle(treeNums.begin(), treeNums.end(), std::default_random_engine(rand())); 

    for (int i = 0; i < 100; i++)
    {
        treeNums.erase(treeNums.begin() + i);
    }

    // for (int i = 0; i < treeNums.size(); i++)
        // std::cout << treeNums[i] << std::endl;
        
    
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
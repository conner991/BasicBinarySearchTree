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

#include <fstream>

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])

// #pragma warning(disable : 4996)

// Prototypes
void RNG(std::vector<int>& treeNums);
void visit(int &num, std::fstream& fileOut);
void visitForFile(int &num, std::fstream& fileOut);
void f_out(std::shared_ptr<BinarySearchTree<int>> tree, std::fstream& fileOut);
/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
int main()
{
    
    std::fstream fileOut;
    fileOut.open("TraversalResults.txt", std::ios::out);

    std::vector<int> treeNums;

    
    // Generate random numbers, insert into a vector
    RNG(treeNums);
    
    
    // Insert numbers into a BST
    std::shared_ptr<BinarySearchTree<int>> tree = std::make_shared<BinarySearchTree<int>>();

    for (int i = 0; i < treeNums.size(); i++)
    {   
        if (!(tree->add(treeNums[i])))
        {
            std::cout << "Value(s) not entered correctly\n\n";
            break;
        }
    }

    // traverse and display with Height
    std::cout << "\nHere are the three different tree traverasl outputs:\n\n";
    fileOut << "\nHere are the three different tree traverasl outputs:\n\n";
    std::cout << "Pre-Order:\n";
    fileOut << "Pre-Order:\n";
    tree->preorderTraverse(visit, fileOut);
    std::cout << "\nIn-Order:\n";
    fileOut << "\nIn-Order:\n";
    tree->inorderTraverse(visit, fileOut);
    std::cout << "\nPost-Order:\n";
    fileOut << "\nPost-Order:\n";
    tree->postorderTraverse(visit, fileOut);
    std::cout << "\nThe tree height is: " << tree->getHeight() << std::endl << std::endl;
    fileOut << "\nThe tree height is: " << tree->getHeight() << std::endl << std::endl;



    // Close the file
    fileOut.close();

    
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

    for (int i = 0; i < 99; i++)
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
void visit(int &num, std::fstream& fileOut)
{
    std::cout << num << std::endl;
    fileOut << num << std::endl;

}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
-------------------------------------------------------------------------------*/
void visitForFile(int &num, std::fstream& fileOut)
{
    fileOut << num << std::endl;
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- 
void f_out(std::shared_ptr<BinarySearchTree<int>> tree, std::fstream& fileOut)
{

    // traverse and write out with Height
    fileOut << "\nHere are the three different tree traverasl outputs:\n\n";
    fileOut << "Pre-Order:\n";
    tree->preorderTraverse(visit);
    fileOut << "\nIn-Order:\n";
    tree->inorderTraverse(visit);
    fileOut << "\nPost-Order:\n";
    tree->postorderTraverse(visit);
    fileOut << "\nTree Height: " << tree->getHeight() << std::endl << std::endl;

}*/


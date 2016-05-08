/*! \file */ 
/*! \brief main.cpp.
 *
 *  Starts the program.
*/
#include <iostream>
#include "Tree.h"

using namespace std;

/********************************************//**
* Main
***********************************************/
int main( int argc, char const *argv[] )
{
     try
     {
        Tree<int> tree;
        tree.insert(12);
        tree.insert(6);
        tree.insert(17);
        /*tree.insert(38);
        tree.insert(5);
        tree.insert(46);
        tree.insert(2);
        tree.insert(8);
        tree.insert(50);
        tree.insert(4);*/
        tree.insert(10);
        tree.insert(14);
        tree.insert(3);
        tree.insert(15);
        tree.insert(18);
        tree.insert(7);
        tree.insert(20);
        tree.insert(1);
        tree.print();

        for ( int i = 0; i < 5; i++ )
        {
            std::cout << std::endl << "Elemento na posicao " << i << ": " << tree.nthElement(tree.root, i)->data << std::endl;
        }

        std::cout << std::endl << "Elemento mediano: " << tree.findMedian(tree.root) << std::endl;
        std::cout << std::endl << "Elemento raiz: " << tree.root->data << std::endl;
        std::cout << std::endl << "Total elementos: " << tree.getNodeCount() << std::endl;
    }
    catch ( std::exception const &e )
    { 
        //std::cerr << e.what << "\n";
    }

    /*! Main return */
    return 0;
}
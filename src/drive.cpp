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
        tree.insert(17);
        tree.insert(12);
        tree.insert(6);
        tree.insert(10);
        tree.insert(14);
        tree.insert(3);
        tree.insert(15);
        tree.insert(17);
        tree.insert(18);
        tree.insert(7);
        tree.insert(20);
        tree.insert(12);
        tree.insert(1);
        tree.insert(15);
        tree.print();

        for ( int i = 0; i < 10; i++ )
        {
            std::cout << std::endl << "Elemento na posicao " << i << ": " << tree.nthElement(tree.getRoot(), i) << std::endl;
        }

        std::cout << std::endl << "Elemento mediano: " << tree.findMedian(tree.getRoot()) << std::endl;
        std::cout << std::endl << "Elemento raiz: " << tree.getRootData() << std::endl;
        std::cout << std::endl << "Total elementos: " << tree.getNodeCount() << std::endl;
        std::cout << std::endl << "Altura: " << tree.treeHeight(tree.getRoot()) << std::endl;

        std::cout << std::endl << "Posicao node 18: " << tree.position(tree.getRoot(), 18) << std::endl;
        std::cout << std::endl << "Posicao node 10: " << tree.position(tree.getRoot(), 10) << std::endl;
        std::cout << std::endl << "Posicao node 7: " << tree.position(tree.getRoot(), 7) << std::endl;
        std::cout << std::endl << "Posicao node 3: " << tree.position(tree.getRoot(), 3) << std::endl;
        std::cout << std::endl << "Posicao node 17: " << tree.position(tree.getRoot(), 17) << std::endl;
        std::cout << std::endl << "Posicao node 12: " << tree.position(tree.getRoot(), 12) << std::endl;
        std::cout << std::endl << "Posicao node 6: " << tree.position(tree.getRoot(), 6) << std::endl;
        std::cout << std::endl << "Posicao node 20: " << tree.position(tree.getRoot(), 20) << std::endl;
        std::cout << std::endl << "Posicao node 15: " << tree.position(tree.getRoot(), 15) << std::endl;
        std::cout << std::endl << "Posicao node 100: " << tree.position(tree.getRoot(), 100) << std::endl;

        std::cout << std::endl << "Eh completa: " << tree.isComplete(tree.getRoot()) << std::endl;
    }
    catch ( std::exception const &e )
    { 
        //std::cerr << e.what << "\n";
    }

    /*! Main return */
    return 0;
}
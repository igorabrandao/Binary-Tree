/*! \file */ 
/*! \brief main.cpp.
 *
 *  Starts the program.
*/
#include <iostream>
#include <sstream>
#include <string>
#include "Tree.h"

using namespace std;

bool fileExist( const std::string& name )
{
    if ( FILE *file = fopen(name.c_str(), "r") )
    {
        fclose(file);
        return true;
    } 
    else 
    {
        return false;
    }   
}

/********************************************//**
* Main
***********************************************/
int main( int argc, char const *argv[] )
{
     try
     {
        //! Tree instance
        Tree<int> tree;
        string input = "";

        //! Check the value of argc. If not enough parameters have been passed, inform user and exit.
        if ( argc < 2 )
        { 
            //! Generate a tree from default file
            std::cout << std::endl << "<<< Using default input file..." << std::endl;
            tree.createTreeFile("assets/data/input.txt");
            tree.print();
        }
        //! Correct parameters
        else 
        {
            //! Generate a tree from default file
            std::stringstream input;
            input << "assets/data/" << argv[1];

            std::cout << "<< Using " << argv[1] << " input file..." << std::endl;

            if ( fileExist(input.str()) == true )
            {
                tree.createTreeFile(input.str());
                tree.print();
            }
            else
            {
                std::cout << std::endl << "<<< File does not exist" << std::endl << std::endl;
                exit(0);
            }
        }

        do
        {
            /*! Check if all arguments was passed */
            cout << "<<< Inform the command filename (q to quit): ";
            cin >> input;

            std::stringstream filename;
            filename << "assets/data/" << input;

            //! The command file needs to exist
            if ( input.compare("") != 0 && fileExist(filename.str()) == true )
            {
                //! Call the file command parsing
                tree.parseCommandFile(filename.str());
            }
        }
        while ( input.compare("q") != 0 );

        for ( int i = 0; i < 5; i++ )
        {
            std::cout << std::endl << "Elemento na posicao " << i << ": " << tree.nthElement(tree.getRoot(), i) << std::endl;
        }

        std::cout << std::endl << "Elemento mediano: " << tree.findMedian(tree.getRoot()) << std::endl;
        std::cout << std::endl << "Elemento raiz: " << tree.getRootData() << std::endl;
        std::cout << std::endl << "Total elementos: " << tree.getNodeCount() << std::endl;
        std::cout << std::endl << "Altura: " << tree.treeHeight(tree.getRoot()) << std::endl;

        std::cout << std::endl << "Posicao node 18: " << tree.position(tree.getRoot(), 18, 0) << std::endl;
        std::cout << std::endl << "Posicao node 10: " << tree.position(tree.getRoot(), 10, 0) << std::endl;
        std::cout << std::endl << "Posicao node 7: " << tree.position(tree.getRoot(), 7, 0) << std::endl;
        std::cout << std::endl << "Posicao node 3: " << tree.position(tree.getRoot(), 3, 0) << std::endl;
        std::cout << std::endl << "Posicao node 17: " << tree.position(tree.getRoot(), 17, 0) << std::endl;
        std::cout << std::endl << "Posicao node 12: " << tree.position(tree.getRoot(), 12, 0) << std::endl;
        std::cout << std::endl << "Posicao node 6: " << tree.position(tree.getRoot(), 6, 0) << std::endl;
        std::cout << std::endl << "Posicao node 20: " << tree.position(tree.getRoot(), 20, 0) << std::endl;
        std::cout << std::endl << "Posicao node 15: " << tree.position(tree.getRoot(), 15, 0) << std::endl;
        std::cout << std::endl << "Posicao node 100: " << tree.position(tree.getRoot(), 100, 0) << std::endl;

        std::cout << std::endl << "Eh completa: " << tree.isComplete(tree.getRoot()) << std::endl;
        std::cout << std::endl << "Eh cheia: " << tree.isFull() << std::endl;

    }
    catch ( std::exception const &e )
    { 
        //std::cerr << e.what << "\n";
    }

    /*! Main return */
    return 0;
}
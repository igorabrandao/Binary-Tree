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
        tree.insert(14);
        tree.insert(12);
        tree.insert(6);
        tree.insert(17);
        tree.insert(8);
        tree.print();
    }
    catch ( std::exception const &e )
    { 
        //std::cerr << e.what << "\n";
    }

    /*! Main return */
    return 0;
}
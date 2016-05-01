/*!
    <PRE>
    SOURCE FILE : Tree.h
    DESCRIPTION.: Tree class - with implementation.
    AUTHORS.....: Igor A. Brandão and José Carlos Emídio
    CONTRIBUTORS: Igor A. Brandão and José Carlos Emídio
    LOCATION....: IMD/UFRN.
    SATARTED ON.: APR/2016
    CHANGES.....: Structure and functions implemented.

    TO COMPILE..: Use makefile.
    OBS.........: Part of the EDB2 Project.

    LAST UPDATE.: April 30th, 2016.
    </PRE>
*/

#ifndef Tree_H_
#define Tree_H_

#include <iostream>
#include <stdexcept>

// ******************PUBLIC OPERATIONS*********************
// void push( x )       --> Insert x
// T pop( )             --> Remove and return most recently inserted item
// T top( )             --> Return most recently inserted item
// bool isEmpty( )      --> Return true if empty; else false
// bool isFull( )       --> Return true if full; else false
// void makeEmpty( )    --> Remove all items
// void print( )        --> Print the Stack elements

// ***********************ERRORS****************************
// std::bad_alloc thrown if needed.

/*! Tree class */
template <class T>
class Tree
{
    // Internal class which stores only Node related information.
    struct TreeNode
    {
        T data;
        TreeNode * left;
        TreeNode * right;

        TreeNode(T val):data(val),left(NULL),right(NULL)
        {
        }
    };

    TreeNode * root;    //!< Tree root instance
    void print( TreeNode* ) const;
    void freeMemory( TreeNode* );

    /*!
     * Public section
    */
    public:

        /*! Basic members */
        Tree();     //!< Constructor
        ~Tree();    //!< Destructor

        void insert( T );
        void print();
};

#include "Tree.inl"
#endif

/* --------------------- [ End of the Tree.h header ] ------------------- */
/* ========================================================================= */
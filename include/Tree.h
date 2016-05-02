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
    LAST UPDATE.: May 1st, 2016.
    </PRE>
*/

#ifndef Tree_H_
#define Tree_H_

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

// ******************PUBLIC OPERATIONS*********************
// void insert( T )                 --> Insert a Node T
// void print()                     --> Print the entire tree
// int countNodes( TreeNode* )      --> Count the Nodes in the tree
// T nthElement( TreeNode*, int )   --> Return the nth element
// T findMedian( TreeNode* )        --> Return the element in the median
// int position( TreeNode* )        --> Return a Node's position
// bool isFull()                    --> Check if the Tree is full
// bool isComplete()                --> Check if the Tree is Complete
// string toString()                --> Return the Tree as string

// ***********************ERRORS****************************
// std::bad_alloc thrown if needed.

/*! Tree class */
template <class T>
class Tree
{
    //! Internal class which stores only Node related information.
    struct TreeNode
    {
        T data;             //!< Node information

        int leftCount;      //!< Node's left child count
        int rightCount;     //!< Node's right child count
        int nodeCount;      //!< Node's total child count

        TreeNode * left;    //!< Node's left child
        TreeNode * right;   //!< Node's right child

        TreeNode(T val):data(val),left(NULL),right(NULL)
        {
            /*! empty */
        }
    };

    T median;           //!< Object to receive the median
    int index;          //!< Index to support the median function
    int totalNode;      //!< Total of Nodes (including the root)
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

        /*! Custom functions */
        int countNodes( TreeNode* ) const;
        T nthElement( TreeNode*, int ) const;
        T findMedian( TreeNode* ) const;
        int position( TreeNode* ) const;
        bool isFull() const;
        bool isComplete() const;
        string toString() const;
};

#include "Tree.inl"
#endif // TREE_H

/* --------------------- [ End of the Tree.h header ] ------------------- */
/* ========================================================================= */
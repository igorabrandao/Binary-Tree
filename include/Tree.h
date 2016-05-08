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
    LAST UPDATE.: May 4th, 2016.
    </PRE>
*/

#ifndef Tree_H_
#define Tree_H_

#include <iostream>
#include <string>
#include <stdexcept>
#include <cassert>

using namespace std;

// ******************PUBLIC OPERATIONS*********************
// void insert( T )                         --> Insert a Node T
// void print()                             --> Print the entire tree
// int countNodes( TreeNode* )              --> Count the Nodes in the tree
// TreeNode* nthElement( TreeNode*, int )   --> Return the nth element
// T findMedian( TreeNode* )                --> Return the element in the median
// int position( TreeNode* )                --> Return a Node's position
// bool isFull()                            --> Check if the Tree is full
// bool isComplete()                        --> Check if the Tree is Complete
// string toString()                        --> Return the Tree as string

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

        TreeNode * left;    //!< Node's left child
        TreeNode * right;   //!< Node's right child

        TreeNode(T val):data(val),left(NULL),right(NULL),leftCount(0),rightCount(0)
        {
            /*! empty */
        }
    };

    int index;          //!< Index to support the median function
    int treeHeight;     //!< Tree's height
    int nodeCount;      //!< Node's total child count

    void print( TreeNode* ) const;
    void freeMemory( TreeNode* );

    /*!
     * Public section
    */
    public:

        /*! Basic members */
        TreeNode * root;    //!< Tree root instance
        Tree();             //!< Constructor
        ~Tree();            //!< Destructor

        void insert( T );
        void print();

        /*! Custom functions */
        int countNodes( TreeNode* );

        const TreeNode* nthElement( TreeNode*, int );
        T findMedian( TreeNode* );
        int position( TreeNode* );
        bool isFull();
        bool isComplete();
        string toString();

        /*! Get's and set's */
        void setIndex( int index_ ) { this->index = index_; }
        int getIndex() { return this->index; }

        void setHeight( int height_ ) { this->treeHeight = height_; }
        int getHeight() { return this->treeHeight; }

        void setNodeCount( int count_ ) { this->nodeCount = count_; }
        int getNodeCount() { return this->nodeCount; }
};

#include "Tree.inl"
#endif // TREE_H

/* --------------------- [ End of the Tree.h header ] ------------------- */
/* ========================================================================= */
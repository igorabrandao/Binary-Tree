/*! \file */ 
/*! \brief Tree.cpp.
 *
 *  Implements the functions from Tree class.
*/

#include <queue>
#include <utility>  //! std::pair
#include "Tree.h"

/*!
 * Class constructor
 * Initialize the root as nullptr
 *
 * @return => void
*/
template <typename T>
Tree<T>::Tree():root( nullptr )
{
	//! Initialize some attributes
    this->index = 0;
}

/*!
 * Class destructor
 * Free the memory using the Tree root as a parameter 
 *
 * @return => void
*/
template <typename T>
Tree<T>::~Tree()
{
    freeMemory( root );
}

/*!
 * freeMemory function
 * Free the memory used by the Tree
 *
 * @param *node => pointer to a specific node
 *
 * @return => void
*/
template <typename T>
void Tree<T>::freeMemory( Tree::TreeNode *node )
{
	//! Check if the parameter Node is nullptr
    if ( node == nullptr )
        return;

    //! Recursive calling to the children (cascade)
	freeMemory( node->left ); 
	freeMemory( node->right );

    // Delete the node itself
    delete node;
}

/*!
 * insert function
 * Insert a new Node into the tree
 *
 * @param val => new Node's value
 *
 * @return => void
*/
template <typename T>
void Tree<T>::insert( T val )
{
	//! Create an instance of the new Node
    TreeNode *treeNode = new TreeNode(val);

    //! Auxiliaries pointer to help connecting the new Node
    TreeNode *temp = nullptr;
    TreeNode *prev = nullptr;

    //! From now, the temp Node represents the root
    temp = root;

    //! While the temp Node is a valid one, keep running
    while( temp )
    {
    	//! Prev receives the parent Node
        prev = temp;

        //! Check where the new Node would suit
        if ( temp->data < treeNode->data )
            temp = temp->right;
        else
            temp = temp->left;
    }

    //! It's time to reconnect the pointers
    if ( prev == nullptr )
    {
    	/*! If it happens, means that the new Node is smaller than the root,
    	 * or that the Tree may not be initialized
    	*/
        root = treeNode;
    }
    else
    {
    	/*! At this point we identified the parent Node to the new one.
    	 *  Now, we just need to check if the new Node is lower or greater
    	 *  than it's parent.
    	*/
        if ( prev->data < treeNode->data )
            prev->right = treeNode;  	//!< Greater (right)
        else
            prev->left = treeNode;		//!< Lower (left)
    }
}

/*!
 * print function
 * Print the Tree structure recursively
 *
 * @param *node => Tree's node pointer
 *
 * @return => void
*/
template <typename T>
void Tree<T>::print( TreeNode *node ) const
{
	//! Check if the Tree was initialized
    if ( node == nullptr )
        return ;

    int level = 0;

    // Use a queue for breadth-first traversal of the tree.  The pair is
    // to keep track of the depth of each node.  (Depth of root node is 1.)
    typedef std::pair<TreeNode*, int> node_level;

    std::queue<node_level> q;
    q.push(node_level(node, 1));

    while (!q.empty()) 
    {
        node_level nl = q.front();
        q.pop();
        if ( nullptr != (node = nl.first) )
        {
            if (level != nl.second)
            {
                std::cout << std::endl << std::endl << " Level " << nl.second << ": ";
                level = nl.second;
            }
            std::cout << node->data << ' ';
            q.push(node_level(node->left,  1 + level));
            q.push(node_level(node->right, 1 + level));
        }
    }
    std::cout << std::endl << std::endl;
}

/*!
 * print function override
 * Triggers the print function, passing the Tree's
 * root as a paramenter.
 *
 * @return => void
*/
template <typename T>
void Tree<T>::print()
{
    print( root );
}

/*!
 * countNodes function
 * Count the total Nodes inside the Tree
 *
 * @param *node => Tree's node pointer
 *
 * @return => int
*/
template <typename T>
int Tree<T>::countNodes( TreeNode *node ) const
{
    //! Check if the Tree was initialized
    if ( node == nullptr )
        return 0;

    //! Return the total Nodes recursively
    return ( countNodes(node->left) + countNodes(node->right) + 1 );
}

/*!
 * nthElement function
 * Returns the nth element (counting from 1) through ABB ordered path
 *
 * Using a total count field to each node, it's more efficient to find
 * the nth element (in logarithmic time).
 *
 * @param *node => Tree's node pointer
 * @param n_    => element's searched position
 *
 * @return => template
*/
template <typename T>
T Tree<T>::nthElement( TreeNode *node, int n_ ) const
{
    //! Check if the parameter n is inside the Tree scope
    assert( n_ >= 0 && n_ < node->nodeCount );

    if ( node->left != nullptr )
    {
        if ( n_ < node->left->nodeCount )
        {
            return node->left->nthElement( n_ );
        }

        n_ -= node->left->total;
    }

    if ( n_ == 0 )
        return this;

    assert( node->right != nullptr );
    return node->right->nthElement(n_ - 1);
}

/*!
 * median function
 * Returns the element cointained in the Tree's median.
 * If the Tree is even, returns the lowest median element.
 *
 * @param *node => Tree's node pointer
 *
 * @return => template
*/
template <typename T>
T Tree<T>::findMedian( TreeNode *node ) const
{
    //! Check if the Tree was initialized
    if ( node == nullptr )
        return nullptr;

    //! Recursive call with the left child
    median = findMedian( node->left );

    //! Return the median element if it was found
    if ( median != nullptr )
        return median;

    //! Check if the tested element is the median
    if ( this->index == (this.totalNode / 2) )
        return node;

    //! Increase the global index
    this->index += 1;

    //! Recursive call with the right child
    return findMedian( node->right );
}

/*!
 * position function
 * Returns the provided element position in a Tree's simetric ordered path.
 *
 * @param *node => Tree's node pointer
 *
 * @return => int
*/
template <typename T>
int Tree<T>::position( TreeNode *node ) const
{
    /*! empty */
    return 0;
}

/*!
 * isFull function
 * Returns true if the Tree is a Full Binary and false otherwise.
 *
 * @return => bool
*/
template <typename T>
bool Tree<T>::isFull() const
{
    /*! empty */
    return false;
}

/*!
 * isComplete function
 * Returns true if the Tree is a Complete Binary and false otherwise.
 *
 * @return => bool
*/
template <typename T>
bool Tree<T>::isComplete() const
{
    /*! empty */
    return false;
}

/*!
 * toString function
 * Returns a string containing the Tree's view sequence by level.
 *
 * @return => string
*/
template <typename T>
string Tree<T>::toString() const
{
    /*! empty */
    return "";
}
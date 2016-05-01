/*! \file */ 
/*! \brief Tree.cpp.
 *
 *  Implements the functions from Tree class.
*/

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
	/*! empty */
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
 * @param root => Tree's root
 *
 * @return => void
*/
template <typename T>
void Tree<T>::print( TreeNode *root ) const
{
	//! Check if the Tree was initialized
    if ( root == nullptr )
        return ;

    // Recursively callings (first left and then right)
    print(root->left);
    std::cout << root->data << std::endl;
    print(root->right);
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
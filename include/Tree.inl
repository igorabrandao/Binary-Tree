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
    this->nodeCount = 1;
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
    TreeNode *node = new TreeNode(val);

    //! Auxiliaries pointer to help connecting the new Node
    TreeNode *parentNode = nullptr;
    TreeNode *childNode = nullptr;

    //! From now, the parentNode Node represents the root
    parentNode = root;

    //! While the parentNode Node is a valid one, keep running
    while ( parentNode )
    {
    	//! childNode receives the parent Node
        childNode = parentNode;

        //! Check where the new Node would suit
        if ( parentNode->data < node->data )
        {
            parentNode = parentNode->right;
            childNode->rightCount += 1;      //!< Sum up the right counter
        }
        else if ( parentNode->data > node->data )
        {
            parentNode = parentNode->left;
            childNode->leftCount += 1;      //!< Sum up the left counter
        }
        else
        {
            //! Ignore duplicated elements
            return;
        }
    }

    //! It's time to reconnect the pointers
    if ( childNode == nullptr )
    {
    	/*! If it happens, means that the new Node is smaller than the root,
    	 * or that the Tree may not be initialized
    	*/
        root = node;
    }
    else
    {
    	/*! At this point we identified the parent Node to the new one.
    	 *  Now, we just need to check if the new Node is lower or greater
    	 *  than it's parent.
    	*/
        if ( childNode->data < node->data )
            childNode->right = node;  	//!< Greater (right)
        else
            childNode->left = node;		//!< Lower (left)
    }

    //! Update the node counter
    this->nodeCount = countNodes( this->root );
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

    /*! Use a queue for breadth-first traversal of the tree. The pair is
    to keep track of the depth of each node. (Depth of root node is 1.) */
    typedef std::pair<TreeNode*, int> node_level;

    std::queue<node_level> q;
    q.push(node_level(node, 1));

    while ( !q.empty() )
    {
        node_level nl = q.front();
        q.pop();

        if ( nullptr != (node = nl.first) )
        {
            if ( level != nl.second )
            {
                std::cout << std::endl << std::endl << " Nível " << nl.second << ": ";
                level = nl.second;
            }

            std::cout << node->data << ' ';
            q.push( node_level(node->left,  1 + level) );
            q.push( node_level(node->right, 1 + level) );
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
 * treeHeight function
 * Count the total tree's levels
 *
 * @param *node => Pointer to Tree's node root
 *
 * @return => int
*/
template <typename T>
int Tree<T>::treeHeight( TreeNode *node_ )
{
    //! Check if the Tree was initialized
    if ( node_ == nullptr )
        return 0;

    //! Return the total Nodes recursively
    if ( node_->leftCount > node_->rightCount )
        return ( treeHeight(node_->left) + 1 );
    else
        return ( treeHeight(node_->right) + 1 );
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
int Tree<T>::countNodes( TreeNode *node_ )
{
    //! Check if the Tree was initialized
    if ( node_ == nullptr )
        return 0;

    //! Return the total Nodes recursively
    return ( countNodes(node_->left) + countNodes(node_->right) + 1 );
}

/*!
 * nthElement function
 * Returns the nth element (counting from 1) through ABB ordered path
 *
 * Using a total count field to each node, it's more efficient to find
 * the nth element (in logarithmic time).
 *
 * @param n_    => element's searched position
 *
 * @return => template
*/
template <typename T>
T Tree<T>::nthElement( typename Tree<T>::TreeNode *node, int n_ )
{
    assert( n_ >= 0 && n_ < this->nodeCount );

    if ( node == nullptr )
        return NULL;

    if ( n_ == 0 )
        return node->data;
    else if ( n_ > this->nodeCount )
        return nthElement( node->right, n_ - this->nodeCount );
    else
        return nthElement( node->left, n_ - 1 );
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
T Tree<T>::findMedian( TreeNode *node )
{
    //! Check if the Tree was initialized
    if ( node == nullptr )
        return 0;

    //! Recursive call with the left child
    T median = findMedian( node->left );

    //! Return the median element if it was found
    if ( median != 0 )
        return median;

    //! Check if the tested element is the median
    if ( this->index == (this->nodeCount / 2) )
        return node->data;

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
int Tree<T>::position( TreeNode *node, T nodeToFind, int index_ )
{
    // Base Cases: root is null or key is present at root
    if ( node == nullptr || node->data == nodeToFind )
       return index_;

    // Key is greater than root's key
    if ( node->data < nodeToFind )
       return position(node->right, nodeToFind, (index_ + 1));
 
    // Key is smaller than root's key
    return position(node->left, nodeToFind, (index_ + 1));
}

/*!
 * isFull function
 * Returns true if the Tree is a Full Binary and false otherwise.
 *
 * @return => bool
*/
template <typename T>
bool Tree<T>::isFull()
{
    if ( this->root == nullptr )
        return 0;
    else if ( this->nodeCount == ( pow( 2, treeHeight(this->root)) - 1) )
        return true;
    else
        return false;
}

/*!
 * isComplete function
 * Returns true if the Tree is a Complete Binary and false otherwise.
 *
 * @return => bool
*/
template <typename T>
bool Tree<T>::isComplete( TreeNode *node_ )
{
    //! Check if the Tree was initialized
    if ( node_ == nullptr )
        return true;

    //! Get the height's from left and right child
    node_->leftCount = treeHeight( node_->left );
    node_->rightCount = treeHeight( node_->right );

    return( node_->leftCount == node_->rightCount && isComplete(node_->left) && isComplete(node_->right) );
}

/*!
 * toString function
 * Returns a string containing the Tree's view sequence by level.
 *
 * @return => string
*/
template <typename T>
string Tree<T>::toString()
{
    /*! empty */
    return "";
}

/*!
 * createTreeFile function
 * Generate a new tree from a file
 *
 * @return => void
*/
template <typename T>
void Tree<T>::createTreeFile( string filename_ )
{
    std::string line;
    std::ifstream openfile(filename_);

    //! Read an entire line from file
    while ( std::getline(openfile, line) )  // this does the checking!
    {
        std::istringstream iss(line);
        int node_value;

        std::cout << std::endl << "<<< Generating the tree... " << std::endl;

        //! Read each element
        while ( iss >> node_value )
        {
            // Generate the tree
            this->insert(node_value);
        }
    }
}

/*!
 * executeCommandFile function
 * Execute a command batch from a file
 *
 * @return => void
*/
template <typename T>
void Tree<T>::parseCommandFile( string filename_)
{
    ifstream openfile(filename_);
    string command;
    int parameter;

    if( !openfile )
        cerr << "<<< Cant open the file " << endl;

    while ( (openfile >> command >> parameter) || (openfile >> command) )
    {
        cout << command << " - " << parameter << endl;
    }

    openfile.close();
}
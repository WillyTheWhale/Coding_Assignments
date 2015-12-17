///***********************************************************************************

/// Title: Tree Class Header

/// Description: This is the declaration of a Tree class, and it's functions as 

/// specified by the PC20 UML

/// Author: Willy Ma

/// COMSC 165 Section 8326

/// Date: December 10, 2015

/// Status : Complete

/// 

/// 

///***********************************************************************************
#ifndef TREE_H
#define TREE_H

#include <iostream>

class Tree
{
private:
	struct Node
	{
		char c;
		Node *left;
		Node *right;
	};

	Node *root;

	void	insert( Node *& , Node * );
	int 	seek( Node *& , char );
	void	destroy( Node *& );
	void	clear( Node *& );
	void	print( Node * ) 		const;
	int 	count( Node * ) 		const;
	void	printLeaves( Node * )	const;


public:
			Tree();
			~Tree();
	int 	insert( char );
	int 	remove( char );
	void 	clear();
	bool	search( char )	const;
	void	print()		const;
	int 	count()		const;
	void	printLeaves()	const;
	bool	isFull()	const;
	bool	isEmpty()	const;

};

Tree::Tree()
{
	root = NULL;
}

Tree::~Tree()
{
	clear();
}



int Tree::insert( char c )
{
	if ( isFull() ) // Can we allocate memory to a new node?
	{
		return -1;
	}

	/*else if( search( c ) )	// Does a node with that char already exist?
	{
		return -1;
	}*/ // This actually doesn't affect the binary tree system.

	else								
	{									
		Node *newLeafNode = new Node;	// Then we allocate memory for a new
										// Node.
		newLeafNode->c = c;				// It is a leaf because we initialize
		newLeafNode->left = NULL;		// it to have no children.
		newLeafNode->right = NULL;		

		insert( root , newLeafNode );	// Insert the new leaf node.

		return 0;
	}

}

void Tree::insert( Node *&r , Node *n )
{
	if ( r == NULL )	// Check to see if this is pointer is not pointing to
	{					// a node... If so, we've found the spot.
		r = n;			// Have the pointer point to the new Node's adreess
	}

	else if ( ( n->c ) < ( r->c )  ) // If new node's c is less than the current
	{								// pointer's c, then the spot is to the
		insert( r->left , n );		// left of current pointer. So we check if
									// we can insert into the address held by
	}								// left.

	else 
	{							// If we haven't found the spot.. and the spot
		insert( r->right, n );	// isn't in the left of the current pointer...
	}							// then it must be in the right of current
								// pointer. We then see if we can insert n's
								// address into the address held by the right.
}



int Tree::remove( char c )
{
	if ( isEmpty() )	// You can't remove any node's from a nodeless tree.
	{
		return -1;
	}
	
	else	// Proceed only if the tree contains nodes.
	{
		int result;
		result = seek( root , c );	// Seek returns 0 on success, -1 on fail.

		return result;
	}
}

int Tree::seek( Node *&r , char c )
{
	if ( r == NULL )
	{
		return -1;
	}

	else if ( c < ( r->c ) )
	{
		seek( r->left , c );
	}

	else if ( c > ( r-> c ) )
	{
		seek ( r->right , c );
	}

	else // if c == r->c , then we found the node.
	{
		destroy( r );
		return 0;
	}
}

void Tree::destroy( Node *&r ) 	// We are passed the pointer that holds the
{								// address of the node to destroy, this pointer
								// is also the address held by a left/right
								// pointer of a parent node.

	////////////////////// This is the case where we are passed a node to be 
	//		CASE 1 		// destroyed that only has NO child. It is a leaf.
	////////////////////// 

	if ( ( r->left == NULL ) && ( r->right == NULL ) ) // when right and left
	{												   // don't exist.
		delete r;
		r = NULL;	// Then you dont have to worry about it's children, and you
	}				// can just delete it.


	////////////////////// This is the case where we are passed a node to be 
	//		CASE 2 		// destroyed that only has one child. We check whether
	////////////////////// it is the left or the right child.

	else if ( ( r->left !=NULL ) && ( r->right == NULL ) ) // This is when left
	{												  // exists, right doesnt.
		Node *temp = r->left; // we save the left child
		delete r;			  // delete the data allocated to that node
		r = temp;			  // save the address of the left branch to the
	}						  // pointer r.

	else if ( ( r->left == NULL ) && ( r->right != NULL ) ) // this is when right
	{												   // exists, left doesnt.
		Node *temp = r->right; // we save the right child's address.
		delete r;			   // delete the  data allocated to that node
		r = temp;			   // save the address of the right branch to the
	}						   // pointer r.


	////////////////////// This is the case where we are passed a node to be 
	//					// destroyed that two children. We take the left child
	//		CASE 3		// and put it in an approriate spot in the right child
	//					// and then save the address of the updated right
	////////////////////// branch to the pointer r.

	else
	{
		Node *rightNode = r->right;
		Node *travelerNode = r->right;			// We create a local temporary
												// ptr to traverse the right
		while ( travelerNode->left != NULL )	// branch's left side.
		{
			travelerNode = travelerNode->left; 	// Keep going left until you
		}										// cant.

		travelerNode->left = r->left; 	// We are at the very left of the right
										// side.
										// Store the node's left side's 
										// address inside.
		delete r;			// Destroy the data located at the address held
		r = rightNode;		// by r, which was sent in. Then replace r with
	}						// the address 

}



void Tree::clear()
{
	clear( root );
}

void Tree::clear( Node *&r )
{
	if ( r != NULL )
	{
		if ( r->left != NULL )
		{
			clear( r->left );
		}

		if ( r->right != NULL )
		{
			clear ( r->right );
		}

			delete r;
			r = NULL;

	}

}

bool Tree::search( char c ) const
{
	if ( isEmpty() )
	{
		return false;
	}

	Node *travelerNode = root;
	
	while ( travelerNode != NULL )
	{
		if ( c < ( travelerNode->c ) )
		{
			travelerNode = travelerNode->left;
		}

		else if ( c > ( travelerNode->c ) )
		{
			travelerNode = travelerNode->right;
		}

		else
		{
			return true;
		}

	}

	return false;

}

int Tree::count() const
{
	if ( isEmpty() )
	{
		return 0;
	}

	int total = 0;
	total = count( root );
	return total;
}

int Tree::count( Node *r ) const
{

	if ( r != NULL )
	{
		return ( 1 + count( r->left ) + count ( r->right ) );
	}

	return 0;
}

void Tree::print() const
{
	if ( isEmpty() != true )
	print( root );
}

void Tree::print( Node *r ) const
{
	if ( r->left != NULL )
	{
		print( r->left );
	}

	cout << r->c << " ";

	if ( r->right != NULL )
	{
		print ( r->right );
	}

}

void Tree::printLeaves() const
{
	if ( isEmpty() != true )
	{
		printLeaves( root );
	}
}

void Tree::printLeaves( Node *r ) const
{
	if ( r != NULL )
	{
		if ( ( r->left == NULL ) && ( r->right == NULL ) )
		{
			cout << r->c << " ";
		}

		else
		{
			printLeaves( r->left );		// check left side
			printLeaves( r->right );	// check right side
		}

	}

}

bool Tree::isFull() const
{
	Node *test = new Node;

	if ( test == NULL )
	{
		delete test;
		return true;
	}

	else
	{
		delete test;
		return false;
	}

}

bool Tree::isEmpty() const
{
	if ( root == NULL )
	{
		return true;
	}

	else
	{
		return false;
	}
}
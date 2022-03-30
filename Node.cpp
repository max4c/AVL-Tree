	#include "Node.h"
	
	/*
	* Returns the data that is stored in this node
	*
	* @return the data that is stored in this node.
	*/
	int Node::getData() const
	{	
		return(data);
	}
	int Node::getHeight()
	{
		return(height);
	}
	void Node::setHeight(int newHeight)
	{
		height = newHeight;
	}
	void Node::setData(int newData)
	{
		data = newData;
	}

	/*
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*/
	NodeInterface * Node::getLeftChild() const
	{
		return(leftChild);
	}

	/*
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*/
	NodeInterface * Node::getRightChild() const
	{
		return(rightChild);
	}

	Node *& Node::getRight() 
	{
		return(rightChild);
	}

	Node *& Node::getLeft() 
	{
		return(leftChild);
	}

	void Node::setLeftChild(Node *ptr)
	{
		leftChild = ptr;
	}

	void Node::setRightChild(Node *ptr)
	{
		rightChild = ptr;
	}
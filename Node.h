#pragma once
#include "NodeInterface.h"
#include <cstddef>
using namespace std;

class Node : public NodeInterface {
		friend class AVL; // allows BST to access data members
public:
	Node(int value) {height = 1; data = value;leftChild = NULL; rightChild = NULL;}
	~Node() {}
	int getData() const ;
	int getHeight();
	void setHeight(int newHeight);
	void setData(int newData);
	NodeInterface * getLeftChild() const;
	NodeInterface * getRightChild() const;
	Node *&getRight();
	Node *&getLeft();
	void setLeftChild(Node *ptr);
	void setRightChild(Node *ptr);
protected:
	Node *leftChild;
	Node *rightChild;
	int data;
	int height;

};
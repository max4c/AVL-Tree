#pragma once
#include "AVLInterface.h"
#include "Node.h"
#include <iostream>

class AVL : public AVLInterface {
public:
	AVL() {root = NULL; count = 0;}
	virtual ~AVL() {clear();}
	NodeInterface * getRootNode() const;
	bool add(int data);
	bool remove(int data);
	void clear();
	int get_height(Node *node);
	void update_height(Node *&node);
	void calc_height(Node *&node);
	void rotateLeft(Node *&node);
	void rotateRight(Node *&node);
	int inorderPre(Node *&node);
	void rebalance(Node *&node);
private:
	bool add(int data, Node *&node);
	bool remove(int data, Node *&node);
//	void replace(Node *&oldNode, Node *&node);
	void recursiveClear(Node* node);
protected:
	Node *root;
	int count;


};
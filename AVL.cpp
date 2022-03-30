#include "AVL.h"

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	NodeInterface * AVL::getRootNode() const
	{
		return this->root;
	}

/*
*
*
*
* REBALANCE PART
*
*
*
*/

	void AVL::rebalance(Node *&node)
	{

		if (get_height(node->getRight()) - get_height(node->getLeft()) < -1) // rotate right
			{
				cout << "right heavy"<<endl;
				if (get_height(node->leftChild->getRight()) - get_height(node->leftChild->getLeft()) <= 0){
					cout << "left left tree"<<endl;
					rotateRight(node); 
					}
				else if (get_height(node->leftChild->getRight()) - get_height(node->leftChild->getLeft()) > 0){
					cout <<"left right tree"<<endl;
					rotateLeft(node->leftChild);
					rotateRight(node);
					}
			}
		else if (get_height(node->getRight()) - get_height(node->getLeft()) > 1) // rotate left 
			{
				cout << "left heavy"<<endl;
				if (get_height(node->rightChild->getRight()) - get_height(node->rightChild->getLeft()) >= 0){
					cout <<"right right tree"<<endl;
					rotateLeft(node);
					}
				else if (get_height(node->rightChild->getRight()) - get_height(node->rightChild->getLeft()) < 0){
					cout <<"right left tree"<<endl;
					rotateRight(node->rightChild);
					rotateLeft(node);	
					}
			}
	}
	
	void AVL::rotateLeft(Node *&node)
	{
		Node* temp = node->rightChild;
		node->rightChild = temp->leftChild;
		temp->leftChild = node;
		node = temp;
		update_height(node->leftChild);
		update_height(node);
	}
	
	void AVL::rotateRight(Node *&node)
	{
		Node* temp = node->leftChild;
		node->leftChild = temp->rightChild;
		temp->rightChild = node;
		node = temp;
		update_height(node->rightChild);
		update_height(node);
	}

	/*
	*
	*
	*
	*HEIGHT PART
	*
	*
	*
	*/

	int AVL::get_height(Node *node) {
		if(node == nullptr) {
			return(0);
		} else{
			return node->getHeight();
		}
	}
	void AVL::update_height(Node *&node)
	{
		if (get_height(node->getRight()) >= get_height(node->getLeft()))
			node->setHeight(get_height(node->getRight()) + 1); 
		else if(get_height(node->getRight()) < get_height(node->getLeft()))
			node->setHeight(get_height(node->getLeft()) + 1);
	}
	
	void AVL::calc_height (Node *&node)
	{
		if(node==nullptr) {
			return;
		}

		int max = 0;

		if(get_height(node->getLeft())>max) {
			max = get_height(node->getLeft());
		}
		if(get_height(node->getRight())>max) {
			max = get_height(node->getRight());
		}
		node->setHeight(max+1);
	cout << "calc_height "<<node->getData()<<" = "<<node->getHeight()<<endl;
	}

	/*
	*
	*
	*
	* ADD FUNCTION
	*
	*
	*
	*/

		bool AVL::add(int data)
	{
		return add(data, this->root);

	}

	bool AVL::add(int data, Node *&node){
		if (node == NULL) {
			node = new Node(data);
			return true;
		} 
		else if(node->getData() == data) {
			cout << "duplicate"<<endl;
			
			return false;
		} 
		else if(data < node->getData()) {
				bool rval = add(data, node->getLeft()); //transverse left
				calc_height(node);
				rebalance(node);
				return rval;
		} 
		else {
			bool rval = add(data, node->getRight()); //transverse right
				calc_height(node);
				rebalance(node);
				return rval;
		}		
	}

	/*
	*
	*
	* Remove Function
	*
	* 
	* 
	*/

bool AVL::remove (int data)
{
	return remove(data, this->root);
}

bool AVL::remove(int data, Node *&node) {
	if (node == NULL){ 
		return false;}

	else{
		if(data < node->getData()){
		bool rval =  remove(data, node->getLeft()); // transverse left
				calc_height(node);
				rebalance(node);
				return rval;}
		else if(data > node->getData()){
			bool rval = remove(data, node->getRight()); // transverse right
				calc_height(node);
				rebalance(node);
				return rval;}

		else{ //found

			Node* old_node = node;
			if(node->getLeft() == NULL){
				node = node->getRight();
				delete old_node;
			}
			else if (node->getRight()==NULL){
				node = node->getLeft();
				delete old_node;
			}
			else { //TWO CHILDREN
				old_node->setData(inorderPre(node));
				bool rval = remove(old_node->getData(), node->getLeft());
				calc_height(node);
				rebalance(node);
				return rval;
			}
			return true;
		}	
	}
}

int AVL::inorderPre(Node *&node)
{
	Node * scoutPtr = node->getLeft();
	while(scoutPtr->getRight() != NULL){
			scoutPtr = scoutPtr->getRight();
			}
		return scoutPtr->getData();
}



	/*
	*
	*
	* REMOVE PART
	*
	*
	*/


	void AVL::clear() {
	recursiveClear(this->root);
	this->root = NULL;
	}

	void AVL::recursiveClear(Node* node){
		if(node != NULL){
			recursiveClear(node->getLeft());
			recursiveClear(node->getRight());
			delete node;
		}
	}
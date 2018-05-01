#include "IntBinaryTree.h"

using namespace std;

IntBinaryTree::IntBinaryTree()
{

}


IntBinaryTree::~IntBinaryTree()
{
}

void IntBinaryTree::insertNode(int num) {
	TreeNode *newNode = new TreeNode(num); // pointer to a new node
	insert(root, newNode);
}

void IntBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode) {
	if (newNode != nullptr) {
		if (nodePtr == nullptr) nodePtr = newNode; // insert node 
		// search the left branch for a place to insert the node
		else if (newNode->value < nodePtr->value) insert(nodePtr->left, newNode);
		// search the right branch for a place to insert the node
		else insert(nodePtr->right, newNode);
	}
}

bool IntBinaryTree::searchNode(int num) const {
	TreeNode *nodePtr = root;
	
	while (nodePtr != nullptr) {
		if (nodePtr->value == num) return true;
		else {
			if (num > nodePtr->value) nodePtr = nodePtr->right;
			else nodePtr = nodePtr->left;
		}
	}
	return false;
}

bool IntBinaryTree::remove(int num) {
	return deleteNode(num, root);
}

bool IntBinaryTree::deleteNode(int num, TreeNode *&nodePtr) {
	if (nodePtr == nullptr) return false;
	else if (num == nodePtr->value) {
		TreeNode *tmp = nodePtr;
		nodePtr = nodePtr->right;
		insert(nodePtr, tmp->left);
		delete tmp;
		return true;
	}
	else if (num < nodePtr->value) return deleteNode(num, nodePtr->left);
	else return deleteNode(num, nodePtr->right);
}

bool IntBinaryTree::makeDeletion(TreeNode *&nodePtr) {
	TreeNode *tmp = nullptr;
	if (nodePtr == nullptr) {
		return false;
	}
	else if (nodePtr->right == nullptr) {
		tmp = nodePtr;
		nodePtr = nodePtr->left;
		delete tmp;
	}
	else if (nodePtr->left == nullptr) {
		tmp = nodePtr;
		nodePtr = nodePtr->right;
		delete tmp;
	}
	else {
		tmp = nodePtr->right;
		while (tmp->left) {
			tmp = tmp->left;
		}
		tmp->left = nodePtr->left;
		tmp = nodePtr;
		nodePtr = nodePtr->right;
		delete tmp;
	}
	return false;
}

void IntBinaryTree::displayInOrder(TreeNode *nodePtr) const {
	if (nodePtr) {
		displayInOrder(nodePtr->left);
		cout << nodePtr->value << endl;
		displayInOrder(nodePtr->right);
	}
}

void IntBinaryTree::displayPostOrder(TreeNode *nodePtr) const {
	if (nodePtr) {
		displayPostOrder(nodePtr->left);
		displayPostOrder(nodePtr->right);
		cout << nodePtr->value << endl;
	}
}

void IntBinaryTree::displayPreOrder(TreeNode *nodePtr) const {
	if (nodePtr) {
		cout << nodePtr->value << endl;
		displayPreOrder(nodePtr->left);
		displayPreOrder(nodePtr->right);
	}
}
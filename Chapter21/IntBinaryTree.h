#pragma once
#include <iostream>

using namespace std;

class TreeNode
{
public:
	int value;
	TreeNode *left;
	TreeNode *right;

	// Constructor requiring value
	TreeNode(int val) {
		value = val;
		left = nullptr;
		right = nullptr;
	}
};

class IntBinaryTree
{
private:
	TreeNode *root;

	// Private member functions
	void insertNode(TreeNode*&, TreeNode*&);
	void destroySubTree(TreeNode*&);
	bool deleteNode(int, TreeNode*&);
	int leafCount(TreeNode*) const;
	int height(TreeNode*) const;
	void width(TreeNode*, int, int[], int) const;
	void displayInOrder(TreeNode*) const;
	void displayPreOrder(TreeNode*) const;
	void displayPostOrder(TreeNode*) const;
public:
	// Constructor
	IntBinaryTree();

	// Destructor
	~IntBinaryTree();

	// Binary tree operations
	void insert(int);
	bool searchNode(int) const;
	bool remove(int);
	int width() const;
	int leafCount() const {
		return leafCount(root);
	}
	int height() const {
		return height(root);
	}
	void displayInOrder() const {
		displayInOrder(root);
	}
	void displayPreOrder() const {
		displayPreOrder(root);
	}
	void displayPostOrder() const {
		displayPostOrder(root);
	}
};

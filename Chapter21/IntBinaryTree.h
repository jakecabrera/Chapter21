#include <iostream>

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
	void insert(TreeNode*&, TreeNode*&);
	void destroySubTree(TreeNode*&);
	bool deleteNode(int, TreeNode*&);
	bool makeDeletion(TreeNode*&);
	void displayInOrder(TreeNode*) const;
	void displayPreOrder(TreeNode*) const;
	void displayPostOrder(TreeNode*) const;
public:
	// Constructor
	IntBinaryTree();

	// Destructor
	~IntBinaryTree();

	// Binary tree operations
	void insertNode(int);
	bool searchNode(int) const;
	bool remove(int);
	int leafCount();
	int height();
	int width();
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

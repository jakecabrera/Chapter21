#include "IntBinaryTree.h"

using namespace std;

// constructor
IntBinaryTree::IntBinaryTree()
{
	root = nullptr;
}

// destructor
IntBinaryTree::~IntBinaryTree()
{
	destroySubTree(root);
}

// *********************************************************
// name:		destroySubTree
// called by:	~IntBinaryTree
// passed:		TreeNode*& as where to start destroying
// returns:		nothing
// calls:		destroySubTree
// The destroySubTree takes a node and destroys all the nodes
// below it and itself.
// *********************************************************

void IntBinaryTree::destroySubTree(TreeNode *&nodePtr) {
	if (nodePtr) {
		// destroy the left and right of this node
		destroySubTree(nodePtr->left);
		destroySubTree(nodePtr->right);
		// destroy this node afterwards
		delete nodePtr;
	}
}

// *********************************************************
// name:		insert
// called by:	nobody
// passed:		int as value to insert
// returns:		nothing
// calls:		insertNode
// The insert function takes a value and inserts it into
// its proper place in the tree.
// *********************************************************

void IntBinaryTree::insert(int num) {
	TreeNode *newNode = new TreeNode(num); // pointer to a new node
	insertNode(root, newNode);
}

// *********************************************************
// name:		insertNode
// called by:	insert
// passed:		TreeNode*& nodePtr as node to check for insertion
//				TreeNode*& newNode as new node to insert
// returns:		nothing
// calls:		insertNode
// The insertNode function takes a node and inserts it into
// its proper place in a given tree.
// *********************************************************

void IntBinaryTree::insertNode(TreeNode *&nodePtr, TreeNode *&newNode) {
	if (newNode != nullptr) {
		if (nodePtr == nullptr) nodePtr = newNode; // insert node 
		// search the left branch for a place to insert the node
		else if (newNode->value < nodePtr->value) insertNode(nodePtr->left, newNode);
		// search the right branch for a place to insert the node
		else insertNode(nodePtr->right, newNode);
	}
}

// *********************************************************
// name:		searchNode
// called by:	nobody
// passed:		int as number to search for its existence
// returns:		bool as whether the value is in the tree
// calls:		nobody
// The searchNode function checks if the tree contains the
// specified value.
// *********************************************************

bool IntBinaryTree::searchNode(int num) const {
	TreeNode *nodePtr = root;
	
	while (nodePtr != nullptr) {
		if (nodePtr->value == num) return true; // Match!
		else {
			if (num > nodePtr->value) nodePtr = nodePtr->right; // search the right side
			else nodePtr = nodePtr->left; // search the left side
		}
	}
	return false;
}

// *********************************************************
// name:		remove
// called by:	nobody
// passed:		int as number to remove
// returns:		bool as whether the value was removed
// calls:		deleteNode
// The remove function deletes a node of specified value if
// it exists.
// *********************************************************

bool IntBinaryTree::remove(int num) {
	return deleteNode(num, root);
}

// *********************************************************
// name:		deleteNode
// called by:	remove
// passed:		int as number to remove
// returns:		bool as whether the value was removed
// calls:		deleteNode
// The deleteNode function deletes a given value from a given
// portion of the tree if it exists.
// *********************************************************

bool IntBinaryTree::deleteNode(int num, TreeNode *&nodePtr) {
	if (nodePtr == nullptr) return false; // num doesn't exist in tree
	else if (num == nodePtr->value) { // num found
		// delete node, promote right side in its place and put the left
		// tree at the bottom left of the right side
		TreeNode *tmp = nodePtr;
		nodePtr = nodePtr->right;
		insertNode(nodePtr, tmp->left);
		delete tmp;
		return true;
	}
	else if (num < nodePtr->value) return deleteNode(num, nodePtr->left); // Search left side for num
	else return deleteNode(num, nodePtr->right); // search right side for num
}

// *********************************************************
// name:		leafCount
// called by:	leafCount()
// passed:		TreeNode* as tree to count leaves
// returns:		int as count of leaves in tree
// calls:		leafCount(TreeNode*)
// The leafCount function counts the amount of nodes that
// point to no other node in a tree.
// *********************************************************

int IntBinaryTree::leafCount(TreeNode *nodePtr) const {
	if (nodePtr == nullptr) return 0;
	else if (nodePtr->left == nullptr && nodePtr->right == nullptr) return 1; //node is a leaf
	// Get the count of leafs to the left and right of this node.
	else return leafCount(nodePtr->left) + leafCount(nodePtr->right);
}

// *********************************************************
// name:		height
// called by:	height()
// passed:		TreeNode* as root of where to get height
// returns:		int as number of levels in the tree
// calls:		height(TreeNode*)
// The height function finds the number of levels in a tree.
// *********************************************************

int IntBinaryTree::height(TreeNode *nodePtr) const {
	if (nodePtr == nullptr) return 0;
	else {
		int leftHeight = height(nodePtr->left); // height of the left side
		int rightHeight = height(nodePtr->right); // height of the right side
		// because this node exists, we are adding 1 to the greater of the
		// heights of the left and right side.
		return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
	}
}

// *********************************************************
// name:		width
// called by:	nobody
// passed:		nothing
// returns:		int as count of nodes in widest level
// calls:		width(TreeNode*, int, int)
// The width functions finds the level that contains the 
// most nodes and returns the count of nodes in that level.
// *********************************************************

int IntBinaryTree::width() const {
	int treeHeight = height();
	int *levelWidths = new int[treeHeight]{}; // for holding the count of nodes per level
	width(root, 0, levelWidths, treeHeight); 

	// get the largest width
	int largestWidth = 0;
	for (int i = 0; i < treeHeight; i++) if (levelWidths[i] > largestWidth) largestWidth = levelWidths[i];
	delete levelWidths;

	return largestWidth;
}

// *********************************************************
// name:		width
// called by:	width()
// passed:		TreeNode* as where to start checking width
//				int as current level being checked
//				int[] as array containing running count of 
//					nodes per level.
// returns:		nothing
// calls:		width(TreeNode*, int, int)
// The width function is an overloaded function for
// recursively calling itself to find the width of the tree.
// It takes an int array and fills the array recursively with
// the count of nodes per level.
// *********************************************************

void IntBinaryTree::width(TreeNode *nodePtr, int level, int levelWidths[], int maxLevel) const {
	if (!nodePtr || level >= maxLevel) return;
	
	// the node exists on this level so increment this levels width
	levelWidths[level]++;

	// get the width of the next level, checking both sides
	width(nodePtr->right, level + 1, levelWidths, maxLevel);
	width(nodePtr->left, level + 1, levelWidths, maxLevel);
}

// *********************************************************
// name:		displayInOrder
// called by:	displayInOrder()
// passed:		TreeNode* as tree to display
// returns:		nothing
// calls:		displayInOrder(TreeNode*)
// The displayInOrder function prints all the values less
// than the given node, then itself, then all the ones 
// greater than itself.
// *********************************************************

void IntBinaryTree::displayInOrder(TreeNode *nodePtr) const {
	if (nodePtr) {
		displayInOrder(nodePtr->left);
		cout << nodePtr->value << endl;
		displayInOrder(nodePtr->right);
	}
}

// *********************************************************
// name:		displayPostOrder
// called by:	displayPostOrder()
// passed:		TreeNode* as tree to display
// returns:		nothing
// calls:		displayPostOrder(TreeNode*)
// The displayPostOrder function prints all the values less
// than the given node, then all the ones 
// greater than itself, then itself.
// *********************************************************

void IntBinaryTree::displayPostOrder(TreeNode *nodePtr) const {
	if (nodePtr) {
		displayPostOrder(nodePtr->left);
		displayPostOrder(nodePtr->right);
		cout << nodePtr->value << endl;
	}
}

// *********************************************************
// name:		displayPreOrder
// called by:	displayPreOrder()
// passed:		TreeNode* as tree to display
// returns:		nothing
// calls:		displayPreOrder(TreeNode*)
// The displayPreOrder function prints itself, then all the 
// values less than the given node, then all the ones greater 
// than itself.
// *********************************************************

void IntBinaryTree::displayPreOrder(TreeNode *nodePtr) const {
	if (nodePtr) {
		cout << nodePtr->value << endl;
		displayPreOrder(nodePtr->left);
		displayPreOrder(nodePtr->right);
	}
}
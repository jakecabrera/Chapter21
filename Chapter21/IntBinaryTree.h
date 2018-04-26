
class IntBinaryTreeNode
{
public:
	int value;
	IntBinaryTreeNode *left;
	IntBinaryTreeNode *right;

	// Constructor requiring value
	IntBinaryTreeNode(int val) {
		value = val;
		left = nullptr;
		right = nullptr;
	}
};

class IntBinaryTree
{
private:
	IntBinaryTreeNode *root;
public:
	// Constructor
	IntBinaryTree();

	// Destructor
	~IntBinaryTree();

	// Binary tree operations
	void insert(int);
	bool find(int);
	bool remove(int);
	int leafCount();
	int height();
	int width();
};

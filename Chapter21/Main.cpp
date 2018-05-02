#include "IntBinaryTree.h"

using namespace std;

int main() {
	IntBinaryTree *tree = new IntBinaryTree();
	tree->insert(10);
	tree->insert(87);
	tree->insert(9);
	tree->insert(55);
	tree->insert(13);
	tree->insert(40);
	tree->insert(22);
	tree->insert(1);
	tree->insert(0);
	tree->insert(77);
	tree->insert(0);
	tree->insert(4);
	tree->insert(55);
	tree->insert(33);
	tree->insert(22);

	//tree.remove(22);

	//if (tree.searchNode(0)) tree.displayPreOrder();

	cout << "width: " << tree->width() << endl;
	//tree.width();

	delete tree;


	cin.get();
	return 0;
}

//10, 87, 9, 55, 13, 40, 22,1,0,77, 0, 4, 55, 33, 22
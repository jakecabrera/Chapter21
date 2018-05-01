#include "IntBinaryTree.h"

using namespace std;

int main() {
	IntBinaryTree tree = IntBinaryTree();
	tree.insertNode(10);
	tree.insertNode(87);
	tree.insertNode(9);
	tree.insertNode(55);
	tree.insertNode(13);
	tree.insertNode(40);
	tree.insertNode(22);
	tree.insertNode(1);
	tree.insertNode(0);
	tree.insertNode(77);
	tree.insertNode(0);
	tree.insertNode(4);
	tree.insertNode(55);
	tree.insertNode(33);
	tree.insertNode(22);

	if (tree.searchNode(10)) tree.displayInOrder();

	cin.get();
	return 0;
}

//10, 87, 9, 55, 13, 40, 22,1,0,77, 0, 4, 55, 33, 22
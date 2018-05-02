/*
* Author:	Jake Cabrera
* Date:		05/02/2018
* 
* Chapter 21 programming assignment
* Integer Binary Tree
*/

#include <string>
#include <iostream>
#include <regex>
#include "IntBinaryTree.h"

using namespace std;

// Function prototypes
void displayMenu();
int getMenuOption();
int getInt();
void waitToContinue();
void showErrorMessage(string msg);
void insertIntoTree(IntBinaryTree&);
void displayTree(IntBinaryTree&);
void leafCount(IntBinaryTree&);
void treeHeight(IntBinaryTree&);
void treeWidth(IntBinaryTree&);

int main() {
	bool finished = false;
	int menuOption;
	IntBinaryTree tree;

	do {
		displayMenu();
		menuOption = getMenuOption();

		switch (menuOption)
		{
		case 1:
			insertIntoTree(tree);
			break;
		case 2:
			displayTree(tree);
			break;
		case 3:
			leafCount(tree);
			break;
		case 4:
			treeHeight(tree);
			break;
		case 5:
			treeWidth(tree);
			break;
		case 6:
			finished = true;
			break;
		default:
			cout << "Please select an option that is on the menu..." << endl;
			waitToContinue();
			break;
		}
	} while (!finished);

	cout << "Program is finished. Press [ENTER] to exit..." << endl;

	string str;
	getline(cin, str);
	return 0;
}

// *********************************************************
// name:		displayMenu
// called by:	nobody
// passed:		nothing
// returns:		nothing
// calls:		nobody
// The displayMenu function displays the menu which shows the
// operations that you can perform with the tree
// *********************************************************

void displayMenu() {
	cout << "==============================" << endl;
	cout << "Operations:" << endl;
	cout << "==============================" << endl;
	cout << "1. Insert Into Tree" << endl;
	cout << "2. Display Tree in Order" << endl;
	cout << "3. Leaf Count" << endl;
	cout << "4. Height of Tree" << endl;
	cout << "5. Width of Tree" << endl;
	cout << "6. Exit" << endl;
	cout << "==============================" << endl << endl;
}

// *********************************************************
// name:		getMenuOption
// called by:	nobody
// passed:		nothing
// returns:		int as an option from the menu
// calls:		showErrorMessage
// The getMenuOption function asks for and retrieves a valid
// int from the user and returns it
// *********************************************************

int getMenuOption() {
	string input;
	int option;
	bool validInput = false;

	// keep asking for input until given valid input
	do {
		// get input
		cout << "Enter a menu option by number: ";
		getline(cin, input);

		// Validate input as an integer
		if (regex_match(input, regex("0*[1-6]{1}"))) {
			try
			{
				// Input is verified to be a number 1-8
				option = stoi(input);
				validInput = true;
			}
			catch (const std::exception&)
			{
				showErrorMessage("Something unexpected happened.");
			}
		}

		if (!validInput) showErrorMessage("Input must be an integer 1 through 6.");
	} while (!validInput);

	cout << endl;
	return option;
}

// *********************************************************
// name:		getInt
// called by:	nobody
// passed:		nothing
// returns:		int
// calls:		nothing
// The getInt function asks and retrieves an integer from the
// user.
// *********************************************************

int getInt() {
	string input;
	int x;
	bool validInput = false;

	// Keep asking for valid input until received
	do {
		cout << "Please enter an integer: " << flush;
		getline(cin, input);

		// Validate input as an integer
		if (regex_match(input, regex("\\d+"))) {
			try
			{
				// Input is verified to be just numbers
				// Let's see if it will fit in an int variable
				x = stoi(input);
				validInput = true;
			}
			catch (const std::out_of_range&) {
				showErrorMessage("Input is too large to be an integer.");
			}
			catch (const std::exception&)
			{
				showErrorMessage("Something unexpected happened.");
			}
		}
		else showErrorMessage("Input must be an integer.");
	} while (!validInput);

	cout << endl;
	return x;
}

// *********************************************************
// name:		waitToContinue
// called by:	display
// passed:		nothing
// returns:		nothing
// calls:		nothing
// The waitToContinue function will pause the program until
// the user presses enter.
// *********************************************************

void waitToContinue() {
	string tmp;
	cout << "Press [ENTER] to continue...";
	getline(cin, tmp);
	cout << endl;
}

// *********************************************************
// name:		showErrorMessage
// called by:	getInt, getMenuOption
// passed:		string as reason of error
// returns:		nothing
// calls:		nobody
// The showErrorMessage function prints to console an error
// and it's reason for being there.
// *********************************************************

void showErrorMessage(string msg) {
	cout << "ERROR! " << msg << " Please try again..." << endl << endl;
}

// *********************************************************
// name:		insertIntoTree
// called by:	nobody
// passed:		IntBinaryTree& as tree to insert a value into
// returns:		nothing
// calls:		waitToContinue
// The insertIntoTree function takes a tree and inserts a 
// value into it.
// *********************************************************

void insertIntoTree(IntBinaryTree &tree) {
	cout << "You have chosen to insert a value into the tree." << endl;
	int num = getInt();
	tree.insert(num);
	cout << "Value of [" << num << "] inserted into the tree." << endl << endl;
	waitToContinue();
}

// *********************************************************
// name:		displayTree
// called by:	nobody
// passed:		IntBinaryTree& as tree to display
// returns:		nothing
// calls:		waitToContinue
// The displayTree function takes a tree and prints each of
// its values out in order.
// *********************************************************

void displayTree(IntBinaryTree &tree) {
	cout << "Below is the contents of the tree:" << endl;
	tree.displayInOrder();
	cout << endl;
	waitToContinue();
}

// *********************************************************
// name:		leafCount
// called by:	nobody
// passed:		IntBinaryTree& as tree to count leafs
// returns:		nothing
// calls:		waitToContinue
// The leafCount function takes a tree and prints the count
// of leaf nodes in the tree
// *********************************************************

void leafCount(IntBinaryTree &tree) {
	cout << "You have chosen to get the count of leaves in the tree:" << endl;
	cout << "The tree has [" << tree.leafCount() << "] leaves." << endl << endl;
	waitToContinue();
}

// *********************************************************
// name:		treeHeight
// called by:	nobody
// passed:		IntBinaryTree& as tree to get height of
// returns:		nothing
// calls:		waitToContinue
// The treeHeight function gets the height of the given tree
// *********************************************************

void treeHeight(IntBinaryTree &tree) {
	cout << "You have chosen to get the height of the tree:" << endl;
	cout << "The trees height is [" << tree.height() << "]." << endl << endl;
	waitToContinue();
}

// *********************************************************
// name:		treeWidth
// called by:	nobody
// passed:		IntBinaryTree& as tree to get width of
// returns:		nothing
// calls:		waitToContinue
// The treeWidth function gets the width of the given tree
// *********************************************************

void treeWidth(IntBinaryTree &tree) {
	cout << "You have chosen to get the width of the tree:" << endl;
	cout << "The trees widest level is [" << tree.width() << "] nodes wide." << endl << endl;
	waitToContinue();
}

// 10, 87, 9, 55, 13, 40, 22,1,0,77, 0, 4, 55, 33, 22
#ifndef __BSTREE_H__
#define __BSTREE_H__

#include "Node.h"
#include <string>

using namespace std;

class BSTree {

private:
	Node* root = nullptr;

private:
	void preOrder(Node*) const;
	void inOrder(Node*) const;
	void postOrder(Node*) const;
	bool search(const string&, Node*) const;
	void remove(Node*);
	int height(Node*) const;
	Node* find(const string&); //returns node to given string
	Node* findParent(Node*); //finds the parent of a given node
	string largest(Node*) const;
	string smallest(Node*) const;

public:
	/*Insert an item into the binary search tree. Be sure to keep the binary search tree properties. 
	When an item is first inserted into the tree the count should be set to 1. When adding a duplicate string (case sensitive), 
	rather than adding another node, the count variable should just be incremented.*/
	void insert(const string&);

	/*Search for a string in the binary search tree. It should return true if the string is in the tree, and false otherwise.*/
	bool search(const string&) const;

	/*Traverse and print the tree in inorder notation following the printing guidelines specified above.*/
	void inOrder() const;

	/*Traverse and print the tree in postorder notation following the printing guidelines specified above.*/
	void postOrder() const;

	/*Traverse and print the tree in preorder notation following the printing guidelines specified above.*/
	void preOrder() const;

	/*Find and return the largest value in the tree. Return an empty string if the tree is empty.*/
	string largest() const;

	/*Find and return the smallest value in the tree. Return an empty string if the tree is empty.*/
	string smallest() const;

	/*Compute and return the height of a particular string in the tree. 
	The height of a leaf node is 0 (count the number of edges on the longest path). Return -1 if the string does not exist.*/
	int height(const string&) const;

	/*Remove a specified string from the tree. Be sure to maintain all binary search tree properties. 
	If removing a node with a count greater than 1, just decrement the count, otherwise, if the count is simply 1, remove the node. 
	You MUST follow the remove algorithm shown in the slides and discussed in class or else your program will not pass the test functions. 
	When removing, if removing a leaf node, simply remove the leaf. Otherwise, if the node to remove has a left child, 
	replace the node to remove with the largest string value that is smaller than the current string to remove 
	(i.e. find the largest value in the left subtree of the node to remove). If the node has no left child, replace the node to remove with 
	the smallest value larger than the current string to remove (i.e. find the smallest value in the right subtree of the node to remove).*/
	void remove(const string&);
};

#endif
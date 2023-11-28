//Collaborated with Armani Korsich, Kiyomi Sugita, & Zybooks pseudo code

#include "BSTree.h"

void BSTree::preOrder(Node* node) const //helper
{
	if (node)
	{
		cout << node->data << "(" << node->count << "), ";
		preOrder(node->left);
		preOrder(node->right);
	}
}
void BSTree::preOrder() const
{
	preOrder(root);
	cout << endl;
}

void BSTree::inOrder(Node*node) const //helper
{
	if (node) {
		inOrder(node->left);
		cout << node->data << "(" << node->count << "), ";
		inOrder(node->right);
	}
}

void BSTree::inOrder() const
{
	inOrder(root);
	cout << endl;
}

void BSTree::postOrder(Node* node) const //helper
{
	if (node)
	{
		postOrder(node->left);
		postOrder(node->right);
		cout << node->data << "(" << node->count << "), ";
	}
}

void BSTree::postOrder() const
{
	postOrder(root);
	cout << endl;
}

bool BSTree::search(const string& str, Node* node) const //helper
{
	if (node == nullptr) {
		return false;
	}
	if (node->data == str) {
		return true;
	}
	else if (search(str, node->left)) {
		return true;
	}
	else if (search(str, node->right)) {
		return true;
	}
	else {
		return false;
	}

}

bool BSTree::search(const string& str) const
{
	return search(str, root);
}

void BSTree::remove(Node* node) 
{
	if (node) {
		if (node->left == nullptr && node->right == nullptr) {
			Node* nodeParent = findParent(node);
			if (nodeParent) {
				if (nodeParent->left == node) {
					nodeParent->left = nullptr;
				}
				else {
					nodeParent->right = nullptr;
				}
			}
			delete node;
		}
		else if (node->left != nullptr) {
			string largestInLeft = largest(node->left);
			int largestInLeftCount = find(largestInLeft)->count;
			remove(find(largestInLeft));
			node->data = largestInLeft;
			node->count = largestInLeftCount;
		}
		else
		{
			string smallestInRight = smallest(node->right);
			int smallestInRightCount = find(smallestInRight)->count;
			remove(find(smallestInRight));
			node->data = smallestInRight;
			node->count = smallestInRightCount;
		}
	}

}

void BSTree::remove(const string& str)
{
	if (!search(str)) {
		return;
	}
	Node* removeNode = find(str);
	if (removeNode->count > 1)
	{
		removeNode->count--;
		return;
	}
	if (height(str) == 0)
	{
		Node* parent = findParent(removeNode);
		if (parent != nullptr) {
			if (str < parent->data) {
				cout << "leaf" << endl;
				if (parent->left->data == str) {
					parent->left = nullptr;
				}
			}
			else {
				parent->right = nullptr;
			}
		}
		if (removeNode == root) {
			root = nullptr;
		}
		delete removeNode;
		return;
	}
	remove(removeNode);
}

void BSTree::insert(const string& item)
{
	if (root == nullptr) {
		root = new Node(item, 1);
		root->left = nullptr;
		root->right = nullptr;
	}
	else {
		Node* curr = root;
		while (curr != nullptr) {
			if (item == curr->data) {
				curr->count++;
				return;
			}
			else if (item < curr->data) {
				if (curr->left == nullptr) {
					curr->left = new Node(item, 1);
					curr->left->left = nullptr;
					curr->left->right = nullptr;
					curr = nullptr;
				}
				else {
					curr = curr->left;
				}
			}
			else {
				if (curr->right == nullptr) {
					curr->right = new Node(item, 1);
					curr->right->right = nullptr;
					curr->right->left = nullptr;
					curr = nullptr;
				}
				else {
					curr = curr->right;
				}
			}
		}
	}
}

string BSTree::largest() const
{
	return largest(root);
}

string BSTree::largest(Node* node) const { //helper
	if (node) {
		Node* curr = node;
		while (curr->right) {
			curr = curr->right;
		}
		return curr->data;
	}
	else {
		return "";
	}
}

string BSTree::smallest() const
{
	return smallest(root);
}

string BSTree::smallest(Node* node) const {
	if (node) {
		Node* curr = node;
		while (curr->left) {
			curr = curr->left;
		}
		return curr->data;
	}
	else {
		return "";
	}
}

int BSTree::height(Node* node) const //helper
{
	if (node == nullptr) {
		return -1;
	}
	int leftHeight = height(node->left);
	int rightHeight = height(node->right);
	return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
}

int BSTree::height(const string& str) const
{
	Node* curr = root;
	if (search(str)) {
		while (curr->data != str) {
			if (str < curr->data) {
				curr = curr->left;
			}
			else {
				curr = curr->right;
			}
		}
		return height(curr);
	}
	else {
		return -1;
	}
}

Node* BSTree::find(const string& str) //helper
{
	Node* curr = root;
	while (curr->data != str && curr != nullptr) {
		if (str < curr->data) {
			curr = curr->left;
		}
		else {
			curr = curr->right;
		}
	}
	return curr;
}

Node* BSTree::findParent(Node* node)
{
	if (node == root)
	{
		return nullptr;
	}
	Node* curr = nullptr;
	if (root) {
		curr = root;
		if (curr->left || curr->right) {
			while (curr->left != nullptr || curr->right != nullptr) {
				if (curr->left) {
					if (curr->left->data == node->data) {
						return curr;
					}
				}
				if (curr->right) {
					if (curr->right->data == node->data) {
						return curr;
					}
				}
				if (node->data < curr->data) {
					curr = curr->left;
				}
				else {
					curr = curr->right;
				}
			}
		}
	}

	return curr;
}
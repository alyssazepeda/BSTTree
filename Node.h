#pragma once
#include <iostream>
using namespace std;

class Node {
public:
	Node* left = nullptr;
	Node* right = nullptr;
	string data = "";
	int count;
	Node(const string&, int);
};
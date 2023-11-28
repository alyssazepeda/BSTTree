#include "Node.h"

Node::Node(const string& str, int number)
{
	left = nullptr;
	right = nullptr;
	data = str;
	count = number;
}

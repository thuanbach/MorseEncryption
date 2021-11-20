/*
 * Node.h
 *
 *  Created on: Nov 19, 2021
 *      Author: thuanbachvan
 */

#ifndef TREE_NODE_H_
#define TREE_NODE_H_

#include <iostream>

using namespace std;

struct Node {
	char letter;
	string code;
	Node* left_node;
	Node* right_node;
};

#endif /* TREE_NODE_H_ */

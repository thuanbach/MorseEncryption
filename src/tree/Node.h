/**
 * This define a tree's node
 *
 * @file Node.h
 * @date Nov 19, 2021
 * @author Thuan Bach
 */

#ifndef TREE_NODE_H_
#define TREE_NODE_H_

#include <iostream>

using namespace std;

struct Node {
	string letter;
	string code;
	Node* left_node;
	Node* right_node;
};

#endif /* TREE_NODE_H_ */

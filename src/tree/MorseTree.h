/*
 * MorseTree.h
 *
 *  Created on: Nov 19, 2021
 *      Author: thuanbachvan
 */

#ifndef TREE_MORSETREE_H_
#define TREE_MORSETREE_H_

#include <iostream>
#include "Node.h"

using namespace std;

class MorseTree {

public:
	MorseTree();
	MorseTree(const string &file);
	virtual ~MorseTree();
private:
	void init_morse_tree_from_file(const string &file);
	Node* parse_a_node_from_raw_text_line(const string &line);
	void insert_node(Node& node);

	Node* root;

};

#endif /* TREE_MORSETREE_H_ */

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
#include "SearchType.h"

using namespace std;

class MorseTree {

public:
	MorseTree();
	MorseTree(const string &file);
	virtual ~MorseTree();
	Node* search_node_by_letter(const string &letter);
	Node* search_node_by_code(const string &code);

	void traverse();

	void traverse_with_node(Node* node);

private:
	Node* search(Node* node, const string &text, const SearchType type);

	Node* search_node(const string &text, const string type);

	void init_morse_tree_from_file(const string &file);

	Node* parse_a_node_from_raw_text_line(const string &line);

	void insert_node(Node* node);

	void insert_node_recursive(Node* parent_node, Node* node, const int level);

	Node* root;
};

#endif /* TREE_MORSETREE_H_ */

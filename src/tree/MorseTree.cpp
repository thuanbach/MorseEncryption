/*
 * MorseTree.cpp
 *
 *  Created on: Nov 19, 2021
 *      Author: thuanbachvan
 */

#include <fstream>
#include "MorseTree.h"
#include "SearchType.h"


MorseTree::MorseTree(){
	root = NULL;
}

MorseTree::~MorseTree() {

}

MorseTree::MorseTree(const string &file_path) {
	init_morse_tree_from_file(file_path);
}


Node* MorseTree::parse_a_node_from_raw_text_line(const string &line){

	Node* node = new Node();

	node->letter = line.at(0);

	node->code = line.substr(1, line.length()-1);

	return node;
}



Node* MorseTree::search_node(const string &text, const string type) {
	return NULL;

}

bool match(Node* node, const string &text, const SearchType type) {

	if (type ==  BY_LETTER ) {
		return node->letter == text;
	}

	return node->code == text;
}

Node* MorseTree::search(Node* node, const string &text, const SearchType type) {
	if (node == NULL) return NULL;

	bool matched = match(node, text, type);

	if (matched) {
		return node;
	}

	Node* from_left = search(node->left_node, text, type);

	if (from_left != NULL){
		return from_left;
	}

	return search(node->right_node, text, type);

}

Node* MorseTree::search_node_by_letter(const string &letter){

	Node* node = search(root->left_node, letter, BY_LETTER);

	if (node == NULL){
		return node;
	}

	return search(root->right_node, letter, BY_LETTER);
}

Node* MorseTree::search_node_by_code(const string &code){

	return search(root->left_node, code, BY_CODE);
}


void MorseTree::insert_node_recursive(Node* parent, Node* node, const int level){

	if (node->code.substr(level, 1) == ".") {
		if (parent->left_node == NULL) {
			parent->left_node = node;
		} else {
			insert_node_recursive(root->left_node, node, level+1);
		}

	} else {
		if (parent->right_node == NULL) {
			parent->right_node = node;
		} else {
			insert_node_recursive(root->right_node, node, level+1);
		}
	}
}

void MorseTree::insert_node(Node* node){
	insert_node_recursive(root, node, 0);
}

 void MorseTree::init_morse_tree_from_file(const string &file_path){



	ifstream ifsCodes;

	ifsCodes.open(file_path);

	cout << file_path;


	string line;

	while (getline(ifsCodes, line)) {

		cout << line << endl;

		Node* node = parse_a_node_from_raw_text_line(line);

		cout << node << endl;

		insert_node(node);
	}
}

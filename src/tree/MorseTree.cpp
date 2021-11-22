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
	root = new Node();
	root->left_node = NULL;
	root->right_node = NULL;
	init_morse_tree_from_file(file_path);
}


Node* MorseTree::parse_a_node_from_raw_text_line(const string &line){

	Node* node = new Node();

	node->letter = line.substr(0, 1);

	node->code = line.substr(1, line.length()-2);

	node->left_node = NULL;
	node->right_node = NULL;

	return node;
}



Node* MorseTree::search_node(const string &text, const string type) {
	return NULL;

}

bool match(Node* node, const string &text, const SearchType type) {

	if (type ==  BY_LETTER ) {
		return (node->letter.compare(text) == 0);
	}

	return node->code.compare(text) == 0;
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

	if (node != NULL){
		return node;
	}

	return search(root->right_node, letter, BY_LETTER);
}

Node* MorseTree::search_node_by_code(const string &code){

	Node* node = search(root->left_node, code, BY_CODE);

	if (node != NULL){
		return node;
	}

	return search(root->right_node, code, BY_CODE);
}


void MorseTree::insert_node_recursive(Node* parent, Node* node, const int level){

	if (node->code.substr(level, 1) == ".") {
		if (parent->left_node == NULL) {
			parent->left_node = node;
		} else {
			insert_node_recursive(parent->left_node, node, level+1);
		}

	} else {
		if (parent->right_node == NULL) {
			parent->right_node = node;
		} else {
			insert_node_recursive(parent->right_node, node, level+1);
		}
	}
}

void MorseTree::insert_node(Node* node){
	insert_node_recursive(root, node, 0);
}

void MorseTree::traverse(){
	cout << endl;
	traverse_with_node(root->left_node);
	traverse_with_node(root->right_node);
}

void MorseTree::traverse_with_node(Node* node){
	if (node != NULL) {
		cout << " letter " << node->letter << " code " << node->code <<  " code length " << node->code.length() << endl ;
		traverse_with_node(node->left_node);
		traverse_with_node(node->right_node);
	}

}


 void MorseTree::init_morse_tree_from_file(const string &file_path){

	ifstream ifsCodes;

	ifsCodes.open(file_path);

	cout << file_path;

	string line;

	while (getline(ifsCodes, line)) {

		Node* node = parse_a_node_from_raw_text_line(line);

		insert_node(node);
	}

	traverse();
}

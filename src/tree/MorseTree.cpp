/*
 * MorseTree.cpp
 *
 *  Created on: Nov 19, 2021
 *      Author: thuanbachvan
 */

#include <fstream>
#include "MorseTree.h"

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

void MorseTree::insert_node(Node& node){

}

 void MorseTree::init_morse_tree_from_file(const string &file_path){


	ifstream ifsCodes;

	ifsCodes.open(file_path);


	string line;

	unsigned int line_index = 0;

	while (getline(ifsCodes, line)) {
		Node* node = parse_a_node_from_raw_text_line(line);
		line_index++;
	}


}

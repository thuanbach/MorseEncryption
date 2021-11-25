/**
 *
 * @file MorseTree.cpp
 * @date Nov 19, 2021
 * @author Thuan Bach
 *
 * This class is responsible for implementing a Morse tree
 */

#include <fstream>
#include "MorseTree.h"
#include "SearchType.h"

/**
 * Default constructor
 */
MorseTree::MorseTree() {
	root = NULL;
}

/**
 * Default de-constructor
 */
MorseTree::~MorseTree() {

}

/**
 * Default constructor with file path where Morse's codes are defined.
 * Read file where each line contain a letter and its corresponding encoded string.
 *
 * @param file_path The file path where Morse's codes are defined.
 */
MorseTree::MorseTree(const string &file_path) {
	root = new Node();
	root->left_node = NULL;
	root->right_node = NULL;
	init_morse_tree_from_file(file_path);
}

/**
 * Parse a node from raw text line
 *
 * @param line A line of the file containing letters and codes
 * @return Node A Node representing a line.
 */
Node* MorseTree::parse_a_node_from_raw_text_line(const string &line) {

	Node *node = new Node();

	node->letter = line.substr(0, 1);

	node->code = line.substr(1, line.length() - 2);

	node->left_node = NULL;
	node->right_node = NULL;

	return node;
}

/**
 * Check if the node matches with text and SearchType condition.
 *
 * @param node A current node
 * @param text A string needs to be searched
 * @param type A SearchType type need to be compared.
 */
bool MorseTree::match(Node *node, const string &text, const SearchType type) {

	if (type == BY_LETTER) {

		string upppercaseLetter = "";

		upppercaseLetter += node->letter.at(0) - 32;

		return (node->letter.compare(text) == 0)
				|| (upppercaseLetter.compare(text) == 0);
	}

	return node->code.compare(text) == 0;
}

/**
 * Search a node by text and a SearchType
 *
 * @param node	A current node that is being checked
 * @param text The text needs to be searched in the tree
 * @param type	A SearchType that is used to to choose letter or code for comparison.
 * @return Node	A node that matches to all conditions.
 */
Node* MorseTree::search(Node *node, const string &text, const SearchType type) {

	if (node == NULL)
		return NULL;

	bool matched = match(node, text, type);

	if (matched) {
		return node;
	}

	Node *from_left = search(node->left_node, text, type);

	if (from_left != NULL) {
		return from_left;
	}

	return search(node->right_node, text, type);

}

/**
 * Search a node by letter
 *
 * @param letter A letter needs to be searched.
 * @return Node A node containing the letter.
 */
Node* MorseTree::search_node_by_letter(const string &letter) {

	Node *node = search(root->left_node, letter, BY_LETTER);

	if (node != NULL) {
		return node;
	}

	return search(root->right_node, letter, BY_LETTER);
}

/**
 * Search a Node by a code
 *
 * @param code	A code needs to be searched
 * @return Node A node containing the code
 */
Node* MorseTree::search_node_by_code(const string &code) {

	Node *node = search(root->left_node, code, BY_CODE);

	if (node != NULL) {
		return node;
	}

	return search(root->right_node, code, BY_CODE);
}

/**
 * Insert a node into the tree recursively.
 *
 * @param parent_node
 * @param node The node needs to be inserted.
 * @param level The tree level
 * @return N/A
 */
void MorseTree::insert_node_recursive(Node *parent, Node *node,
		const int level) {

	if (node->code.substr(level, 1) == ".") {
		if (parent->left_node == NULL) {
			parent->left_node = node;
		} else {
			insert_node_recursive(parent->left_node, node, level + 1);
		}

	} else {
		if (parent->right_node == NULL) {
			parent->right_node = node;
		} else {
			insert_node_recursive(parent->right_node, node, level + 1);
		}
	}
}

/**
 * Insert a node into the tree
 *
 * @param Node A node needs to be inserted.
 * @return N/A
 */
void MorseTree::insert_node(Node *node) {
	insert_node_recursive(root, node, 0);
}

/**
 * Traverse the tree. It supports for verifying the tree is correct or not.
 *
 * @return N/A
 */
void MorseTree::traverse() {
	traverse_with_node(root->left_node);
	traverse_with_node(root->right_node);
}

/**
 * Traverse the tree from a node. It will call recursively its child nodes.
 *
 * @param Node The current node is being traversed.
 */
void MorseTree::traverse_with_node(Node *node) {
	if (node != NULL) {
		traverse_with_node(node->left_node);
		traverse_with_node(node->right_node);
	}
}

/**
 * <p> Initiate the MorseTree from file. <p>
 * <p> Read file where each line contains a letter and its corresponding encoded string. <p>
 * <p> The order of letters's in the file is important because it will be its level in the tree. <p>
 *
 * @param file_path The file path where Morse's codes are defined.
 * @return N/A
 */
void MorseTree::init_morse_tree_from_file(const string &file_path) {

	ifstream ifsCodes;

	ifsCodes.open(file_path);

	string line;

	while (getline(ifsCodes, line)) {

		Node *node = parse_a_node_from_raw_text_line(line);

		insert_node(node);
	}
}

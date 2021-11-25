/**
 * This class is responsible for building Morse Tree.
 *
 * @file MorseTree.h
 * @date Nov 19, 2021
 * @author Thuan Bach
 */

#ifndef TREE_MORSETREE_H_
#define TREE_MORSETREE_H_

#include <iostream>
#include "Node.h"
#include "SearchType.h"

using namespace std;


class MorseTree {

public:
	/**
	 * Default constructor
	 */
	MorseTree();


	/**
	 * Default constructor with file path where Morse's codes are defined.
	 * Read file where each line contain a letter and its corresponding encoded string.
	 *
	 * @param file_path The file path where Morse's codes are defined.
	 */
	MorseTree(const string &file);

	/**
	 * De-Constructor
	 */
	virtual ~MorseTree();

	/**
	 * Search a node by letter
	 *
	 * @param letter A letter needs to be searched.
	 * @return Node A node containing the letter.
	 */
	Node* search_node_by_letter(const string &letter);

	/**
	 * Search a Node by a code
	 *
	 * @param code	A code needs to be searched
	 * @return Node A node containing the code
	 */
	Node* search_node_by_code(const string &code);

	/**
	 * Traverse the tree. It supports for verifying the tree is correct or not.
	 *
	 * @return N/A
	 */
	void traverse();

	/**
	 * Traverse the tree from a node. It will call recursively its child nodes.
	 *
	 * @param Node The current node is being traversed.
	 */
	void traverse_with_node(Node* node);

private:
	/**
	 * Check if the node matches with text and SearchType condition.
	 *
	 * @param node A current node
	 * @param text A string needs to be searched
	 * @param type A SearchType type need to be compared.
	 */
	bool match(Node *node, const string &text, const SearchType type);

	/**
	 * Search a node by text and a SearchType
	 *
	 * @param node	A current node that is being checked
	 * @param text The text needs to be searched in the tree
	 * @param type	A SearchType that is used to to choose letter or code for comparison.
	 * @return Node	A node that matches to all conditions.
	 */
	Node* search(Node* node, const string &text, const SearchType type);


	/**
	 * Initiate Morse tree from file.
	 *
	 * @param file Initiate Morse tree from file
	 * @return N/A
	 *
	 */
	void init_morse_tree_from_file(const string &file);

	/**
	 * Parse a node from raw text line
	 *
	 * @param line A line of the file containing letters and codes
	 * @return Node A Node representing a line.
	 */
	Node* parse_a_node_from_raw_text_line(const string &line);

	/**
	 * Insert a node into the tree
	 *
	 * @param Node A node needs to be inserted.
	 * @return N/A
	 */
	void insert_node(Node* node);

	/**
	 * Insert a node into the tree recursively.
	 *
	 * @param parent_node
	 * @param node The node needs to be inserted.
	 * @param level The tree level
	 * @return N/A
	 */
	void insert_node_recursive(Node* parent_node, Node* node, const int level);

	/**
	 * Declare a root node
	 */
	Node* root;
};

#endif /* TREE_MORSETREE_H_ */

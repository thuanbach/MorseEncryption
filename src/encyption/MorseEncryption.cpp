/*
 * MorseEncryption.cpp
 *
 *  Created on: Nov 19, 2021
 *      Author: thuanbachvan
 */

#include <iostream>
#include <sstream>
#include "MorseEncryption.h"
#include "Node.h"

using namespace std;

MorseEncryption::MorseEncryption(string file_path) {
	tree = new MorseTree(file_path);
}

MorseEncryption::~MorseEncryption() {
}

string MorseEncryption::encode(string message) {
	string encoded_message;

	for (unsigned int i = 0; i < message.length(); i++) {

		string letter = message.substr(i, 1);

		Node *node = tree->search_node_by_letter(letter);

		if (node == NULL) {
			encoded_message.append(letter);
		} else {
			encoded_message.append(node->code);
		}

		encoded_message.append(" ");
	}

	return encoded_message;
}

string MorseEncryption::decode(string encoded_message) {
	string message;

	string code = "";

	for (unsigned int i = 0; i < encoded_message.length(); i++) {
		char character = encoded_message.at(i);

		if (character == ' ' or character == '\t') {
			if (code == "") {
				message.append(1, character);
				//skip the next white space that is used as a encoded message separator
				i++;
			} else {
				Node *node = tree->search_node_by_code(code);

				if (node == NULL) {
					message.append(code);
				} else {
					message.append(node->letter);
				}

				code = "";
			}
		} else {
			code = code + character;
		}

	}

	if (code != "" ) {
		message.append(code);
	}
	return message;
}

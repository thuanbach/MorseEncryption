/*
 * MorseEncryption.cpp
 *
 *  Created on: Nov 19, 2021
 *      Author: thuanbachvan
 */

#include <iostream>
#include "MorseEncryption.h"
#include "Node.h"

using namespace std;


MorseEncryption::MorseEncryption(string file_path) {
	cout << "Mor" << endl;
	tree = new MorseTree(file_path);
}

MorseEncryption::~MorseEncryption() {
}


string MorseEncryption:: encode(string message) {
	string encoded_message;

	cout << "Message--------" << message << endl;

	for (unsigned int i=0; i < message.length(); i++) {

		string letter =  message.substr(i, 1);

		Node* node = tree->search_node_by_letter(letter);

		if (node == NULL) {
			encoded_message.append(letter);
		} else {
			encoded_message.append(node->code);
		}
	}

	return encoded_message;
}

string MorseEncryption:: decode(string encoded_message){
	string message;


	return message;
}

/**
 *
 * @file MorseEncryption.cpp
 * @author Thuan Bach
 * @date Nov 19, 2021
 *
 * This class is responsible implement encoding and decoding functionality
 */

#include <iostream>
#include <sstream>
#include "MorseEncryption.h"
#include "Node.h"

using namespace std;

/**
 *  MorseEncryption's Construction
 */
MorseEncryption::MorseEncryption(string file_path) {
	tree = new MorseTree(file_path);
}

/**
 *  MorseEncryption's de-construction
 */
MorseEncryption::~MorseEncryption() {
}

/**
 *
 *  <p> Implement encoding functionality. <p>
 *  <p> Receiving a string message and return a encoded string. <p>
 *  <p> if a character is not a letter, the character is returned as the encoded character. <p>
 *  <p> There is always a space as a separator between characters in encoded message <p>
 *
 *  @param	message	The message needs to be encoded.
 *  @return	string	A corresponding encoded message.
 */
string MorseEncryption::encode(string message) {
	string encoded_message = "";

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

/**
 *  <p> Implement decoding functionality. <p>
 *  <p> Receiving a encoded string and return the message that is encoded. <p>
 *
 *  @param	encoded_message	The encoded message.
 *  @return	string	A message that used.
 */
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

	if (code != "") {
		message.append(code);
	}

	return message;
}

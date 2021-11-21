/*
 * ConsoleEncryptionApp.cpp
 *
 *  Created on: Nov 20, 2021
 *      Author: thuanbachvan
 */

#include <iostream>

using namespace std;

#include "ConsoleEncryptionApp.h"
#include "MorseEncryption.h"

ConsoleEncryptionApp::ConsoleEncryptionApp() {
}

ConsoleEncryptionApp::~ConsoleEncryptionApp() {
}

void ConsoleEncryptionApp::start(const string &file) {

	MorseEncryption encryption(file);
	string message;

	string encoded_message = encryption.encode("e");
	cout << "Coded message:" << encoded_message << endl;


	string decoded_message = encryption.decode(encoded_message);
	cout << "Decoded message" << decoded_message << endl;


	while (true) {
		cout << "Enter a message. (Enter \"exit\" to exit)> ";
		getline(cin, message);

		if (message == "exit") {
			break;
		}


		string encoded_message = encryption.encode(message);
		cout << "Coded message:" << encoded_message << endl;


		string decoded_message = encryption.decode(encoded_message);
		cout << "Decoded message" << decoded_message << endl;
	}

}

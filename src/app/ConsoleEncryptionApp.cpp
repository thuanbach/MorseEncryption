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

	string message = "";

	while (true) {
		cout << "Enter a message. (Enter 0 to exit)> ";

		getline(cin, message);

		size_t index = message.find_first_of("\n\r");
		if (index != string::npos) {
			message = message.substr(0, index);
		}

		if (message == "") continue;

		if (message == "0") {
			cout << "Application shut down";
			break;
		}

		string encoded_message = encryption.encode(message);
		cout << "Coded message" << endl;
		cout << encoded_message << endl;

		string decoded_message = encryption.decode(encoded_message);
		cout << "Decoded message" << endl;
		cout << decoded_message << endl;
	}

}

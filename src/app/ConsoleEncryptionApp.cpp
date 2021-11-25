/**
 * This class is responsible for GUI for your interaction in using Morse's encoding and decoding functionality.
 * It will prompt users for a message and display a encoded message and a decoded message.
 *
 * @file ConsoleEncryptionApp.cpp
 * @author 	Thuan Bach
 * @date	 Nov 20, 2021
 *
 */

#include <iostream>

using namespace std;

#include "ConsoleEncryptionApp.h"
#include "MorseEncryption.h"

/**
 * ConsoleEncryptionApp's constructor
 */
ConsoleEncryptionApp::ConsoleEncryptionApp() {
}

/**
 *  ConsoleEncryptionApp's de-constructor
 */
ConsoleEncryptionApp::~ConsoleEncryptionApp() {
}

/**
 *  Start the console encryption application where user can use Morse's encoding and decoding functionality.
 *
 *  @param	file	The path to the file that Morse's encodes
 *  @return  N/A
 */
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

		if (message == "")
			continue;

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

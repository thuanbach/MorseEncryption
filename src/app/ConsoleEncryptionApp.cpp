/*
 * ConsoleEncryptionApp.cpp
 *
 *  Created on: Nov 20, 2021
 *      Author: thuanbachvan
 */

#include <iostream>

using namespace std;

#include <ConsoleEncryptionApp.h>

ConsoleEncryptionApp::ConsoleEncryptionApp() {
}

ConsoleEncryptionApp::~ConsoleEncryptionApp() {
}


void ConsoleEncryptionApp::start() {

	string line;

	while (true) {
		 cout << "Enter a message. (Enter \"exit\" to exit)> ";
		 getline(cin, line);

		 if (line == "exit") {
			 break;
		 }

	}


}

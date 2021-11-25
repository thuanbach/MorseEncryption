/**
 * This class is responsible for GUI for your interaction in using Morse's encoding and decoding functionality.
 * It will prompt users for a message and display a encoded message and a decoded message.
 *
 * @file ConsoleEncryptionApp.h
 * @author 	Thuan Bach
 * @date	 Nov 20, 2021
 *
 */
#ifndef APP_CONSOLEENCRYPTIONAPP_H_
#define APP_CONSOLEENCRYPTIONAPP_H_

#include <iostream>
#include "MorseTree.h"

using namespace std;

class ConsoleEncryptionApp {

public:
	/**
	 * ConsoleEncryptionApp's constructor
	 */
	ConsoleEncryptionApp();

	/**
	 *  ConsoleEncryptionApp's de-constructor
	 */
	virtual ~ConsoleEncryptionApp();

	/**
	 *  Start the console encryption application where user can use Morse's encoding and decoding functionality.
	 *
	 *  @param	file	The path to the file that Morse's encodes
	 *  @return  N/A
	 */
	void start(const string &file);

};

#endif /* APP_CONSOLEENCRYPTIONAPP_H_ */

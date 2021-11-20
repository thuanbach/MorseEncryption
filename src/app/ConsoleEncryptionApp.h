/*
 * ConsoleEncryptionApp.h
 *
 *  Created on: Nov 20, 2021
 *      Author: thuanbachvan
 */

#ifndef APP_CONSOLEENCRYPTIONAPP_H_
#define APP_CONSOLEENCRYPTIONAPP_H_

#include <iostream>
#include "MorseTree.h"

using namespace std;

class ConsoleEncryptionApp {
public:
	ConsoleEncryptionApp();
	virtual ~ConsoleEncryptionApp();
	void start(const string& file);

private:
	MorseTree tree;
};

#endif /* APP_CONSOLEENCRYPTIONAPP_H_ */

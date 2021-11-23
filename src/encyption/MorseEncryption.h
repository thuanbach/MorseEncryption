/*
 * MorseEncryption.h
 *
 *  Created on: Nov 19, 2021
 *      Author: thuanbachvan
 */

#ifndef MORSEENCRYPTION_H_
#define MORSEENCRYPTION_H_

#include <iostream>
#include "MorseTree.h"

using namespace std;

class MorseEncryption {

public:
	MorseEncryption();
	MorseEncryption(string file_path);

	virtual ~MorseEncryption();

	string encode(string message);

	string decode(string encoded_message);

private:

	MorseTree* tree;
};

#endif /* MORSEENCRYPTION_H_ */

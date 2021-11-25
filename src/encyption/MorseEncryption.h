/**
 *
 * @file MorseEncryption.h
 * @author Thuan Bach
 * @date Nov 19, 2021
 *
 * This class is responsible implement encoding and decoding functionality
 */

#ifndef MORSEENCRYPTION_H_
#define MORSEENCRYPTION_H_

#include <iostream>
#include "MorseTree.h"

using namespace std;

class MorseEncryption {

public:
	/**
	 * @author Thuan Bach
	 * @date Nov 19, 2021
	 *
	 *  MorseEncryption's Construction
	 */
	MorseEncryption();

	/**
	 * @author Thuan Bach
	 * @date Nov 19, 2021
	 *
	 *  MorseEncryption's Construction with initiating MorseTree whose codes are loaded from a file
	 *
	 *  @param	file_path The path to the file where Morse's codes are defined.
	 */
	MorseEncryption(string file_path);

	/**
	 * @author Thuan Bach
	 * @date Nov 19, 2021
	 *
	 *  MorseEncryption's de-construction
	 */
	virtual ~MorseEncryption();

	/**
	 * @author Thuan Bach
	 * @date Nov 19, 2021
	 *
	 *  <p> Implement encoding functionality. <p>
	 *  <p> Receiving a string message and return a encoded string. <p>
	 *  <p> if a character is not a letter, the character is returned as the encoded character. <p>
	 *  <p> There is always a space as a separator between characters in encoded message <p>
	 *
	 *  @param	message	The message needs to be encoded.
	 *  @return	string	A corresponding encoded message.
	 */
	string encode(string message);

	/**
	 * @author Thuan Bach
	 * @date Nov 19, 2021
	 *
	 *  <p> Implement decoding functionality. <p>
	 *  <p> Receiving a encoded string and return the message that is encoded. <p>
	 *
	 *  @param	encoded_message	The encoded message.
	 *  @return	string	A message that used.
	 */
	string decode(string encoded_message);

private:
	/**
	 * Declare a MorseTree
	 */
	MorseTree* tree;
};

#endif /* MORSEENCRYPTION_H_ */

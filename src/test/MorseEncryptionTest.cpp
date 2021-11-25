/**
 * Implement unit tests for Morse Code encoding and decoding
 *
 * @file MorseEncryptionTest.cpp
 * @date Nov 23, 2021
 * @author Thuan Bach
 */

#include <iostream>
#include "MorseEncryption.h"

using namespace std;

/**
 * Verify the result.
 *
 * @param result A boolean of the test
 * @return string A string repenting the test passed or failed.
 */
string verify_result(bool result) {
	if (result) {
		return "Pass";
	}

	return "Fail";
}

/**
 * Test Morse code encoding/decoding with all alphabets.
 *
 * @param encryption MorseEncryption object
 * @return N/A
 */
void test_all_alphabets(MorseEncryption &encryption) {

	string alphabets = "abcdefghijklmnopqrstuvwxyz";

	for(auto m: alphabets){
		string expected_encoded = "";

		string message = string(1, m);
		string encoded_message = encryption.encode(message);
		string decoded_message = encryption.decode(encoded_message);
		switch (m) {
			case 'e':
				expected_encoded = ".";
				break;
			case 't':
				expected_encoded = "–";
				break;
			case 'i':
				expected_encoded = "..";
				break;
			case 'a':
				expected_encoded = ".–";
				break;
			case 'n':
				expected_encoded = "–.";
				break;
			case 'm':
				expected_encoded = "––";
				break;
			case 's':
				expected_encoded = "...";
				break;
			case 'u':
				expected_encoded = "..–";
				break;
			case 'r':
				expected_encoded = ".–.";
				break;
			case 'w':
				expected_encoded = ".––";
				break;
			case 'd':
				expected_encoded = "–..";
				break;
			case 'k':
				expected_encoded = "–.–";
				break;
			case 'g':
				expected_encoded = "––.";
				break;
			case 'o':
				expected_encoded = "–––";
				break;
			case 'h':
				expected_encoded = "....";
				break;
			case 'v':
				expected_encoded = "...–";
				break;
			case 'f':
				expected_encoded = "..–.";
				break;
			case 'l':
				expected_encoded = ".–..";
				break;
			case 'p':
				expected_encoded = ".––.";
				break;
			case 'j':
				expected_encoded = ".–––";
				break;
			case 'b':
				expected_encoded = "–...";
				break;
			case 'x':
				expected_encoded = "–..–";
				break;
			case 'c':
				expected_encoded = "–.–.";
				break;
			case 'y':
				expected_encoded = "–.––";
				break;
			case 'z':
				expected_encoded = "––..";
				break;
			case 'q':
				expected_encoded = "––.–";
				break;
			default:
				break;
		}

		// space between encoded characters
		expected_encoded.append(1, ' ');

		cout << "Test encoding " << m << ": " << verify_result(expected_encoded == encoded_message) << endl;
		cout << "Test decoding " << m << ": " << verify_result(message == decoded_message) << endl;

	}
}

/**
 * Test Morse code encoding/decoding with upper cases.
 *
 * @param encryption MorseEncryption object
 * @return N/A
 */
void test_uppercase_alphabets(MorseEncryption &encryption) {
	string message = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	string encoded_message = encryption.encode(message);
	string decoded_message = encryption.decode(encoded_message);

	cout << "Test alphabet with upper cases: " << verify_result(decoded_message == "abcdefghijklmnopqrstuvwxyz") << endl;
}

/**
 * Test Morse code encoding/decoding with other characters.
 *
 * @param encryption MorseEncryption object
 * @return N/A
 */
void test_other_characters(MorseEncryption &encryption) {
	string message = "1234567890+-,!@#$%^&*():";

	string encoded_message = encryption.encode(message);
	string decoded_message = encryption.decode(encoded_message);

	cout << "Test other characters: " << verify_result(decoded_message == message) << endl;
}

/**
 * Test Morse code encoding/decoding with spaces between words.
 * @param encryption MorseEncryption object
 * @return N/A
 */
void test_space_between_words(MorseEncryption &encryption) {
	string message = "	h	w	a  q";

	string encoded_message = encryption.encode(message);
	string decoded_message = encryption.decode(encoded_message);

	cout << "Test space between characters: " << verify_result(decoded_message == message) << endl;
}

/**
 * Implement unit tests for Morse codes' encoding and decoding
 *
 * @param file_path The file path where Morse codes are defined.
 * @return N/A
 */
void test_morse_encryption(string file_path) {
	MorseEncryption encryption(file_path);

	test_all_alphabets(encryption);

	test_uppercase_alphabets(encryption);

	test_other_characters(encryption);

	test_space_between_words(encryption);
}

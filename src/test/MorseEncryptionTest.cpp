/*
 * MorseEncryptionTest.cpp
 *
 *  Created on: Nov 23, 2021
 *      Author: Thuan Bach
 */



#include <iostream>
#include "MorseEncryption.h"

using namespace std;

string verify_result(bool result) {
	if (result) {
		return "Pass";
	}

	return "Fail";
}

void test_all_alphabets(MorseEncryption &encrytion) {

	string alphabets = "abcdefghijklmnopqrstuvwxyz";

	for(auto m: alphabets){
		string expected_encoded = "";

		string message = string(1, m);
		string encoded_message = encrytion.encode(message);
		string decoded_message = encrytion.decode(encoded_message);
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

void test_uppercase_alphabets(MorseEncryption &encrytion) {
	string message = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	string encoded_message = encrytion.encode(message);
	string decoded_message = encrytion.decode(encoded_message);

	cout << "Test alphabet with upper cases: " << verify_result(decoded_message == "abcdefghijklmnopqrstuvwxyz") << endl;
}


void test_other_characters(MorseEncryption &encrytion) {
	string message = "1234567890+-,!@#$%^&*():";

	string encoded_message = encrytion.encode(message);
	string decoded_message = encrytion.decode(encoded_message);

	cout << "Test other characters: " << verify_result(decoded_message == message) << endl;
}


void test_space_between_words(MorseEncryption &encrytion) {
	string message = "	h	w	a  q";

	string encoded_message = encrytion.encode(message);
	string decoded_message = encrytion.decode(encoded_message);

	cout << "Test space between characters: " << verify_result(decoded_message == message) << endl;
}

void test_morse_encrytion(string file_path) {
	MorseEncryption encryption(file_path);

	test_all_alphabets(encryption);

	test_uppercase_alphabets(encryption);

	test_other_characters(encryption);

	test_space_between_words(encryption);
}

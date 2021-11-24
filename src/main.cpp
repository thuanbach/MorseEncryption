//============================================================================
// Name        : CS700Assignment5.cpp
// Author      : Thuan Bach
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include "ConsoleEncryptionApp.h"
#include "MorseEncryptionTest.h"

using namespace std;

/** Define a test mode used to run unit tests */
const unsigned int TEST_MODE = 1;

/**  Define an application mode used to run the Shaker sort' measurement */
const unsigned int APP_MODE = 2;

/**  Define a running mode for the application. */
const unsigned int RUNNING_MODE = APP_MODE;

int main() {
	string file_path = "src/codes/morse_codes.txt";

	if (RUNNING_MODE == APP_MODE) {

		ConsoleEncryptionApp app;
		app.start(file_path);

	} else {
		test_morse_encrytion(file_path);
	}

	return 0;
}

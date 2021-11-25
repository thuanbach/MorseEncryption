
/**
 *
 * This file contains the main function where the main application gets started.
 *
 * @file main.cpp
 * @author Thuan Bach
 * @date Nov 19, 2021
 */

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

/**
 * This the main function where the main application gets started.
 *
 * @return Always 0 if the application terminated correctly
 */
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

/*
 * main.c
 *
 *  Created on: Jul 18, 2018
 *      Author: bhart
 */

#include "stdafx.h"

#include <include/conversion_core.h>
#include <include/console_core.h>
#include <include/debug_core.h>

/** Serves as a driver for the routines in console_core library. */

int main(void) {
	log_info("Welcome to console_core_tests");

	log_info("Testing get_line_with_default");

	char first_num_buff[2];
	char second_num_buff[2];
	char name[11];

	get_line_with_default("> Enter a number >", first_num_buff, "2", 2);

	get_line_with_default("> Enter a number >", second_num_buff, "3", 2);

	log_info("first_num_buff = %s", first_num_buff);

	log_info("second_num_buff = %s", second_num_buff);

	/* Turn the numbers typed by the user as input into actual long integers, add them, and
	 * show the user the result.
	 */

	long first_num = 0;
	long second_num = 0;

	if (char_to_long(first_num_buff, &first_num) == EXACTLY_CORRECT
			&& char_to_long(second_num_buff, &second_num) == EXACTLY_CORRECT) {
		printf("The sum of the two numbers entered is %ld.\n", first_num + second_num);
	}

	get_line_with_default("> Enter your name (max 10 chars) >", name, "", 11);

	printf("Hello, %s!\n", name);

	log_info("Done");

	return 0;
}

/**
 * Author:     snowcrash 
 * Date:       February 1 2019.
 *
 * This code is ugly, but it is used for testing purposes.
 * Writes tests for 3SAT solver to stdout.
 *
 *	Usage: ./generate_test -t 'test type' -n 'test number'
 *	-t = ("pass" / "fail")
 *	-n = (test number to print 1, 2, 3, 4, ... , n)
 */

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <ctype.h>
#include "../lib/test_input.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma ide diagnostic ignored "cert-err34-c"

int main(int argc, char **argv)
{
	int test_type;

	void (*test_ptr[])(int) = { test_fail_stdin, test_pass_stdin };

	if (argc == 5 && strncmp(argv[1], "-t", sizeof("-t")) == 0 &&
		    (test_type = strncmp(argv[2], "pass", sizeof("pass")) ==
				 0) ||
	    strncmp(argv[2], "fail", sizeof("fail")) == 0 &&
		    strncmp(argv[3], "-n", sizeof("-n") - 1) == 0 &&
		    isdigit(*argv[4])) {
		(*test_ptr[test_type])(atoi(argv[4]));
		exit(EXIT_SUCCESS);
	}

	printf("assert_false tests: %zu\nassert_true tests:  %zu\n",
	       FAIL_SIZE - 1, PASS_SIZE - 1);
	exit(EXIT_FAILURE);
}

#pragma clang diagnostic pop

void test_fail_stdin(int test_number)
{
	if (FAIL_SIZE > test_number) {
		printf("%s\n", fail_tests[test_number]);
	}
}

void test_pass_stdin(int test_number)
{
	if (PASS_SIZE > test_number) {
		printf("%s\n", pass_tests[test_number]);
	}
}

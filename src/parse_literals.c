/**
 * Author:     snowcrash 
 * Date:       February 1 2019.
 */

#include "../lib/parse_literals.h"

/**
 * 	build_clause:
 *
 *  Builds a clause out of disjuncted literals.
 *
 *  @param store_clause where the literals are going to be stored.
 *  @return returns (n) if n_literals < (n) then it's an error. Each literal is stored in memory
 *  at the location store_clause.
 *
 */

int build_clause(void *store_clause)
{
	int n_literals; /* the number of literals stored */
	char *build_clause = NULL;

	build_clause = (char *)store_clause; /* the literals's. */
	ungetc(__DISJUNCT_SYMBOL, stdin); /* prime stdin */

	for (n_literals = 0; n_literals < __OR_OF_N_LITERALS; n_literals++) {
		if (!check_disjunction() ||
		    !(build_clause[n_literals] =
			      (char)get_literal())) /* stores valid disjuncts */
		{
			fprintf(stderr, "%s error: %s\n", __PRETTY_FUNCTION__,
				strerror(__IO_ERROR)),
				exit(1);
		}
	}

	return (n_literals);
}

/**
 * check_disjunction:
 *
 * @return returns true (1) if the next character is '+', otherwise false. (0).
 */

int check_disjunction(void)
{
	return (eat_whitespace() == __DISJUNCT_SYMBOL);
}

/**
 * get_literal:
 *
 * Checks if the next character from stdin is alphanumeric & lower case.
 *
 * @return either an error (0) or the validated (Upper / Lower) case literal.
 * (Upper case) ABCDE, ... ,Z means a negative literal.
 * (Lower case) abcde, ..., z means a positive literal.
 *
 */

int get_literal(void)
{
	int c;

	return (isalpha(c = eat_whitespace()) && islower(c)) ?
		       (check_negation() ? toupper(c) : c) :
		       false;
}

/**
 * check_negation:
 *
 * Checks if (next char) is a logical negation.
 * Pushes character back on input buffer of stream if the next character read in is not (').
 *
 * @return returns true (1), or false (0).
 */

int check_negation(void)
{
	int c;

	if ((c = eat_whitespace()) == __NEGATION_SYMBOL) {
		return true;
	}

	ungetc(c, stdin);
	return false;
}

/**
 * eat_whitespace:
 *
 * Reads from stdin consumes all white space.
 *
 * @return returns first non whitespace character encountered.
 */

int eat_whitespace(void)
{
	int c;

	while (isspace(c = getc(stdin))) {
	}

	return c;
}

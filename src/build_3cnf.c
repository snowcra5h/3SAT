/**
 * Author:     snowcrash
 * Date:       February 1 2019.
 *
 * valid input is whitespace or '(' or ')' or '+' or '\'' or lowercase alphanumerical values.
 * analyze's (an expressions), break into its parts and store.
 */

#include "../lib/build_3cnf.h"
#include "../lib/build_formula.h"
#include "../lib/verify_sat.h"

/**
 * add_clause:
 *
 * Valid clauses are added to a boolean formula.
 * Once 3 disjuncted literals are added to a clause. It's can be considered in valid 3CNF form.
 *
 * @param clause used to store each clause.
 * @param bf the struct containing pointers that hold address's of the start and end of a boolean formula.
 */

void add_clause(void *clause, FORMULA *bf)
{
	int c, i;

	for (i = 0; i <= __ASCII; i++) {
		bf->n_stored_literal[i] = bf->sat_list[i] = 0;
	}

	while ((c = eat_whitespace()) != __CURRENT_EOF) {
		if (c != __IN_CLAUSE) {
			fprintf(stderr, "%s error: %s\n", __PRETTY_FUNCTION__,
				strerror(__IO_ERROR)),
				exit(1);
		} else if (!in_clause(clause)) {
			fprintf(stderr, "%s error: %s\n", __PRETTY_FUNCTION__,
				strerror(__IO_ERROR)),
				exit(1);
		} else {
			store_new_conjunct(clause, bf);
		}
	}
}

/**
 * in_clause:
 *
 * This function should be called when the first character is validated as '('.
 *
 * All valid 3CNF clause's are inside of braces '('a + b + c')',
 * validation is done here to ensure that each clause ends with ')'.
 *
 * @param clause used to store literals.
 * @return: Returns true (1), or false (0).
 */

int in_clause(void *clause)
{
	return (validate_clause(clause) && (eat_whitespace()) == __OUT_CLAUSE);
}

/**
 * validate_clause:
 *
 * If each literal read in, is a lower case alphanumeric non negative, or negative '\'' character,
 * and each term is separated by a disjunction. Then it is in 3CNF form.
 *
 * @param where the clause will be held in memory. .
 * @return true or false value, if the returned size is equal to the valid number of literals in a 3SAT.
 */

int validate_clause(void *clause)
{
	return (build_clause(clause) == __OR_OF_N_LITERALS);
}

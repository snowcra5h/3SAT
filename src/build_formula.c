/**
 * Author:     snowcrash
 * Date:       February 1 2019.
 *
 * Mount Royal University
 * - Department of Mathematics and Computing.
 */

#include "../lib/build_formula.h"

/**
 * store_new_conjunct:
 *
 * Adds a conjunct to each node in a boolean formula, each link in node represents a disjunction of 3 terms.
 * @param literals should be a group of 3 validated literals ( a clause ) .
 * @param bf holds pointers to the first, and last node in the linked list. also contains the supporting data.
 */

void store_new_conjunct(void *literals, FORMULA *bf)
{
	CNF *new_conjunct = init_data(); /* the new disjuncts to store */
	add_validated_literals(new_conjunct, literals,
			       bf); /* add the validated literals to new node */
	add_conjunct(bf,
		     new_conjunct); /* insert node at boolean_formula of list */
}

/**
 * init_data:
 *
 * Allocates memory for conjunct, initializes fields, returns to caller.
 *
 * @return returns an address for the new conjunct to be stored at.
 */

CNF *init_data(void)
{
	int i;
	CNF *node = malloc(sizeof(CNF));

	if (node == NULL) /* Heap is out of space */
	{
		fprintf(stderr, "Error Heap is out of space: %s\n",
			strerror(errno));
		exit(1);
	}

	for (i = 0; i < _MAX_LITERALS_; i++) {
		node->mark_literal[i] = _NO_CUR_LITERAL; /* initialize to -1 */
	}

	return node;
}

/**
 * add_conjunct:
 *
 * append p_conjunct to the end of a 3CNF boolean formula.
 * The last Conjuct added will be pointed to by boolean_formula.last
 * The first Conjuct will be pointed to by boolean_formula.first
 *
 * @param p_formula the struct containing pointers that hold address's of the start and end of a boolean formula.
 * @param p_conjunct the containing containing the new conjunct.
 */

void add_conjunct(FORMULA *p_formula, CNF *p_conjunct)
{
	CNF *temp = p_formula->last;

	p_formula->last = p_conjunct;
	p_conjunct->prev = temp;
	p_conjunct->next = (CNF *)&p_formula;
	temp->next = p_conjunct;
}

/**
 * destroy_list:
 *
 * "returns" memory to heap.
 *  @param p_formula the struct containing pointers that hold address's of the start and end of a boolean formula.
 *
 */

void destroy_list(FORMULA *p_formula)
{
	while (p_formula->first != p_formula->last) {
		p_formula->first = p_formula->first->next;
		free(p_formula->first->prev);
	}

	free(p_formula->first);
}

/**
 * add_validated_literals:
 *
 * Copy the validated literals into the new_clause, tracks the number of occurrences in each literal to optimize
 * which literal is picked to satisfy the boolean formula.
 *
 * @param new_conjunct the conjunct that will store the disjuncted literals.
 * @param literals the location of the disjuncted literals in memory.
 * @param track_literals the container that has the address of the location we are storing the
 * number of stored literals at.
 */

void add_validated_literals(CNF *new_conjunct, void *literals,
			    FORMULA *track_literals)
{
	int n_validated;
	char *n_literal = (char *)
		literals; /* the literal at the nth position in memory */

	for (n_validated = 0; n_validated < _MAX_LITERALS_; n_validated++) {
		track_literals->n_stored_literal[(
			new_conjunct->disjuncts[n_validated] = *n_literal++)]++;
	}
}

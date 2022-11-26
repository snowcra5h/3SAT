/**
 * Author:     snowcrash 
 * Date:       February 1 2019.
 */

#include "../lib/verify_sat.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCDFAInspection"

/**
 * check_sat:
 *
 * Recursively back tracks through each stored conjuncts, attempting to find truth value's that will satisfy at-least
 * one disjuncted literal per conjunct. Returning the value (1) true if satisfiable.
 *
 * If no truth values that satisfy the stored boolean formula could be found, then it returns a flag with the value
 * (0) false.
 *
 * Detailed explanation:
 *
 * Checks conjuncts for matching sat_list value. If found branch true, else branch false, and for all literals in
 * p_conjuct if there exists a negation of the sat_list literals then
 * p_conjunct->mark_literal[offset_in_memory_for_literal] is set to false.
 *
 * If check_sat failed, then (no matching value was found). At this point all flags should have been set for
 * negations, an optimal value needs to be found, if all values have been marked false, then there is no way
 * to satisfy them, picking an optimal value would not be optimal, and false is returned. Otherwise, set_sat is called
 * to handle new transitions.
 *
 * @param head a pointer containing the address of the current conjunct.
 * @param boolean_data the "boolean data" holds the address's of the first, and last conjuncts in memory.
 * @return true if satisfied, otherwise false.
 */

int track_matching(CNF *head, FORMULA *boolean_data)
{
	int optimal;

	if (head != (CNF *)boolean_data) {
		if (head == boolean_data->last) {
			if (check_sat(boolean_data, head)) {
				return true;
			}

			if ((optimal =
				     get_optimal_literal(boolean_data, head))) {
				add_optimal_to_sat(optimal, head, boolean_data);
				return true;
			}
			return false;
		}

		if (check_sat(boolean_data, head)) {
			return track_matching(head->next, boolean_data);
		}

		if ((optimal = get_optimal_literal(boolean_data, head))) {
			return set_sat(optimal, head, boolean_data);
		}
		return false; /* all literals exhausted */
	} else { /* the empty string */
		return (-1);
	}
}

/**
 * set_sat:
 *
 * If an optimal value was found, adds the optimal_literal to sat_list,
 *
 * Detailed Explanation:
 *
 * Calls the functions calling function, and continues branching with the new literal.
 * if a return is false, then the optimal literal which was chosen is negated in sat_list, this has a
 * cause / effect, when the literal stored in sat_data is negated, and a new recursive call is
 * done, it will set the current optimal values flag to false, and attempt to find a new optimal value.
 * this continues until all branches have been exhausted, then the values are removed from sat_list.
 *
 * @param optimal_literal the literal that will be stored, and possibly negated.
 * @param head a pointer containing the address of the current conjunct.
 * @param boolean_data the "boolean data" holds the address's of the first, and last conjuncts in memory.
 * @return true if satisfied, otherwise false.
 */

int set_sat(const int optimal_literal, CNF *head, FORMULA *boolean_data)
{
	add_optimal_to_sat(optimal_literal, head,
			   boolean_data); /* add optimal_literal to sat_list,
    * and mark_literal is set to true. */

	if (track_matching(head->next, boolean_data) == 0) {
		negate_marked_literal(boolean_data, optimal_literal);

		/* If this returns false, then the negated literal is removed from sat_data, and false is returned. */
		if (track_matching(head, boolean_data) != 0) {
			return true;
		} else {
			boolean_data->sat_list[negate_literal(optimal_literal)] =
				_LITERAL_REMOVED;
			return false;
		}
	} else {
		return true;
	}
}

/**
 * negate_marked_literal:
 *
 * Removes old literal from sat_list negates it, and adds the negated value to sat_list.
 *
 * @param p_conjunct a pointer containing the address of the current conjunct.
 * @param bf the stored boolean formula, and SAT literals.
 */

void negate_marked_literal(FORMULA *bf, int optimal_literal)
{
	int new_literal;

	new_literal = negate_literal(
		optimal_literal); /* negates the marked literal */

	bf->sat_list[optimal_literal] = _LITERAL_REMOVED;
	bf->sat_list[new_literal] = _LITERAL_SATISFIED;
}

/**
 * get_index:
 *
 * iterates through current conjunct's marked list, and returns the index of the literal you pass in.
 *
 * @param head a pointer containing the address of the current conjunct.
 * @param literal_to_find should be the value of literal to find.
 * @return -1 if something went wrong, otherwise
 */

int get_index(CNF *head, int literal_to_find)
{
	int i;

	for (i = 0; i < _MAX_LITERALS_; i++) {
		if (head->disjuncts[i] == literal_to_find) {
			return i;
		}
	}

	fprintf(stderr, "%s error: %s\n", __PRETTY_FUNCTION__,
		strerror(__IO_ERROR)),
		exit(1);
}

/**
 * add_optimal_to_sat:
 *
 * adds optimal literal to sat_list and marks it in marked_literal.
 *
 * @param head a pointer containing the address of the current conjunct.
 * @param bf the stored boolean formula, and SAT literals.
 * @param literal_to_store should be the literal you want to mark.
 */

void add_optimal_to_sat(int literal_to_store, CNF *head, FORMULA *bf)
{
	int index_of_optimal = get_index(head, literal_to_store);

	bf->sat_list[literal_to_store] = head->mark_literal[index_of_optimal] =
		true;
}

/**
 * get_optimal_literal:
 *
 * returns the 'base 10' ascii value of some literal that occurs most frequently in the boolean formula.
 *
 * @param head a pointer containing the address of the current conjunct.
 * @param bf the stored boolean formula, and SAT literals.
 * @return 'base 10' ascii value of most frequencet literal. If the return was 0 then mark_literal was all negative.
 */

int get_optimal_literal(FORMULA *bf, CNF *head)
{
	int n_literals = INT_MIN;
	int sat_literal = false;
	int index;

	for (index = 0; index < _MAX_LITERALS_; index++) {
		if (head->mark_literal[index] != 0 &&
		    n_literals < bf->n_stored_literal[head->disjuncts[index]]) {
			n_literals =
				bf->n_stored_literal[head->disjuncts[index]];
			sat_literal = head->disjuncts[index];
		}
	}

	return sat_literal;
}

/**
 * check_sat:
 *
 * If the current conjunct contains a disjunct, who's truth value can be satisfied by any of the currently stored
 * literal values. Then the conjuncts stored flag will be set to true, and the value returned will be true.
 * if it encounters a negated literal, that is equal to the current literal then mark_literal is set to
 * false.
 *
 * @param head a pointer containing the address of the current conjunct.
 * @param bf the stored boolean formula, and SAT literals.
 *
 * @return returns true if found, otherwise false.
 *
 */

int check_sat(FORMULA *bf, CNF *head)
{
	int index;
	int has_match = false;
	int check_negation;
	int stored_literal;

	for (index = 0; index < _MAX_LITERALS_; index++) {
		/* if this is true, negation gets marked */
		check_negation = negate_literal(head->disjuncts[index]);

		if (bf->sat_list[check_negation] != 0) {
			head->mark_literal[index] = false;
		}

		stored_literal = head->disjuncts[index];
		if (bf->sat_list[stored_literal] == 0) {
			continue;
		}
		has_match = true;
	}
	return has_match;
}

/**
* negate_literal:
*
* Given a value returns the negation of it. Eg. the negation of a is A.
*
* @param lit the literal to negate.
* @return a negated literal.
*
*/

int negate_literal(const int lit)
{
	return isupper(lit) ? tolower(lit) : toupper(lit);
}

#pragma clang diagnostic pop

/**
 * author:     snowcrash.
 * date:       february 1 2019.
 */

#ifndef INC_3SAT_3649_VERIFY_SAT_H
#define INC_3SAT_3649_VERIFY_SAT_H

#include <limits.h>
#include <ctype.h>
#include "../lib/build_formula.h"
#include "../lib/parse_literals.h"

#define _LITERAL_SATISFIED  1   /* if there was a matching literal */
#define _LITERAL_REMOVED    0   /* if a literal was removed */

int negate_literal (int lit);

int check_sat (FORMULA *bf, CNF *head);

int set_sat (int optimal_literal, CNF *head, FORMULA *boolean_data);

void add_optimal_to_sat (int literal_to_store, CNF *head, FORMULA *bf);

void negate_marked_literal (FORMULA *bf, int optimal_literal);

int get_optimal_literal (FORMULA *bf, CNF *head);

int track_matching (CNF *head, FORMULA *boolean_data);

#endif

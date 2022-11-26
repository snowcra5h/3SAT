/**
 * Author:     snowcrash.
 * Date:       February 1 2019.
 */

#ifndef INC_3SAT_3649_STORE_CLAUSE_H
#define INC_3SAT_3649_STORE_CLAUSE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../lib/parse_literals.h"
#include "../lib/build_formula.h"

#define __CURRENT_EOF   EOF   /* the value of this can be changed from EOF to 'ascii' for testing */
#define __IN_CLAUSE     '('    /* __IN_CLAUSE is the first value to expect when going into an expression. */
#define __OUT_CLAUSE    ')'    /* __OUT_CLAUSE is the last value to expect to validate an expression. */

void add_clause (void *clause, FORMULA *bf);

int in_clause (void *clause);

int validate_clause (void *clause);

#endif

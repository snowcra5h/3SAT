
/**
 * Author:     snowcrash 
 * Date:       February 1 2019.
 */

#ifndef INC_3SAT_3649_PARSE_LITERALS_H
#define INC_3SAT_3649_PARSE_LITERALS_H

#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <errno.h>

#define __OR_OF_N_LITERALS 3   /* max number of terms (disjuncts) in conjunct. */
#define __DISJUNCT_SYMBOL '+'  /* the symbol used for a disjunction */
#define __NEGATION_SYMBOL '\'' /* the symbol used for a negation */
#define __IO_ERROR  5          /* errno for stdin */

int build_clause (void *store_clause);

int check_negation (void);

int check_disjunction (void);

int eat_whitespace (void);

int get_literal (void);

#endif

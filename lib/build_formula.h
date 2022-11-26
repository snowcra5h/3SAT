/**
 * Author:     snowcrash.
 * Date:       February 1 2019.
 */

#ifndef INC_3SAT_3649_DISJUNCTS_H
#define INC_3SAT_3649_DISJUNCTS_H

#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define _NO_CUR_LITERAL -1  /* if there is no current literal to be tracked */
#define _MAX_LITERALS_ 3    /* max number of terms in each conjunct */
#define __ASCII 127         /* letters in the alphabet */

extern int errno;

typedef struct Conjunct_Container
{
	struct Conjunct_Container *next;
	struct Conjunct_Container *prev;
	
	char disjuncts[_MAX_LITERALS_];    /* each conjunct is made up of 3 disjuncted literals */
	int  mark_literal[_MAX_LITERALS_]; /* initialized to -1 marked true if this node chose a literal, marked false
										* if a negation of the current disjunct was satisfied already. */
} CNF;

typedef struct
{
	struct Conjunct_Container *first; /* the first conjunct */
	struct Conjunct_Container *last;  /* the last conjunct */
	
	int n_stored_literal[__ASCII];   /* tracks the number of times literals show up in disjuncts */
	int sat_list[__ASCII];           /* literal values that satisfy truth in the boolean formula */
} FORMULA;

void store_new_conjunct (void *literals, FORMULA *bf);

void add_conjunct (FORMULA *p_formula, CNF *p_conjunct);

void add_validated_literals (CNF *new_conjunct, void *literals, FORMULA *track_literals);

void destroy_list (FORMULA *p_formula);

CNF *init_data (void);

#endif

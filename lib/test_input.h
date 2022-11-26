/**
 * author:     snowcrash.
 * date:       february 1 2019.
 */

#ifndef INC_3SAT_3649_TEST_INPUT_H
#define INC_3SAT_3649_TEST_INPUT_H

#define FAIL_SIZE (sizeof (fail_tests) / sizeof (fail_tests[0]))      /* NUMBER OF ELEMENTS IN FAIL */
#define PASS_SIZE (sizeof (pass_tests) / sizeof (pass_tests[0]))      /* NUMBER OF ELEMENTS IN PASS */

static char *fail_tests[] =
		            {
				            "(x + y)",
				
				            "(a+b+c)(l+m+n+o)(x+y+z)",
				
				            "()",
				
				            "(+x+y+z)",
				
				            "(x+y+z+)",
				
				            "(a+b'+c)[x+y+z](a'+b+c')",
				
				            "('x+y+z)",
				
				            "(aa + bb + cc)",
				
				            "(x + Y + z)",
				
				            "(x + y * z)",
				
				            "(x + y'' + z)",
				
				            "(x' + y'' + 'z')",
				
				            "(x + y * z)",
				
				            "(x + y'' + z)",
				
				            "(p+q+r) * (p'+q'+r')",
				
				            "(",
				
				            "...",
				
				            "(x+y+z.).",
				
				            "(p + (q + r + s) + t)",
				
				            "(a+b+c)(d+e++f)(g+h+i)",
				
				            "((m+n+o))",
				
				            "(m+n+o)(p+q+r))"
		            };

static char *pass_tests[] =
		            {
				            "(a' + m + z') (a' + m' + z ')",
				
				            "(a + b + c) ( a' + b' + c)",
				
				            "(a+b+c)(a+b+c')(a+b'+c)(a+b'+c')(a'+b+c)(a'+b+c')(a'+b'+c)(a'+b'+c')",
				
				            "(a+b+c)(a+b+c')(a+b'+c')(a'+b+c)(a'+b+c')(a'+b'+c)(a'+b'+c')",
				
				            "( c' + d + j)( f + h' + g')( f + g' + c')( i + b' + a')( i' + a + j')(\n"
				            "i' + c' + f)( f + a' + h')( j + j + e')( i + c + f)( i' + c + f)( e' + f\n"
				            "+ h')( h' + b + c')( d' + e' + e)( j + a' + g)( j' + a' + g')( f' +\n"
				            "d' + b')( b' + g' + d')( b + i + j')( e' + a + h')( h' + g + c')( h +\n"
				            "f' + i')( h + e + e')( g' + c + h')( h' + g' + d')( d + c + j)( a' + a\n"
				            "+ e')( h' + b + g)( h + j + i')( a' + e + g)( h + c + b')( e + d + d)( e'\n"
				            "+ b' + f')( b + a + e')( i + a' + c')( i + g + b')( b' + b' + j')( f'\n"
				            "+ f + f')( c' + g + a)( j + e' + c')( j + c' + e)( g' + d' + j')",
				
				            "( c' + d + j)( c + f' + i)( f + h' + g')( f + g' + c')( i + b' + a')(\n"
				            "i' + a + j')( i' + c' + f)( f + a' + h')( j + j + e')( i + c + f)( i' +\n"
				            "c + f)( e' + f + h')( h' + b + c')( d' + e' + e)( j + a' + g)( j' + a'\n"
				            "+ g')( f' + d' + b')( b' + g' + d')( b + i + j')( e' + a + h')( h' +\n"
				            "g + c')( h + f' + i')( h + e + e')( g' + c + h')( h' + g' + d')( d + c\n"
				            "+ j)( a' + a + e')( h' + b + g)( h + j + i')( a' + e + g)( h + c + b')( e\n"
				            "+ d + d)( e' + b' + f')( b + a + e')( i + a' + c')( i + g + b')( b' +\n"
				            "b' + j')( f' + f + f')( c' + g + a)( j + e' + c')( j + c' + e)( g' +\n"
				            "d' + j')",
				
				            "( x + q + m')( l' + l' + g)( d' + q' + q)( i + f' + j')( q' + a + v')(\n"
				            "f' + f + f)( d' + k + a')( y + m' + s)( t + r' + k')( b' + m + z')( w +\n"
				            "o + r)( u + t + j')( c + c + h')( q + x' + e)( l' + z' + w')( g' + b' +\n"
				            "r)( e + g' + j')( p + j + x)( x' + e' + j)( f + z + v)( k' + o' + o)( s +\n"
				            "j + a')( x' + y + q')( i' + q' + n')( d + m' + a')( l' + h + m')( g +\n"
				            "j' + h)( y' + r' + r')( t + t' + j)( l + b' + t)( g + d + o')( y + l +\n"
				            "y')( t + n + q')( r + e + c')( w' + q + s')( e + l + e')( w + t' + r')(\n"
				            "r + v' + j)( j + d' + t)( u + v + q')( n' + q + g')( i + s + b)( a' + g +\n"
				            "h')( s' + o + r')( x + a + k')( s' + f + c)( x' + d' + g')( i + r +\n"
				            "r')( n + d + h)( p + e' + l)( x + z + a')( c + l + q')( k' + j' + c')( s\n"
				            "+ e + r')( n + g + j)( l' + l + b')( v' + a' + r)( a + p + h)( i' + k' +\n"
				            "w')( a' + p + g)( p + x + q)( k + l + w')( p' + a' + p)( k + c' + h)( f +\n"
				            "e + z')( n' + c' + o)( l' + e' + g')( g + g' + y)( k + w + n')( m' +\n"
				            "f' + a)( u + a + m)( c' + y' + y)( u' + d' + l)( z + s' + b)( b + q +\n"
				            "f')( j' + l' + r')( o + a' + k')( w' + v + w)"
		            };

void test_3cnf (int test_number);

void test_fail_stdin (int test_number);

void test_pass_stdin (int test_number);

#endif

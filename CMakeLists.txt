cmake_minimum_required(VERSION 3.13)
project(3SAT_3649 C)

set(CMAKE_C_STANDARD 99)

add_executable(
        src/build_formula.c
        lib/build_formula.h
        src/parse_literals.c
        lib/parse_literals.h
        src/build_3cnf.c
        lib/build_3cnf.h
        src/solve_sat.c
        src/verify_sat.c
        lib/verify_sat.h lib/solve_sat.h)
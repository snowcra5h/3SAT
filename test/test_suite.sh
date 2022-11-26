#!/usr/bin/env bash

B='\033[0;34m'
LB='\033[1;35m'
CYAN='\033[0;36m'
NC='\033[0m'
BYellow='\033[1;33m'
IPurple='\033[0;95m'

clear
gcc -o test_stdin generate_test.c

echo -e "${CYAN}The number of tests that can be loaded are ${IPurple}: ${NC}"
./test_stdin

echo -n -e "${CYAN}Enter the number of tests to run${IPurple}: ${NC}"
read -r n_tests

echo -n -e "${CYAN}Enter the type of test to run ${IPurple}(${BYellow}fail\pass${IPurple})${NC}?${IPurple}: ${NC}"
read -r test_type

sh generate_tests.sh $test_type $n_tests

#!EOF

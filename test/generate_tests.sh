#!/usr/bin/env bash

B='\033[0;34m'
LB='\033[1;35m'
CYAN='\033[0;36m'
NC='\033[0m'
BYellow='\033[1;33m'
IPurple='\033[0;95m'

clear
if [[ "$#" -lt 2 ]]
then
        echo -e "${BYellow}usage${NC}: ${CYAN}sh $0 pass 4 ${NC}"
        exit 1
fi

for (( i=1; i<=$2; i++ ))
do
        echo -e -n "${CYAN}${i})${NC} ${B}${LB}(${NC}test type${BYellow} : ${CYAN}${1}${LB})${NC}"
        echo -e -n "${BYellow} - ${IPurple}" && ./test_stdin -t "${1}" -n "${i}"
        echo -e -n "${BYellow} - ${IPurple}" && ./test_stdin -t "${1}" -n "${i}" | ../cmake-build-debug/./3SAT_3649
        echo -e -n "${NC}"
done
rm test_stdin
#!EOF
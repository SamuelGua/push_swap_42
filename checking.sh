#!/bin/bash
RED='\033[0;31m'
GREEN='\033[0;32m'
BOLD='\033[1m'
RESET='\033[0m'

clear
make

echo "${GREEN}${BOLD}1 => BON${RESET}"
./push_swap 1 3 5 +9 20 -4 50 60 04 08 | wc -l
echo "${GREEN}${BOLD}2 => BON${RESET}"
./push_swap "3 4 6 8 9 74 -56 +495"
echo "${RED}${BOLD}3 => MAUVAISE lettre${RESET}"
./push_swap 1 3 dog 35 80 -3 | wc -l
echo "${RED}${BOLD}4 => MAUVAISE lettre${RESET}"
./push_swap a
echo "${RED}${BOLD}5 => MAUVAISE lettre${RESET}"
./push_swap 1 2 3 5 67b778 947
echo "${RED}${BOLD}6 => MAUVAISE lettre${RESET}"
./push_swap " 12 4 6 8 54fhd 4354"
echo "${RED}${BOLD}7 => MAUVAISE  --${RESET}"
./push_swap 1 --    45 32
echo "${RED}${BOLD}10 => MAUVAISE doublon${RESET}"
./push_swap 1 3 58 9 3
echo "${GREEN}${BOLD}9 => BON${RESET}"
./push_swap 3 | wc -l
echo "${RED}${BOLD}10 => MAUVAISE doublon${RESET}"
./push_swap " 49 128     50 38   49"
echo "${GREEN}${BOLD}11 => BON${RESET}"
./push_swap "95 99 -9 10 9" | wc -l
echo "${GREEN}${BOLD}12 => BON${RESET}"
./push_swap 2147483647 2 4 7 | wc -l
echo "${GREEN}${BOLD}13 => BON${RESET}"
./push_swap 99 -2147483648 23 545 | wc -l
echo "${RED}${BOLD}14 => MAUVAISE pas dans les int${RESET}"
./push_swap "2147483647 843 56544 24394"
echo "${RED}${BOLD}15 => MAUVAISE pas dans les int${RESET}"
./push_swap 54867543867438 3
echo "${RED}${BOLD}16 => MAUVAISE pas dans les int${RESET}"
./push_swap -2147483647765 4 5
echo "${RED}${BOLD}17 => MAUVAISE pas dans les int${RESET}"
./push_swap "214748364748385 28 47 29"
echo "${RED}${BOLD}18 => MAUVAISE initialisation de la liste${RESET}"
./push_swap "1 2 4 3" 76 90 "348 05"
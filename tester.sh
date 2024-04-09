#!/bin/bash

PINK='\033[35m'
GREEN='\033[32m'
RED='\033[31m'
RESET='\033[0m'

make re

echo -e "${PINK}test 0 - No file:${RESET}"
./so_long

echo ""
echo -e "${PINK}test 1 - Wrong extension map:${RESET}"
./so_long maps/error/map.bera

echo ""
echo -e "${PINK}test 2 - Wrong extension map:${RESET}"
./so_long maps/error/map.be

echo ""
echo -e "${PINK}test 3 - Wrong extension map:${RESET}"
./so_long maps/error/mapber

echo ""
echo -e "${PINK}test 4 - Invalid wall:${RESET}"
./so_long maps/error/map_invalid_wall1.ber

echo ""
echo -e "${PINK}test 5 - Invalid wall:${RESET}"
./so_long maps/error/map_invalid_wall2.ber

echo ""
echo -e "${PINK}test 6 - Invalid wall:${RESET}"
./so_long maps/error/map_invalid_wall3.ber

echo ""
echo -e "${PINK}test 7 - Invalid wall:${RESET}"
./so_long maps/error/map_invalid_wall4.ber

echo ""
echo -e "${PINK}test 8 - Invalid wall:${RESET}"
./so_long maps/error/map_invalid_wall5.ber

echo ""
echo -e "${PINK}test 9 - Invalid wall:${RESET}"
./so_long maps/error/map_invalid_wall6.ber

echo ""
echo -e "${PINK}test 10 - Invalid wall:${RESET}"
./so_long maps/error/map_invalid_wall7.ber

echo ""
echo -e "${PINK}test 11 - Invalid wall:${RESET}"
./so_long maps/error/map_invalid_wall8.ber

echo ""
echo -e "${PINK}test 12 - Invalid componet:${RESET}"
./so_long maps/error/map_invalid_component.ber

echo ""
echo -e "${PINK}test 13 - Invalid player:${RESET}"
./so_long maps/error/map_invalid_player.ber

echo ""
echo -e "${PINK}test 14 - Invalid player:${RESET}"
./so_long maps/error/map_invalid_player2.ber

echo ""
echo -e "${PINK}test 15 - Invalid exit:${RESET}"
./so_long maps/error/map_invalid_exit.ber

echo ""
echo -e "${PINK}test 16 - Invalid exit:${RESET}"
./so_long maps/error/map_invalid_exit2.ber

echo ""
echo -e "${PINK}test 15 - Invalid colectable:${RESET}"
./so_long maps/error/map_invalid_colectable.ber

echo ""
echo -e "${PINK}test x - Good map:${RESET}"
output=$(./so_long maps/map1.ber)
if [ -z "$output" ]; then
	echo -e "${GREEN}OK${RESET}"
else
	echo -e "${RED}KO${RESET}"
fi

make fclean

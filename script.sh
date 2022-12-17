#!/bin/bash

# Continous loop until game ends
while true; do

    #Places for y (x,y)
    columnMove=$((RANDOM % 3 + 1))

    #Places for x (x,y)
    rowMove=$((RANDOM % 3 + 1))
    

    #Makes overall move on board
    makeMove $rowMove $columnMove

done
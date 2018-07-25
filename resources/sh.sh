#!/bin/bash

MAX=5
for X in $(seq 1 $MAX) ; do
        ./filler_vm -f maps/map03 -p2 ../dbauduin.filler -p1 players/abanlin.filler
done

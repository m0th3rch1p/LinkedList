#!/bin/bash
gcc ./DataStructures/Node.c -c Node.o
gcc ./DataStructures/LinkedList.c -c LinkedList.o
gcc ./DataStructures/Node.o ./DataStructures/LinkedList.o ./DataStructures/test.c -o test.sh
echo "Done!"

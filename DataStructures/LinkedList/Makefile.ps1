gcc -c linkedlist.c -o linkedlist.o
gcc -c main.c -o main.o
gcc main.o linkedlist.o -o main
./main
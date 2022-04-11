gcc -c tree.c -o tree.o
gcc -c main.c -o main.o
gcc main.o tree.o -o main
./main
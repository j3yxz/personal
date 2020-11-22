cflags=-std=gnu99 -Wpedantic -Wall -g -Dbenchmark
#add -Dmergesort_on_array to cflags to let the compile the part
#wich will execute a standard mergeSort on the array to confront times
#usually this will be really more slower then the others
all: out.a

out.a: main.o mergesort_linked_list.o el.o
	gcc -o a.out ${cflags} main.o mergesort_linked_list.o el.o

main.o: main.c el.h mergesort_linked_list.h
	gcc -c main.c ${cflags}

el.o: el.c
	gcc -c el.c ${cflags}

mergesort_linked_list.o: mergesort_linked_list.c
	gcc -c mergesort_linked_list.c ${cflags}


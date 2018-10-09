all: wordcount

wordcount: problem3.o
	gcc problem3.o -o wordcount
problem3.o: problem3.c
	gcc -c problem3.c
clean:
	-rm -f problem3.o

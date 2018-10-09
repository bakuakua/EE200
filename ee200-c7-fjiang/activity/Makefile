all: log summarize

log: problem1.o
	gcc problem1.o -o log
problem1.o: problem1.c
	gcc -c problem1.c
summarize: problem2.o
	gcc problem2.o -o summarize
problem2.o: problem2.c
	gcc -c problem2.c
clean:
	-rm -f problem1.o
	-rm -f problem2.o


all: main_s main_d

main_s: main.o part.o
	gcc main.o part.o -o main_s

main_d: main.o libpart.o
	gcc main.o -L. -lpart -o main_d

libpart.so: part.o
	gcc --shared part.o -o libpart.so
main.o: main.c
	gcc -c main.c -o main.o

part.o: part.c
	gcc -c part.c -o part.o

clean:
	rm -f *.o *.so main_s main_d

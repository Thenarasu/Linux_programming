compile:ten.o add.o sub.o mod.o div.o mul.o
	gcc ten.o add.o sub.o mod.o div.o mul.o -o compile
ten.o:ten.c make.h
	gcc -c ten.c
add.o:add.c make.h
	gcc -c add.c
sub.o:sub.c make.h
	gcc -c sub.c
mod.o:mod.c make.h
	gcc -c mod.c
div.o:div.c make.h
	gcc -c div.c
mul.o:mul.c make.h
	gcc -c mul.c
.PHONY:clean
clean:
	rm *.o compile

calc.out : main.o addition.o subtraction.o multiplication.o division.o digit_to_list.o list_utils.o
	gcc -o calc.out main.o addition.o subtraction.o multiplication.o division.o digit_to_list.o list_utils.o

main.o : main.c apc.h
	gcc -c main.c -o main.o

addition.o : addition.c apc.h
	gcc -c addition.c -o addition.o

subtraction.o : subtraction.c apc.h
	gcc -c subtraction.c -o subtraction.o

multiplication.o : multiplication.c apc.h
	gcc -c multiplication.c -o multiplication.o

division.o : division.c apc.h
	gcc -c division.c -o division.o

digit_to_list.o : digit_to_list.c apc.h
	gcc -c digit_to_list.c -o digit_to_list.o

list_utils.o : list_utils.c apc.h
	gcc -c list_utils.c -o list_utils.o

clean :
	rm -f *.o calc.out

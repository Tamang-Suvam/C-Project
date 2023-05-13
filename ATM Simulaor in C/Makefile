#project Makefile
	
	TARGET=mini_atm
	DEP=atm_fun.o atm_prog.o

$(TARGET):$(DEP)
	gcc -o $(TARGET) $(DEP)
	rm ./Bin/*.o
	mv ./*.o ./Bin

atm_fun.o:./Source/atm_fun.c ./Source/atm_header.h
	gcc -c ./Source/atm_fun.c

atm_prog.o:./Source/atm_prog.c ./Source/atm_header.h
	gcc -c ./Source/atm_prog.c

CC=gcc
STD=-std=gnu99
BIN=kaishi.bin
FLAG=-Wall -Werror -DDEBUG
OBJ=main.o xiaogn.o zhuti.o teacher.o student.o principal.o

all:$(OBJ)
	$(CC) $(STD) -o $(BIN) $(OBJ)
main.o:main.c xiaogn.h
	$(CC) $(STD) $(FLAG) -c main.c
xiaogn.o:xiaogn.c xiaogn.h zhuti.h student.h teacher.h principal.h
	$(CC) $(STD) $(FLAG) -c xiaogn.c
zhuti.o:zhuti.c zhuti.h xiaogn.h
	$(CC) $(STD) $(FLAG) -c zhuti.c
student.o:student.c student.h zhuti.h xiaogn.h
	$(CC) $(STD) $(FLAG) -c student.c
teacher.o:teacher.c teacher.h zhuti.h xiaogn.h
	$(CC) $(STD) $(FLAG) -c teacher.c
principal.o:principal.c principal.h zhuti.h xiaogn.h
	$(CC) $(STD) $(FLAG) -c principal.c
clean:
	rm -rf $(OBJ) $(BIN)

#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa main
# Autor		: Cecília Junqueira V. M. Pereira (ceciliajunq@ufmg.br), baseado no Makefile do prof. Wagner Meira Jr. (meira@dcc.ufmg.br)
# Histórico	: 2023-10-03 - arquivo criado
#---------------------------------------------------------------------
# Opções	: make all - compila tudo e executa exemplo
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/lista.o $(OBJ)/satisfabilidade.o $(OBJ)/avaliacao.o $(OBJ)/tipo_item.o $(OBJ)/item_arvore.o
HDRS = $(INC)/lista.h $(INC)/satisfabilidade.h $(INC)/avaliacao.h $(INC)/tipo_item.h $(INC)/item_arvore.h
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/tp1.out

all:  $(EXE)
#	$(EXE) -s "( ~ ( 1 | ~ ( -1 | 0 ) ) & 2 )" 01e
	$(EXE) -a "( 4 & ( 3 | ( ( 1 & ~ 0 ) | 2 ) ) )" 10001
	$(EXE) -a "~ ( ( ~ ( 0 | 1 ) & 2 ) & 3 )" 1000

	$(EXE) -a " 0 | 1 " 10
	$(EXE) -a " 0 | 1 & 2 " 010
	$(EXE) -a " 1 & ~ 2 | ( 1 & 0 )" 001
	$(EXE) -a " ~ ( 0 | 1 ) & 2 " 001
	$(EXE) -a " ~ ( 2 | 0 & 1 ) & ( 3 | 1 ) | ~ 1 " 0111
	$(EXE) -a " 0 | 1 & 2 " 100
	$(EXE) -a " ~ 0 | ~ ( 1 & 2 ) " 100
	$(EXE) -a " 0 | 1 & 2 & 3 | 4 | 5 & ~ 6 & 7 | 8 | ~ 9 & 10 | 11 " 100100111010
	$(EXE) -s " 0 | 1 & 2 " 0e0
	$(EXE) -s " 0 | 1 & 2 " e00
	$(EXE) -s " 0 | 1 & 2 " e11
	$(EXE) -s " 0 | 1 & 2 " a00
	$(EXE) -s " 0 | 1 & 2 " 0a0
	$(EXE) -s " 0 | 1 & 2 " a11
	$(EXE) -s " 0 | 1 & 2 " ae1
	$(EXE) -a " 1 | 2 & ~ ( ~ ~ 3 | 0 ) " 0110
	$(EXE) -a " ( 2 | ~ 0 ) & ~ ( 1 | 2 & ( ~ 3 & ~ 2 ) & 1 | 2 ) " 0010
	$(EXE) -a " 1 & ( ~ 0 | 2 & ( ~ 1 | 0 & ~ 2 ) & 0 | 1 ) " 011
	$(EXE) -a " 1 & ~ ( ~ 0 | 2 & ( ~ 1 | 0 & ~ 2 ) & 0 | 1 ) " 011

	$(EXE) -s "( 43 & ( 16 | ~ ( 45 & ( ~ ~ ( ( ( ( ( 30 | ( 18 | ( 25 & ( 31 | ( 10 & ( 26 | ( 42 | ~ ( 41 | ~ ( ( 7 | ( ( 39 | ( ~ ( 3 | ( ( ~ ~ ( 37 & ( 29 & ( ( ~ ( 14 & ( ( ( 16 | ( 32 & ( ~ ( ( ( 33 & ( ( 17 | ( ( ( 31 | ( 30 | ~ ( 21 & ( 0 | ( 18 | ~ ~ ( 26 & ( ( ( ( 16 | ~ ( ( ( ( ( ( ( ( 23 & ~ ( 22 | ( 21 & ( 20 | ( ( ( ( 18 & ( ~ ( 16 | ( ( 14 & ( ( ( ( 10 & ( 9 | ( ( ( ( 5 & ( 0 & ( ( ( 2 | ( 1 | 0 ) ) | 3 ) | 4 ) ) ) & 6 ) | 7 ) | 8 ) ) ) | 11 ) | 12 ) & 13 ) ) | 15 ) ) & 17 ) ) | 0 ) | 8 ) | 19 ) ) ) ) ) & 24 ) | 25 ) & 26 ) | 3 ) & 8 ) & 27 ) & 7 ) ) & 28 ) & 29 ) | 14 ) ) ) ) ) ) ) & 14 ) | 32 ) ) & 13 ) ) & 0 ) | 4 ) | 24 ) ) ) & 34 ) | 35 ) ) | 36 ) & 27 ) ) ) | 38 ) | 37 ) ) & 3 ) ) & 37 ) ) | 40 ) ) ) ) ) ) ) ) ) | 36 ) | 8 ) & 26 ) & 43 ) & 44 ) ) ) )" 011100001111110110100101110100a101100100110000

$(BIN)/tp1.out: $(OBJS)
	$(CC) -g -o $(BIN)/tp1.out $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 

$(OBJ)/lista.o: $(HDRS) $(SRC)/lista.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/lista.o $(SRC)/lista.cpp 

$(OBJ)/satisfabilidade.o: $(HDRS) $(SRC)/satisfabilidade.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/satisfabilidade.o $(SRC)/satisfabilidade.cpp 

$(OBJ)/avaliacao.o: $(HDRS) $(SRC)/avaliacao.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/avaliacao.o $(SRC)/avaliacao.cpp 

$(OBJ)/tipo_item.o: $(HDRS) $(SRC)/tipo_item.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/tipo_item.o $(SRC)/tipo_item.cpp 

$(OBJ)/item_arvore.o: $(HDRS) $(SRC)/item_arvore.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/item_arvore.o $(SRC)/item_arvore.cpp 
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
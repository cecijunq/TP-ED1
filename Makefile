#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa main
# Autor		: Wagner Meira Jr. (meira@dcc.ufmg.br)
# Histórico	: 2022-04-02 - arquivo criado
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
OBJS = $(OBJ)/main.o $(OBJ)/lista.o $(OBJ)/pilha.o $(OBJ)/avaliacao.o $(OBJ)/tipo_item.o $(OBJ)/item_pilha.o
HDRS = $(INC)/lista.h $(INC)/pilha.h $(INC)/avaliacao.h $(INC)/tipo_item.h $(INC)/item_pilha.h
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/main

all:  $(EXE)
	$(EXE) "~ ( 0 | 1 ) & 2" 101

$(BIN)/main: $(OBJS)
	$(CC) -g -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 

$(OBJ)/lista.o: $(HDRS) $(SRC)/lista.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/lista.o $(SRC)/lista.cpp 

$(OBJ)/pilha.o: $(HDRS) $(SRC)/pilha.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/pilha.o $(SRC)/pilha.cpp 

$(OBJ)/avaliacao.o: $(HDRS) $(SRC)/avaliacao.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/avaliacao.o $(SRC)/avaliacao.cpp 

$(OBJ)/tipo_item.o: $(HDRS) $(SRC)/tipo_item.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/tipo_item.o $(SRC)/tipo_item.cpp 

$(OBJ)/item_pilha.o: $(HDRS) $(SRC)/item_pilha.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/item_pilha.o $(SRC)/item_pilha.cpp 
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
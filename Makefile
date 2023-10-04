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
	$(EXE) -a " 0 | 1 " 10
	$(EXE) -a " 0 | 1 & 2 " 010
	$(EXE) -a " ~ ( 0 | 1 ) & 2 " 001
	$(EXE) -a " 1 & ~ 2 | ( 1 & 0 )" 001
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
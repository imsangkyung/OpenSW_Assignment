
PROJ_DIR=$(shell pwd)
BIN_DIR=$(PROJ_DIR)/bin
INC_DIR=$(PROJ_DIR)/include
OBJ_DIR=$(PROJ_DIR)/obj
SRC_DIR=$(PROJ_DIR)/src
LIB_DIR=$(PROJ_DIR)/lib
CC= gcc
AR=ar

.PHONY: clean, basic, all



$(BIN_DIR)/myapp : $(OBJ_DIR)/add.o $(OBJ_DIR)/div.o $(OBJ_DIR)/mul.o $(OBJ_DIR)/sub.o $(OBJ_DIR)/myapp.o
	$(CC) $^ -o $@ 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ -I$(INC_DIR)


clean:
	rm -rf $(OBJ_DIR)/*.o 
	rm -f $(BIN_DIR)/myapp

basic:
	$(AR) rv $(LIB_DIR)/libmybasic.a $(OBJ_DIR)/add.o $(OBJ_DIR)/div.o $(OBJ_DIR)/mul.o $(OBJ_DIR)/sub.o
	
all:
	gcc $(OBJ_DIR)/myapp.o -o $(BIN_DIR)/myapp -L$(LIB_DIR) -lmybasic 






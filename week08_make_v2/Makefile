
PROJ_DIR=$(shell pwd)
BIN_DIR=$(PROJ_DIR)/bin
INC_DIR=$(PROJ_DIR)/include
OBJ_DIR=$(PROJ_DIR)/obj
SRC_DIR=$(PROJ_DIR)/src
LIB_DIR=$(PROJ_DIR)/lib
STATIC_LIBS=$(LIB_DIR)/libmybasic.a $(LIB_DIR)/libmyadvanced.a
CC= gcc
AR=ar

.PHONY: basic_ops advanced_ops all clean

all: basic_ops advanced_ops $(BIN_DIR)/myapp
$(BIN_DIR)/myapp: $(SRC_DIR)/myapp.c $(STATIC_LIBS)
	$(CC) $< -o $@ -L$(LIB_DIR) -lmybasic -lmyadvanced -I$(INC_DIR) -lm 

basic_ops:
	$(MAKE) -C basic_ops

advanced_ops:
	$(MAKE) -C advanced_ops

clean:
	rm -rf $(BIN_DIR)/* $(OBJ_DIR)/*
	$(MAKE) -C basic_ops clean
	$(MAKE) -C advanced_ops clean
















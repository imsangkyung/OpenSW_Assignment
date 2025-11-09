PROJ_DIR=$(shell pwd)
LIB_DIR=../lib
OBJ_DIR=$(PROJ_DIR)/obj
SRC_DIR=$(PROJ_DIR)/src
INC_DIR=../include

SRCS=$(wildcard $(SRC_DIR)/*.c)
OBJS = $(subst $(SRC_DIR), $(OBJ_DIR), $(SRCS:.c=.o))
CC=gcc
AR=ar

.PHONY: clean

$(LIB_DIR)/libmyadvanced.a: $(OBJS)
	$(AR) rv $@ $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ -I$(INC_DIR) 

clean:
	rm -rf $(OBJ_DIR)/*
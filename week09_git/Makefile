CC = clang
SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = lib
BIN_DIR = bin

LIB_OBJS = $(OBJ_DIR)/mysub.o \
           $(OBJ_DIR)/mymul.o \
           $(OBJ_DIR)/mydiv.o \
           $(OBJ_DIR)/myadd.o \
           $(OBJ_DIR)/mymod.o \
		   $(OBJ_DIR)/mypow.o

APP_OBJ = $(OBJ_DIR)/myapp.o

TARGET_APP = $(BIN_DIR)/myapp
TARGET_LIB = $(LIB_DIR)/libmyops.so.1.0

all: $(TARGET_APP)

$(TARGET_APP): $(APP_OBJ) $(TARGET_LIB)
	$(CC) -o $@ $(APP_OBJ) lib/libmyops.so.1.0 -rpath @executable_path/../$(LIB_DIR)

$(TARGET_LIB): $(LIB_OBJS)
	$(CC) -dynamiclib -o $@ $^ -install_name @rpath/libmyops.so.1.0

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -Wall -fPIC -c $< -o $@ -I./include

$(APP_OBJ): $(SRC_DIR)/myapp.c
	$(CC) -Wall -c $< -o $@ -I./include

clean:
	rm -f $(TARGET_APP) $(TARGET_LIB)
	rm -f $(LIB_OBJS) $(APP_OBJ)

.PHONY: all clean
APPNAME = nim
LIBNAME = libnim
TESTNAME = libnim-test

CC = gcc

CFLAGS = -Wall -Wextra -Werror
LFLAGS = -I src -MP -MMD

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src

APP_PATH = $(BIN_DIR)/$(APPNAME)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIBNAME)/$(LIBNAME).a

APP_SRC = $(shell find $(SRC_DIR)/$(APPNAME) -name '*.c')
APP_OBJ = $(APP_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/$(SRC_DIR)/%.o)

LIB_SRC = $(shell find $(SRC_DIR)/$(LIBNAME) -name '*.c')
LIB_OBJ = $(LIB_SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/$(SRC_DIR)/%.o)

DEPS = $(APP_OBJ:.o=.d) $(LIB_OBJ:.o=.d)

all: $(APP_PATH)

$(APP_PATH): $(APP_OBJ) $(LIB_PATH)
	$(CC) $(CFLAGS) $(LFLAGS) $^ -o $@

$(LIB_PATH): $(LIB_OBJ)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(LFLAGS) -c $< -o $@

clean:
	$(RM) $(APP_PATH) $(LIB_PATH)
	find $(OBJ_DIR) -name '*.o' -exec $(RM) '{}' \;
	find $(OBJ_DIR) -name '*.d' -exec $(RM) '{}' \;

-include $(DEPS)

.PHONY: all clean


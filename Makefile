
# Target
NAME		= intuition
# Variable
CC 			= gcc

# Dependencies
SRCS_DIR	= srcs
INCS_DIR	= includes
OBJS_DIR    = objs
BIN_DIR		= bin
LIBS_DIR	= libs

# Target 
TARGET		= $(BIN_DIR)/$(NAME)

# Flags
CFLAGS 		= -Wall -Wextra -Werror -g -std=c99
DFLAGS 		= -Wall -Wextra -Werror -g
IFLAGS 		= -I$(INCS_DIR)
MF			= Makefile

# .c
SOURCES = main.c game.c map.c map-init.c player.c input.c messages.c game-console.c \
		  map-utilities.c map-generation.c random.c mymath.c
 
# Files
SRCS = $(addprefix $(SRCS_DIR)/, $(SOURCES)) 
OBJS = $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

all: $(TARGET)

# Regla para compilar el juego
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ $^

# Regla para compilar los archivos fuente a objetos
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(MF)
	$(CC) $(CFLAGS) -c -o $@ $<
	
clean:
	@rm -vf $(OBJS)

fclean: clean
	@rm -vf $(TARGET)

re: clean fclean all

run: $(TARGET)
	./$(TARGET)
.PHONY: clean fclean re all run

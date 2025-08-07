## ========================================================================== ##
##                                                                            ##
##   Makefile                                                                 ##
##                                                       \_[UwU]_/            ##
##   By: Lili <linirby.contact@gmail.com>									  ##
##																			  ##
## ========================================================================== ##

NAME := lili_minesweeper

CC := cc
CFLAGS := -Wall -Wextra -Werror
SDL_CFLAGS := $(shell sdl2-config --cflags)
SDL_LIBS := $(shell sdl2-config --libs) -lSDL2_image

INCDIR := include
SRCDIR := src
OBJDIR := obj

SRC := \
$(SRCDIR)/core/main.c \
$(SRCDIR)/core/game_loop.c \
$(SRCDIR)/game/board.c \
$(SRCDIR)/game/logic.c \
$(SRCDIR)/ui/render.c \
$(SRCDIR)/ui/tileset.c \
$(SRCDIR)/ui/cursor.c \
$(SRCDIR)/ui/input.c

OBJ := $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

INC := -I$(INCDIR)

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(SDL_CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(SDL_LIBS) -o $(NAME)

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

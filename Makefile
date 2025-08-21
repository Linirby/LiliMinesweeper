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

WIN_CC := gcc
WIN_NAME := $(NAME).exe
WIN_OBJDIR := obj_win
WIN_OBJ := $(SRC:$(SRCDIR)/%.c=$(WIN_OBJDIR)/%.o)
WIN_CFLAGS := -Wall -Wextra -Werror
WIN_SDL_CFLAGS := $(shell pkg-config --cflags sdl2)
WIN_SDL_LIBS := $(shell pkg-config --libs sdl2) -lSDL2_image -lSDL2main

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(SDL_CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(SDL_LIBS) -o $(NAME)

windows: $(WIN_NAME)

$(WIN_OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(WIN_CC) $(WIN_CFLAGS) $(WIN_SDL_CFLAGS) $(INC) -c $< -o $@

$(WIN_NAME): $(WIN_OBJ)
	$(WIN_CC) $(WIN_CFLAGS) $(WIN_OBJ) $(WIN_SDL_LIBS) -o $(WIN_NAME)

clean:
	$(RM) -r $(OBJDIR)

clean-windows:
	$(RM) -r $(WIN_OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

re-windows: clean-windows windows

.PHONY: all clean fclean re windows clean-windows re-windows

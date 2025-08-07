// ========================================================================== //
//                                                                            //
//   game.h                                                                   //
//                                                       \_[UwU]_/            //
//   By: Lili <linirby.contact@gmail.com>									  //
//																			  //
// ========================================================================== //

#ifndef FT_GAME_H
# define FT_GAME_H

# include <SDL2/SDL.h>

# define TILESET_W 8
# define TILESET_H 8
# define TILESET_INDEX_INDICATOR 0
# define TILESET_INDEX_HIDDEN 1
# define TILESET_INDEX_EMPTY 2
# define TILESET_INDEX_NUM_BASE 3
# define TILESET_INDEX_FLAG 11
# define TILESET_INDEX_MINE 12

# define BOARD_W 16
# define BOARD_H 16
# define BOARD_MINES 40

# define SCALE 4

typedef struct	s_cell
{
    int	has_mine;
    int	revealed;
    int	flagged;
    int	adj;
}	t_cell;

typedef struct	s_board
{
    int		w;
    int		h;
    int		mines;
    t_cell	*cells;
}	t_board;

typedef struct	s_tileset
{
    SDL_Texture	*tex;
    int			tile_w;
    int			tile_h;
}	t_tileset;

typedef struct	s_cursor
{
    int	x;
    int	y;
}	t_cursor;

typedef struct	s_game
{
    SDL_Window		*win;
    SDL_Renderer	*ren;
    t_tileset		tiles;
    t_board			board;
    t_cursor		cursor;
    int				running;
    int				won;
    int				lost;
    int				screen_w;
    int				screen_h;
}	t_game;

#endif

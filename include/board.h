// ========================================================================== //
//                                                                            //
//   board.h                                                                  //
//                                                       \_[UwU]_/            //
//   By: Lili <linirby.contact@gmail.com>									  //
//																			  //
// ========================================================================== //

#ifndef FT_BOARD_H
# define FT_BOARD_H

# include <SDL2/SDL.h>
# include "game.h"

int		board_create(t_board *b, int w, int h, int mines);
void	board_free(t_board *b);
int		board_place_mines(t_board *b, int seed);
int		board_reveal_cell(t_board *b, int x, int y);
void	board_toggle_flag(t_board *b, int x, int y);

#endif

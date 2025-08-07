// ========================================================================== //
//                                                                            //
//   logic.h                                                                 //
//                                                       \_[UwU]_/            //
//   By: Lili <linirby.contact@gmail.com>									  //
//																			  //
// ========================================================================== //

#ifndef FT_LOGIC_H
# define FT_LOGIC_H

# include <SDL2/SDL.h>
# include "game.h"

void	logic_flood_reveal(t_board *b, int sx, int sy);
int		logic_check_victory(t_board *b);
void	logic_reveal_all_mines(t_board *b);

#endif

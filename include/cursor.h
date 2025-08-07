// ========================================================================== //
//                                                                            //
//   cursor.h                                                                 //
//                                                       \_[UwU]_/            //
//   By: Lili <linirby.contact@gmail.com>									  //
//																			  //
// ========================================================================== //

#ifndef FT_CURSOR_H
# define FT_CURSOR_H

# include <SDL2/SDL.h>
# include "game.h"

void	cursor_init(t_cursor *c);
void	cursor_move(t_cursor *c, int dx, int dy, int max_w, int max_h);

#endif

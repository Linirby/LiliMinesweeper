// ========================================================================== //
//                                                                            //
//   render.h                                                                 //
//                                                       \_[UwU]_/            //
//   By: Lili <linirby.contact@gmail.com>									  //
//																			  //
// ========================================================================== //

#ifndef FT_RENDER_H
# define FT_RENDER_H

# include <SDL2/SDL.h>
# include "game.h"

void	render_clear(t_game *g);
void	render_board(t_game *g);
void	render_present(t_game *g);

#endif

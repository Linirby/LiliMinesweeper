// ========================================================================== //
//                                                                            //
//   game_loop.h                                                              //
//                                                       \_[UwU]_/            //
//   By: Lili <linirby.contact@gmail.com>									  //
//																			  //
// ========================================================================== //

#ifndef FT_GAME_LOOP_H
# define FT_GAME_LOOP_H

# include <SDL2/SDL.h>
# include "game.h"

int		game_loop_init(t_game *g);
void	game_loop_run(t_game *g);
void	game_loop_destroy(t_game *g);

#endif

// ========================================================================== //
//                                                                            //
//   tileset.h                                                                //
//                                                       \_[UwU]_/            //
//   By: Lili <linirby.contact@gmail.com>									  //
//																			  //
// ========================================================================== //

#ifndef FT_TILESET_H
# define FT_TILESET_H

# include <SDL2/SDL.h>
# include "game.h"

int			tileset_load(t_game *g, const char *path);
SDL_Rect	tileset_src_rect(int index, int tile_w, int tile_h);

#endif

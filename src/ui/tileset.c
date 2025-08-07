// ========================================================================== //
//                                                                            //
//   tileset.c                                                                //
//                                                       \_[UwU]_/            //
//   By: Lili <linirby.contact@gmail.com>									  //
//																			  //
// ========================================================================== //

#include "tileset.h"
#include <SDL2/SDL_image.h>

int	tileset_load(t_game *g, const char *path)
{
	SDL_Surface	*s;

	s = IMG_Load(path);
	if (!s)
		return (0);
	g->tiles.tex = SDL_CreateTextureFromSurface(g->ren, s);
	SDL_FreeSurface(s);
	if (!g->tiles.tex)
		return (0);
	return (1);
}

SDL_Rect	tileset_src_rect(int index, int tile_w, int tile_h)
{
	SDL_Rect	r;

	r.x = index * tile_w;
	r.y = 0;
	r.w = tile_w;
	r.h = tile_h;
	return (r);
}

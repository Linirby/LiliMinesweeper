// ========================================================================== //
//                                                                            //
//   render.c                                                                 //
//                                                       \_[UwU]_/            //
//   By: Lili <linirby.contact@gmail.com>									  //
//																			  //
// ========================================================================== //

#include "render.h"
#include "tileset.h"

static void	render_cell(SDL_Renderer *ren, t_tileset *ts, t_cell *c, int sx, int sy)
{
	SDL_Rect	src;
	SDL_Rect	dst;
	int			index;

	dst.x = sx;
	dst.y = sy;
	dst.w = ts->tile_w * SCALE;
	dst.h = ts->tile_h * SCALE;
	if (!c->revealed)
	{
		index = TILESET_INDEX_HIDDEN;
		if (c->flagged)
			index = TILESET_INDEX_FLAG;
	}
	else
	{
		if (c->has_mine)
			index = TILESET_INDEX_MINE;
		else if (c->adj == 0)
			index = TILESET_INDEX_EMPTY;
		else
			index = TILESET_INDEX_NUM_BASE + c->adj - 1;
	}
	src = tileset_src_rect(index, ts->tile_w, ts->tile_h);
	SDL_RenderCopy(ren, ts->tex, &src, &dst);
}

void	render_clear(t_game *g)
{
	SDL_SetRenderDrawColor(g->ren, 0, 0, 0, 255);
	SDL_RenderClear(g->ren);
}

void	render_board(t_game *g)
{
	int			x;
	int			y;
	SDL_Rect	src;
	SDL_Rect	dst;

	y = 0;
	while (y < g->board.h)
	{
		x = 0;
		while (x < g->board.w)
		{
			dst.x = x * g->tiles.tile_w * SCALE;
			dst.y = y * g->tiles.tile_h * SCALE;
			render_cell(g->ren, &g->tiles,
				&g->board.cells[y * g->board.w + x], dst.x, dst.y);
			if (x == g->cursor.x && y == g->cursor.y)
			{
				src = tileset_src_rect(TILESET_INDEX_INDICATOR,
					g->tiles.tile_w, g->tiles.tile_h);
				dst.w = g->tiles.tile_w * SCALE;
				dst.h = g->tiles.tile_h * SCALE;
				SDL_RenderCopy(g->ren, g->tiles.tex, &src, &dst);
			}
			x = x + 1;
		}
		y = y + 1;
	}
}

void	render_present(t_game *g)
{
	SDL_RenderPresent(g->ren);
}

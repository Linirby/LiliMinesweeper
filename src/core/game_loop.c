// ========================================================================== //
//                                                                            //
//   game_loop.c                                                              //
//                                                       \_[UwU]_/            //
//   By: Lili <linirby.contact@gmail.com>									  //
//																			  //
// ========================================================================== //

#include <time.h>
#include <stdlib.h>
#include "game.h"
#include "logic.h"
#include "board.h"
#include "tileset.h"
#include "cursor.h"
#include "input.h"
#include "render.h"

static void	game_apply_action(t_game *g, t_action *a)
{
	int x;
	int y;

	if (a->quit)
		g->running = 0;
	if (g->lost || g->won)
		return ;
	cursor_move(&g->cursor, a->move_x, a->move_y, g->board.w, g->board.h);
	x = g->cursor.x;
	y = g->cursor.y;
	if (a->flag)
		board_toggle_flag(&g->board, x, y);
	if (a->reveal)
	{
		if (board_reveal_cell(&g->board, x, y))
			g->lost = 1;
		if (!g->lost)
			g->won = logic_check_victory(&g->board);
	}
	if (g->lost)
		logic_reveal_all_mines(&g->board);
}

int	game_loop_init(t_game *g)
{
	int	ok;
	int	seed;

	g->win = NULL;
	g->ren = NULL;
	g->tiles.tex = NULL;
	g->running = 1;
	g->won = 0;
	g->lost = 0;
	ok = (SDL_Init(SDL_INIT_VIDEO) == 0);
	if (!ok)
		return (0);
	ok = board_create(&g->board, BOARD_W, BOARD_H, BOARD_MINES);
	if (!ok)
		return (0);
	seed = (int)time(NULL);
	board_place_mines(&g->board, seed);
	cursor_init(&g->cursor);
	g->screen_w = g->board.w * TILESET_W * SCALE;
	g->screen_h = g->board.h * TILESET_H * SCALE;
	g->win = SDL_CreateWindow("Minesweeper", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, g->screen_w, g->screen_h, 0);
	if (!g->win)
		return (0);
	g->ren = SDL_CreateRenderer(g->win, -1, SDL_RENDERER_ACCELERATED);
	if (!g->ren)
		return (0);
	g->tiles.tile_w = TILESET_W;
	g->tiles.tile_h = TILESET_H;
	ok = tileset_load(g, "assets/tiles.png");
	return (ok);
}

void	game_loop_run(t_game *g)
{
	t_action	a;
	int			quit;

	quit = 0;
	while (g->running && !quit)
	{
		a.move_x = 0;
		a.move_y = 0;
		a.reveal = 0;
		a.flag = 0;
		a.quit = 0;
		input_poll(&a);
		game_apply_action(g, &a);
		render_clear(g);
		render_board(g);
		render_present(g);
		if (!g->running)
			quit = 1;
	}
}

void	game_loop_destroy(t_game *g)
{
	if (g->tiles.tex)
		SDL_DestroyTexture(g->tiles.tex);
	if (g->ren)
		SDL_DestroyRenderer(g->ren);
	if (g->win)
		SDL_DestroyWindow(g->win);
	board_free(&g->board);
	SDL_Quit();
}

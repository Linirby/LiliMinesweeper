// ========================================================================== //
//                                                                            //
//   board.c                                                                  //
//                                                       \_[UwU]_/            //
//   By: Lili <linirby.contact@gmail.com>									  //
//																			  //
// ========================================================================== //

#include <stdlib.h>
#include "board.h"
#include "logic.h"

static int	board_idx(t_board *b, int x, int y)
{
	return (y * b->w + x);
}

static int	board_in_bounds(t_board *b, int x, int y)
{
	if (x < 0)
		return (0);
	if (y < 0)
		return (0);
	if (x >= b->w)
		return (0);
	if (y >= b->h)
		return (0);
	return (1);
}

int	board_create(t_board *b, int w, int h, int mines)
{
	int	i;
	int	size;

	b->w = w;
	b->h = h;
	b->mines = mines;
	size = w * h;
	b->cells = (t_cell *)malloc(sizeof(t_cell) * size);
	if (!b->cells)
		return (0);
	i = 0;
	while (i < size)
	{
		b->cells[i].has_mine = 0;
		b->cells[i].revealed = 0;
		b->cells[i].flagged = 0;
		b->cells[i].adj = 0;
		i = i + 1;
	}
	return (1);
}

void	board_free(t_board *b)
{
	if (b->cells)
		free(b->cells);
	b->cells = NULL;
}

static void	board_compute_adj(t_board *b)
{
	int	x;
	int	y;
	int	dx;
	int	dy;

	y = 0;
	while (y < b->h)
	{
		x = 0;
		while (x < b->w)
		{
			b->cells[board_idx(b, x, y)].adj = 0;
			dy = -1;
			while (dy <= 1)
			{
				dx = -1;
				while (dx <= 1)
				{
					if ((dx != 0 || dy != 0)
						&& board_in_bounds(b, x + dx, y + dy)
						&& b->cells[board_idx(b, x + dx, y + dy)].has_mine)
						b->cells[board_idx(b, x, y)].adj =
							b->cells[board_idx(b, x, y)].adj + 1;
					dx = dx + 1;
				}
				dy = dy + 1;
			}
			x = x + 1;
		}
		y = y + 1;
	}
}

int	board_place_mines(t_board *b, int seed)
{
	int	placed;
	int	size;
	int	pos;

	srand(seed);
	size = b->w * b->h;
	placed = 0;
	while (placed < b->mines)
	{
		pos = rand() % size;
		if (!b->cells[pos].has_mine)
		{
			b->cells[pos].has_mine = 1;
			placed = placed + 1;
		}
	}
	board_compute_adj(b);
	return (1);
}

int	board_reveal_cell(t_board *b, int x, int y)
{
	int	idx;

	if (!board_in_bounds(b, x, y))
		return (0);
	idx = board_idx(b, x, y);
	if (b->cells[idx].revealed)
		return (0);
	if (b->cells[idx].flagged)
		return (0);
	b->cells[idx].revealed = 1;
	if (b->cells[idx].has_mine)
		return (1);
	if (b->cells[idx].adj == 0)
		logic_flood_reveal(b, x, y);
	return (0);
}

void	board_toggle_flag(t_board *b, int x, int y)
{
	int	idx;

	if (!board_in_bounds(b, x, y))
		return ;
	idx = (y * b->w + x);
	if (b->cells[idx].revealed)
		return ;
	if (b->cells[idx].flagged)
		b->cells[idx].flagged = 0;
	else
		b->cells[idx].flagged = 1;
}

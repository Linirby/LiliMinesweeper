// ========================================================================== //
//                                                                            //
//   logic.c                                                                  //
//                                                       \_[UwU]_/            //
//   By: Lili <linirby.contact@gmail.com>									  //
//																			  //
// ========================================================================== //

#include <stdlib.h>
#include "logic.h"

static int	in_bounds(t_board *b, int x, int y)
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

void	logic_flood_reveal(t_board *b, int sx, int sy)
{
	int	*qx;
	int	*qy;
	int	head;
	int	tail;

	qx = (int *)malloc(sizeof(int) * b->w * b->h);
	qy = (int *)malloc(sizeof(int) * b->w * b->h);
	if (!qx || !qy)
		return ;
	head = 0;
	tail = 0;
	qx[tail] = sx;
	qy[tail] = sy;
	tail = tail + 1;
	while (head < tail)
	{
		int x;
		int y;
		int dx;
		int dy;

		x = qx[head];
		y = qy[head];
		head = head + 1;
		dy = -1;
		while (dy <= 1)
		{
			dx = -1;
			while (dx <= 1)
			{
				if ((dx != 0 || dy != 0) && in_bounds(b, x + dx, y + dy))
				{
					int i;

					i = (y + dy) * b->w + (x + dx);
					if (!b->cells[i].revealed && !b->cells[i].flagged
						&& !b->cells[i].has_mine)
					{
						b->cells[i].revealed = 1;
						if (b->cells[i].adj == 0)
						{
							qx[tail] = x + dx;
							qy[tail] = y + dy;
							tail = tail + 1;
						}
					}
				}
				dx = dx + 1;
			}
			dy = dy + 1;
		}
	}
	free(qx);
	free(qy);
}

int	logic_check_victory(t_board *b)
{
	int	i;
	int	size;

	i = 0;
	size = b->w * b->h;
	while (i < size)
	{
		if (!b->cells[i].has_mine && !b->cells[i].revealed)
			return (0);
		i = i + 1;
	}
	return (1);
}

void	logic_reveal_all_mines(t_board *b)
{
	int	i;
	int	size;

	i = 0;
	size = b->w * b->h;
	while (i < size)
	{
		if (b->cells[i].has_mine)
			b->cells[i].revealed = 1;
		i = i + 1;
	}
}

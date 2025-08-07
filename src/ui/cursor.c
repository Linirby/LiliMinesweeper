// ========================================================================== //
//                                                                            //
//   cursor.c                                                                 //
//                                                       \_[UwU]_/            //
//   By: Lili <linirby.contact@gmail.com>									  //
//																			  //
// ========================================================================== //

#include "cursor.h"

void	cursor_init(t_cursor *c)
{
    c->x = 0;
    c->y = 0;
}

void	cursor_move(t_cursor *c, int dx, int dy, int max_w, int max_h)
{
	int	nx;
	int	ny;

	nx = c->x + dx;
	ny = c->y + dy;
	if (nx < 0)
		nx = 0;
	if (ny < 0)
		ny = 0;
	if (nx >= max_w)
		nx = max_w - 1;
	if (ny >= max_h)
		ny = max_h - 1;
	c->x = nx;
	c->y = ny;
}

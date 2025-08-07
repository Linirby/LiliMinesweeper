// ========================================================================== //
//                                                                            //
//   main.c                                                                   //
//                                                       \_[UwU]_/            //
//   By: Lili <linirby.contact@gmail.com>									  //
//																			  //
// ========================================================================== //

#include <stdlib.h>
#include "game_loop.h"

int	main(void)
{
	t_game	g;
	int		ok;

	ok = game_loop_init(&g);
	if (ok)
	{
		game_loop_run(&g);
	}
	game_loop_destroy(&g);
	return (0);
}

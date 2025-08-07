// ========================================================================== //
//                                                                            //
//   input.c                                                                  //
//                                                       \_[UwU]_/            //
//   By: Lili <linirby.contact@gmail.com>									  //
//																			  //
// ========================================================================== //

#include <SDL2/SDL.h>
#include "input.h"

void	input_poll(t_action *a)
{
	SDL_Event	e;
	int			cont;

	cont = 1;
	while (cont)
	{
		if (!SDL_PollEvent(&e))
			cont = 0;
		else if (e.type == SDL_QUIT)
			a->quit = 1;
		else if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym == SDLK_ESCAPE)
				a->quit = 1;
			if (e.key.keysym.sym == SDLK_UP)
				a->move_y = -1;
			if (e.key.keysym.sym == SDLK_DOWN)
				a->move_y = 1;
			if (e.key.keysym.sym == SDLK_LEFT)
				a->move_x = -1;
			if (e.key.keysym.sym == SDLK_RIGHT)
				a->move_x = 1;
			if (e.key.keysym.sym == SDLK_d)
				a->reveal = 1;
			if (e.key.keysym.sym == SDLK_f)
				a->flag = 1;
		}
	}
}

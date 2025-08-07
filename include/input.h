// ========================================================================== //
//                                                                            //
//   input.h                                                                  //
//                                                       \_[UwU]_/            //
//   By: Lili <linirby.contact@gmail.com>									  //
//																			  //
// ========================================================================== //

#ifndef FT_INPUT_H
# define FT_INPUT_H

# include <SDL2/SDL.h>
# include "game.h"

typedef struct	s_action
{
    int	move_x;
    int	move_y;
    int	reveal;
    int	flag;
    int	quit;
}	t_action;

void	input_poll(t_action *a);

#endif

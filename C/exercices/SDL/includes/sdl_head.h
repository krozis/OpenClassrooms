#ifndef SDL_HEAD_H
# define SDL_HEAD_H

# include <stdio.h>
# include <stdlib.h>
# include <SDL2/SDL.h>
# include <unistd.h>

typedef enum	e_bool
{
	fALSE,
	TRUE
}				t_bool;

Uint32	SDL_test(void);

#endif
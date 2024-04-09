/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:08:27 by stelie            #+#    #+#             */
/*   Updated: 2021/11/23 09:48:30 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdl_head.h"

Uint32	SDL_test(void)
{
	SDL_Window		*window;
	SDL_Renderer	*rend;
	SDL_Rect		rect[50];
	size_t			i = 0;

	window = SDL_CreateWindow("Testbug", 100, 100, 640, 480, SDL_WINDOW_RESIZABLE);
	if (window == NULL)
	{
		fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
		SDL_DestroyWindow(window);
		return (EXIT_FAILURE);
	}
	SDL_Delay(2000);
	rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (rend == NULL)
	{
		fprintf(stderr, "Erreur SDL_CreateRenderer : %s", SDL_GetError());
		SDL_DestroyRenderer(rend);
		return (EXIT_FAILURE);
	}
	if (0 != SDL_SetRenderDrawColor(rend, 248, 255, 7, 50))
	{
		fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
		SDL_DestroyRenderer(rend);
		return (EXIT_FAILURE);
	}
	if (0 != SDL_RenderClear(rend))
	{
		fprintf(stderr, "Erreur SDL_SetRenderClear : %s", SDL_GetError());
		SDL_DestroyRenderer(rend);
		return (EXIT_FAILURE);
	}
	SDL_RenderPresent(rend);
	SDL_Delay(500);
	for (i = 0; i < 50; i++)
	{
		rect[i].w = 50;
		rect[i].h = 50;
		rect[i].x = 100 * (i % 5) + 50 * ((i / 5) % 2);
		rect[i].y = 50 * (i / 5);
	}
	SDL_RenderFillRects(rend, rect, 50);
	SDL_RenderPresent(rend);
	SDL_SetWindowTitle(window, "Pokebowl");
//	SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
	SDL_Delay(2000);
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(window);
	return (EXIT_SUCCESS);
}

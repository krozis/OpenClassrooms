/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:57:14 by stelie            #+#    #+#             */
/*   Updated: 2021/11/23 09:30:01 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdl_head.h"

int	main(void)
{
	if (0 != SDL_Init(SDL_INIT_VIDEO))
	{
		fprintf(stderr, "Error SDL_Init : %s\n", SDL_GetError());
		return (EXIT_FAILURE);
	}
	if (0 != SDL_test())
	{
		SDL_Quit();
		return (EXIT_FAILURE);
	}
	SDL_Quit();
	return (EXIT_SUCCESS);
}

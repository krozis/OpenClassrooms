/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:07:55 by stelie            #+#    #+#             */
/*   Updated: 2021/11/17 10:29:51 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pendu.h"

static t_bool	is_finished(char *str)
{
	while (*str)
	{
		if (*str == '*')
			return (FALSE);
		str++;
	}
	return (TRUE);
}

static void	fill_userword(char c, t_pendu *game)
{
	int	i;

	i = 0;
	while (game->to_find[i])
	{
		if (c == game->to_find[i])
			game->userword[i] = c;
		i++;
	}
}

void	init_userword(t_pendu *game)
{
	int	i;

	game->userword = ft_strdup(game->to_find);
	i = 0;
	while (game->to_find[i] != '\0')
	{
		game->userword[i] = '*';
		i++;
	}
	game->userword[i] = '\0';
}

static void	check_user_guess(t_pendu *game)
{
	char	c;
	int		i;
	t_bool	found;

	found = FALSE;
	c = getchar();
	if (c <= 'z' && c >= 'a')
		c -= 32;
	while (getchar() != '\n')
		;
	if (!ft_isincharset(c, game->to_find))
		game->count--;
	else
		fill_userword(c, game);
}

void	play_game(t_pendu *game)
{
	while (game->win == FALSE && game->count > 0)
	{
		system("clear");
		printf("Il vous reste %li tentative.\n", game->count);
		printf("%s\n\n", game->userword);
		display_pendu(game->count);
		check_user_guess(game);
		game->win = is_finished(game->userword);
	}
}

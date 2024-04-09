/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pendu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:50:00 by stelie            #+#    #+#             */
/*   Updated: 2021/11/17 10:29:26 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pendu.h"

static t_bool	replay(void)
{
	char	answer;

	while (1)
	{
		printf("Veux-tu rejouer? (O ou N)\n");
		if (scanf("%c", &answer) == 1)
		{
			if (answer == 'o' || answer == 'O')
				return (TRUE);
			else if (answer == 'n' || answer == 'N')
				return (FALSE);
			else
			{
				system("clear");
				ft_putstr("Uniquement O ou N, tu peux y arriver!\n");
				while (getchar() != '\n')
					;
			}
		}
	}
}

static t_bool	end_game(t_pendu *game)
{
	system("clear");
	if (game->count == 0)
	{
		printf("Perdu! Le mot a trouver etait %s.\n", game->to_find);
		display_pendu(0);
	}
	else
		printf("Bravo! tu as trouve le mot %s!\n", game->to_find);
	return (replay());
}

static void	nb_of_player(t_pendu *game)
{
	int		nb_joueurs;

	while (1)
	{
		printf("A combien de joueurs souhaitez vous jouer? (1 ou 2)\n");
		if (scanf("%d", &nb_joueurs) == 1)
		{
			ft_empty_buff();
			if (nb_joueurs == 1 || nb_joueurs == 2)
				break ;
			else
			{
				system("clear");
				printf("Seulement 1 ou 2 joueurs, ni plus ni moins.\n");
			}
		}
		else
		{
			ft_empty_buff();
			system("clear");
			printf("Choisissez un nombre valide.\n");
		}
	}
	game->two_players = nb_joueurs - 1;
}

static void	init_game(t_pendu *game)
{
	game->count = PENDU_TRIES;
	if (game->two_players == TRUE)
		init_two_players(game);
	else
		init_one_player(game);
}

void	pendu(void)
{
	t_pendu	game;
	t_bool	play;

	play = TRUE;
	while (play == TRUE)
	{
		system("clear");
		printf("Bienvenue dans le jeu du pendu!\n");
		ft_bzero(&game, sizeof(t_pendu));
		nb_of_player(&game);
		init_game(&game);
		play_game(&game);
		play = end_game(&game);
	}
}

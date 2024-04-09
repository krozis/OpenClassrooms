/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_players.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:07:52 by stelie            #+#    #+#             */
/*   Updated: 2021/11/16 17:26:43 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pendu.h"

void	init_two_players(t_pendu *game)
{
	t_bool	correct;
	char	*word;

	word = malloc(sizeof(char) * 51);
	if (word == NULL)
		exit(1);
	system("clear");
	correct = FALSE;
	while (correct != TRUE)
	{
		printf("Joueur 1, choisissez votre mot:\n");
		scanf("%s", word);
		ft_empty_buff();
		correct = ft_str_isalpha(word);
	}
	ft_toupper(word);
	game->to_find = ft_strdup(word);
	init_userword(game);
	free(word);
}

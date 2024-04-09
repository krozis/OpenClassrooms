/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:11:49 by stelie            #+#    #+#             */
/*   Updated: 2021/11/17 10:30:08 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pendu.h"

static int	get_wd_count(FILE *dico)
{
	int		wd_count;
	char	c;

	wd_count = 0;
	c = 'a';
	while (c != EOF)
	{
		c = fgetc(dico);
		if (c == '\n')
			wd_count++;
	}
	rewind (dico);
	return (wd_count);
}

static void	forward_to_rand(FILE *dico, int limit)
{
	char	c;

	c = 'a';
	while (limit > 0 && c != EOF)
	{
		c = fgetc(dico);
		if (c == '\n')
			limit--;
	}
}

static void	fill_rand_to_find(t_pendu *game, FILE *dico)
{
	char	*word;
	char	c;
	int		i;

	i = 0;
	c = 'a';
	word = malloc(sizeof(char) * 51);
	if (word == NULL)
		exit(0);
	while (c != '\n')
	{
		c = fgetc(dico);
		if (c != '\n')
			word[i] = c;
		else
			word[i] = '\0';
		i++;
	}
	game->to_find = ft_strdup(word);
}

static void	get_random_word(t_pendu *game, FILE *dico)
{
	int	rand_nb;
	int	wd_count;

	srand(time(NULL));
	wd_count = get_wd_count(dico);
	rand_nb = (rand() % (wd_count)) + 1;
	forward_to_rand(dico, rand_nb);
	fill_rand_to_find(game, dico);
}

void	init_one_player(t_pendu *game)
{
	FILE	*dico;

	dico = NULL;
	dico = fopen("src/dico.txt", "r");
	if (dico == NULL)
	{
		printf("Impossible de charger le dictionnaire de mots.\n");
		exit(0);
	}
	get_random_word(game, dico);
	fclose(dico);
	init_userword(game);
}

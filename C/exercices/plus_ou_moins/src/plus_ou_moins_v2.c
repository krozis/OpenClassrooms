#include "header.h"

static void	init_game(t_pom *game)
{
	int		raw;

	raw = 0;
	while (raw != 1 && raw != 2)
	{
		printf("Combien de joueurs pour cette partie? (1 ou 2)\n");
		scanf("%i", &raw);
		if (raw == 2)
			game->two_players = TRUE;
	}
	while (game->max < 2)
	{
		printf("Quel niveau de difficulte? (definir le nombre max)\n");
		scanf("%i", &raw);
		game->max = raw;
	}
	if (game->two_players == FALSE)
		game->to_find = (rand() % (game->max - POM_MIN + 1)) + POM_MIN;
	else
	{
		while (game->to_find < 1 || game->to_find > game->max)
		{
			printf("Joueur 2, definissez le nombre mystere:\n");
			scanf("%i", &raw);
			game->to_find = raw;
		}
	}
}

static void	play_game(t_pom *game)
{
	int	guess;

	guess = 0;
	system("clear");
	while (!game->win)
	{
		printf("Devinez le nombre mystere:\n");
		{
			scanf("%i", &guess);
			if (guess > 0 && guess <= game->max)
			{
				game->count++;
				if (guess < game->to_find)
					printf("c'est plus!\n");
				else if (guess > game->to_find)
					printf("c'est moins!\n");
				else
					game->win = TRUE;
			}
		}
	}
	printf("Felicitations, vous avez trouve le nombre mystere!\n");
	printf("Vous avez gagne en %li coup(s).\n", game->count);
}

void	plus_ou_moins_v2(void)
{
	t_pom	game;
	int		replay;

	srand(time(NULL));
	while (!game.quit_game)
	{
		ft_bzero(&game, sizeof(t_pom));
		init_game(&game);
		play_game(&game);
		printf("Souhaitez vous rejouer? (1 pour oui, 2 pour non)\n");
		scanf("%i", &replay);
		if (replay == 2)
			game.quit_game = TRUE;
	}
	printf("Merci d'avoir joue!\n");
}

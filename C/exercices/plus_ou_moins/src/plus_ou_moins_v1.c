#include "header.h"

void	plus_ou_moins_v1(void)
{
	int		nb;
	int		guess;
	t_bool	win;

	win = FALSE;
	srand(time(NULL));
	nb = (rand() % (POM_MAX - POM_MIN + 1)) + POM_MIN;
	system("clear");
	printf("Bienvenue dans le jeu du Plus ou Moins. Tentez de deviner!\n");
	while (!win)
	{
		scanf("%i", &guess);
		if (guess > nb)
			printf("c'est moins!\n");
		else if (guess < nb)
			printf("C'est plus!\n");
		else
			win = TRUE;
	}
	printf("Vous avez trouve le nombre mystere, bravo!\n");
}

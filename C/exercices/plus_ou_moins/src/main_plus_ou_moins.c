#include "header.h"

static void	launcher(int choice)
{
	switch (choice)
	{
	case 1:
		plus_ou_moins_v1();
		break;
	case 2:
		plus_ou_moins_v2();
		break;
	default:
		break;
	}
}

int	main(void)
{
	int		choice;
	char	choice_raw[2];
	t_bool	is_correct;

	choice = 0;
	is_correct = FALSE;
	system("clear");
	printf("Hello. You can select the number of the program to run here:\n");
	printf("1. Plus ou Moins v1\n");
	printf("2. Plus ou Moins v2\n");
	while (!is_correct)
	{
		fgets(choice_raw, sizeof(choice_raw), stdin);
		choice = atoi(choice_raw);
		if (choice >= 1 && choice <= 2)
			is_correct++;
		else
		{
			system("clear");
			printf("Give the number of the program you want to run, please.\n");
		}
	}
	system("clear");
	launcher(choice);
	return (0);
}

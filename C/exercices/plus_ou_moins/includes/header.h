#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <ctype.h>

# define POM_MAX 100
# define POM_MIN 1

# define PENDU_TRIES 10

typedef enum e_bool
{
	FALSE,
	TRUE
}				t_bool;

typedef struct s_pom
{
	t_bool	win;
	size_t	count;
	t_bool	quit_game;
	t_bool	two_players;
	int		to_find;
	int		max;
}				t_pom;

typedef struct s_pendu
{
	t_bool	win;
	size_t	count;
	t_bool	quit_game;
	t_bool	two_players;
	char	to_find[50];
	char	*userword;
	size_t	wd_in_dico;
}				t_pendu;

void	ft_putstr(char *str);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(char *s);
void	ft_toupper(char	*str);
void	plus_ou_moins_v1(void);
void	plus_ou_moins_v2(void);
void	pendu(void);
void	init_pendu(t_pendu *game, t_bool	two_players);
t_bool	get_in_dico(t_pendu *game);

#endif
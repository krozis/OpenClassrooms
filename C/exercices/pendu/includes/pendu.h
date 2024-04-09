/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pendu.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:50:22 by stelie            #+#    #+#             */
/*   Updated: 2021/11/17 09:35:31 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PENDU_H
# define PENDU_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <ctype.h>

# define PENDU_TRIES 10

typedef enum e_bool
{
	FALSE,
	TRUE
}				t_bool;

typedef struct s_pendu
{
	t_bool	win;
	size_t	count;
	t_bool	quit_game;
	t_bool	two_players;
	char	*to_find;
	char	*userword;
}				t_pendu;

t_bool	ft_islowercase(char c);
t_bool	ft_isuppercase(char c);
t_bool	ft_isalpha(char c);
t_bool	ft_str_isalpha(char *str);
t_bool	ft_isincharset(char c, char *str);

void	ft_putchar(char c);
void	ft_putstr(char *str);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
void	ft_toupper(char	*str);
char	ft_toupper_char(char c);
void	ft_bzero(void *s, size_t n);
void	ft_empty_buff(void);

void	pendu(void);
void	init_one_player(t_pendu *game);
void	init_two_players(t_pendu *game);
void	init_userword(t_pendu *game);
void	play_game(t_pendu *game);
void	display_pendu(size_t count);

#endif
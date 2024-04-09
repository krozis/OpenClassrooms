/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alpha_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:50:07 by stelie            #+#    #+#             */
/*   Updated: 2021/11/16 17:37:34 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pendu.h"

t_bool	ft_islowercase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (TRUE);
	return (FALSE);
}

t_bool	ft_isuppercase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (TRUE);
	return (FALSE);
}

t_bool	ft_isalpha(char c)
{
	if (ft_islowercase(c) || ft_isuppercase(c))
		return (TRUE);
	return (FALSE);
}

t_bool	ft_str_isalpha(char *str)
{
	while (*str)
	{
		if (!ft_isalpha(*str))
			return (FALSE);
		str++;
	}
	return (TRUE);
}

t_bool	ft_isincharset(char c, char *str)
{
	while (*str)
	{
		if (c == *str)
			return (TRUE);
		str++;
	}
	return (FALSE);
}

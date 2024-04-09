/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:13:32 by stelie            #+#    #+#             */
/*   Updated: 2021/11/16 17:21:51 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pendu.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*dup;

	i = ft_strlen(s1);
	dup = malloc(sizeof(char) * (i + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

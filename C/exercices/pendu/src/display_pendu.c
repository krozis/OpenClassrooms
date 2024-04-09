/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_pendu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 09:33:20 by stelie            #+#    #+#             */
/*   Updated: 2021/11/17 10:23:42 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pendu.h"

static void	display_9(void)
{
	printf("\n              \n              \n");
	printf("              \n              \n              \n              \n");
	printf("     ------     \n");
}

static void	display_6_to_8(size_t count)
{
	printf("\n    ");
	if (count < 7)
		printf("|");
	else
		printf(" ");
	if (count < 8)
		printf("---");
	else
		printf("   ");
	printf("|     \n        |     \n        |     \n        |     \n");
	printf("        |     \n        |     \n     ------     \n");
}

static void	display_3_to_5(size_t count)
{
	printf("\n    |---|     \n    0   |     \n   ");
	if (count < 4)
		printf("/");
	else
		printf(" ");
	if (count < 5)
		printf("|");
	else
		printf(" ");
	printf("   |     \n        |     \n        |     \n");
	printf("        |     \n     ------     \n");
}

static void	display_0_to_2(size_t count)
{
	printf("\n    |---|     \n    0   |     \n   /|\\  |     \n    ");
	if (count < 2)
		printf("-");
	else
		printf(" ");
	printf("   |     \n");
	if (count == 1)
		printf("   /    |     \n");
	else if (count == 0)
		printf("   / \\  |     \n");
	else
		printf("        |     \n");
	printf("        |     \n     ------     \n");
}

void	display_pendu(size_t count)
{
	if (count == 9)
		display_9();
	if (count <= 8 && count >= 6)
		display_6_to_8(count);
	if (count <= 5 && count >= 3)
		display_3_to_5(count);
	if (count < 3)
		display_0_to_2(count);
}

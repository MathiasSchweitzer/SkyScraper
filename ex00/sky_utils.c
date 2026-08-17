/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathias <mschweit@learner.42.tech>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 12:28:29 by mschweit          #+#    #+#             */
/*   Updated: 2026/08/16 04:26:32 by mathias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "sky_array.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	n;

	n = 0;
	while (s1[n] == s2[n])
	{
		if (s1[n] == '\0' && s2[n] == '\0')
			return (1);
		n++;
	}
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*int	error(t_sky_game *game, char *message)
{
	int	count;

	write(1, "Error\n", 6);
	if (!game)
		return (1);
	count = 0;
	while (message[count])
		count++;
	write(2, message, count);
	write(2, "\n", 1);
	free_game(game);
	return (1);
}*/

int	error(t_sky_game *game, char *message)
{
	(void) message;
	write(1, "Error\n", 6);
	if (!game)
		return (1);
	free_game(game);
	return (1);
}

void	print_line(int **arr, int row, int size)
{
	int	col;

	col = 0;
	while (col < size)
	{
		ft_putchar('0' + arr[row][col]);
		if (col != size - 1)
			ft_putchar(' ');
		else
			ft_putchar('\n');
		col++;
	}
}

void	print_arr(int **arr, int size)
{
	int	row;

	if (arr == NULL)
	{
		error(NULL, "Arr is NULL.");
		return ;
	}
	row = 0;
	while (row < size)
	{
		if (arr[row] == NULL)
			write(1, "(NULL)\n", 7);
		else
			print_line(arr, row, size);
		row++;
	}
}

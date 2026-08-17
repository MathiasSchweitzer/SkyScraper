/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_solve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschweit <mschweit@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 22:16:02 by mschweit          #+#    #+#             */
/*   Updated: 2026/08/17 14:37:55 by mschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "sky_array.h"
#include "sky_utils.h"
#include "sky_check.h"
#include "sky_fill.h"

int	nb_in_row(t_sky_game *game, int nb, int row)
{
	int	col;

	col = 0;
	while (col < game->size)
	{
		if (game->result[row][col] == nb)
			return (1);
		col++;
	}
	return (0);
}

int	nb_in_col(t_sky_game *game, int nb, int col)
{
	int	row;

	row = 0;
	while (row < game->size)
	{
		if (game->result[row][col] == nb)
			return (1);
		row++;
	}
	return (0);
}

int	found_0(t_sky_game *game, int *row, int *col)
{
	int	found;

	found = 0;
	*row = 0;
	while (*row < game->size)
	{
		*col = 0;
		while (*col < game->size)
		{
			if (game->result[*row][*col] == 0)
			{
				found = 1;
				break ;
			}
			(*col)++;
		}
		if (found)
			break ;
		(*row)++;
	}
	return (found);
}

int	brute_force(t_sky_game *game)
{
	int	row;
	int	col;
	int	count;

	if (!found_0(game, &row, &col))
	{
		if (is_correct(game))
			return (1);
		return (0);
	}
	count = 0;
	while (count < game->size)
	{
		count++;
		if (!nb_in_row(game, count, row) && !nb_in_col(game, count, col))
		{
			game->result[row][col] = count;
			if (brute_force(game))
				return (1);
		}
	}
	game->result[row][col] = 0;
	return (0);
}

int	solve_grid(t_sky_game *game)
{
	if (!game)
	{
		error(NULL, "Game is NULL.");
		return (0);
	}
	fill_max(game);
	return (brute_force(game));
}

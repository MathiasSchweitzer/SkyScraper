/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschweit <mschweit@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 03:15:25 by mathias           #+#    #+#             */
/*   Updated: 2026/08/17 20:25:46 by mschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sky_array.h"

void	fill_col(int **result, int col, int size)
{
	int	row;

	row = 0;
	while (row < size && (result[row][col] == 0 || result[row][col] == row + 1))
	{
		result[row][col] = row + 1;
		row++;
	}
}

void	fill_col_reverse(int **result, int col, int size)
{
	int	row;

	row = size;
	while (row > 0
		&& (result[row - 1][col] == 0 || result[row - 1][col] == size - row))
	{
		row--;
		result[row][col] = size - row;
	}
}

void	fill_row(int **result, int row, int size)
{
	int	col;

	col = 0;
	while (col < size && (result[row][col] == 0 || result[row][col] == col + 1))
	{
		result[row][col] = col + 1;
		col++;
	}
}

void	fill_row_reverse(int **result, int row, int size)
{
	int	col;

	col = size;
	while (col > 0
		&& (result[row][col - 1] == 0 || result[row][col - 1] == size - col))
	{
		col--;
		result[row][col] = size - col;
	}
}

void	fill_max(t_sky_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < game->size)
		{
			if (game->rules[row][col] == game->size)
			{
				if (row == 0)
					fill_col(game->result, col, game->size);
				else if (row == 1)
					fill_col_reverse(game->result, col, game->size);
				else if (row == 2)
					fill_row(game->result, col, game->size);
				else
					fill_row_reverse(game->result, col, game->size);
			}
			col++;
		}
		row++;
	}
}

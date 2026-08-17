/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathias <mschweit@learner.42.tech>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 13:06:12 by mschweit          #+#    #+#             */
/*   Updated: 2026/08/16 04:21:52 by mathias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sky_count.h"
#include "sky_array.h"

int	correct_col(t_sky_game *game)
{
	int	col;

	col = 0;
	while (col < game->size)
	{
		if (visible_col(game->result, col, game->size) != game->rules[0][col])
			return (0);
		col++;
	}
	return (1);
}

int	correct_col_reverse(t_sky_game *game)
{
	int	col;

	col = 0;
	while (col < game->size)
	{
		if (visible_col_reverse(game->result, col, game->size)
			!= game->rules[1][col])
			return (0);
		col++;
	}
	return (1);
}

int	correct_row(t_sky_game *game)
{
	int	col;

	col = 0;
	while (col < game->size)
	{
		if (visible_row(game->result, col, game->size) != game->rules[2][col])
			return (0);
		col++;
	}
	return (1);
}

int	correct_row_reverse(t_sky_game *game)
{
	int	col;

	col = 0;
	while (col < game->size)
	{
		if (visible_row_reverse(game->result, col, game->size)
			!= game->rules[3][col])
			return (0);
		col++;
	}
	return (1);
}

int	is_correct(t_sky_game *game)
{
	if (!game->result || !game->rules)
		return (0);
	if (!correct_col(game))
		return (0);
	if (!correct_col_reverse(game))
		return (0);
	if (!correct_row(game))
		return (0);
	if (!correct_row_reverse(game))
		return (0);
	return (1);
}

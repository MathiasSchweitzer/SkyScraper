/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathias <mschweit@learner.42.tech>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 12:16:32 by mschweit          #+#    #+#             */
/*   Updated: 2026/08/16 04:24:32 by mathias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sky_utils.h"

int	arg_to_arr(char *str, t_sky_game *arr)
{
	int	count;

	count = 0;
	if (str[0] < '1' || str[0] > '0' + arr->size)
		return (1);
	while (str[0])
	{
		if (count >= arr->size * arr->size)
			return (1);
		if (str[0] >= '1' && str[0] <= '4')
		{
			if (count + 1 == arr->size * arr->size && str[1] != '\0')
				return (1);
			arr->rules[count / arr->size][count % arr->size] = str[0] - '0';
			count++;
		}
		else if (str[0] != ' ')
			return (1);
		str++;
	}
	if (count != arr->size * arr->size)
		return (1);
	return (0);
}

void	free_arr(int **arr, int size)
{
	int	row;

	if (!arr)
	{
		error(NULL, "Arr is NULL.");
		return ;
	}
	row = 0;
	while (row < size)
	{
		if (arr[row] != NULL)
			free(arr[row]);
		row++;
	}
	free(arr);
}

void	free_game(t_sky_game *game)
{
	if (!game)
	{
		error(NULL, "Game is null");
		return ;
	}
	free_arr(game->result, game->size);
	free_arr(game->rules, game->size);
	free(game);
}

int	**init_arr(int rows, int cols)
{
	int	**res;
	int	row;
	int	col;

	res = malloc(rows * sizeof(int *));
	if (!res)
		return (NULL);
	row = 0;
	while (row < rows)
	{
		res[row] = malloc(cols * sizeof(int));
		if (!res[row])
			free_arr(res, row);
		col = 0;
		while (col < cols)
		{
			res[row][col] = 0;
			col++;
		}
		row++;
	}
	return (res);
}

t_sky_game	*init_game(int size)
{
	t_sky_game	*res;

	if (size < 1 || size > 9)
		return (NULL);
	res = malloc(sizeof(t_sky_game));
	if (!res)
		return (NULL);
	res->result = init_arr(size, size);
	if (!res->result)
		return (NULL);
	res->rules = init_arr(4, size);
	if (!res->rules)
		return (NULL);
	res->size = size;
	return (res);
}

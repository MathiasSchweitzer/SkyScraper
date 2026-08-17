/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathias <mschweit@learner.42.tech>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 13:42:26 by mschweit          #+#    #+#             */
/*   Updated: 2026/08/16 04:22:11 by mathias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	visible_col(int **result, int col, int size)
{
	int	row;
	int	max;
	int	res;

	row = 0;
	max = 0;
	res = 0;
	while (row < size)
	{
		if (max < result[row][col])
		{
			res++;
			max = result[row][col];
		}
		row++;
	}
	return (res);
}

int	visible_col_reverse(int **result, int col, int size)
{
	int	row;
	int	max;
	int	res;

	row = size;
	max = 0;
	res = 0;
	while (row > 0)
	{
		row--;
		if (max < result[row][col])
		{
			res++;
			max = result[row][col];
		}
	}
	return (res);
}

int	visible_row(int **result, int row, int size)
{
	int	col;
	int	max;
	int	res;

	col = 0;
	max = 0;
	res = 0;
	while (col < size)
	{
		if (max < result[row][col])
		{
			res++;
			max = result[row][col];
		}
		col++;
	}
	return (res);
}

int	visible_row_reverse(int **result, int row, int size)
{
	int	col;
	int	max;
	int	res;

	col = size;
	max = 0;
	res = 0;
	while (col > 0)
	{
		col--;
		if (max < result[row][col])
		{
			res++;
			max = result[row][col];
		}
	}
	return (res);
}

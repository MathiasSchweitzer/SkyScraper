/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_array.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschweit <mschweit@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 12:17:47 by mschweit          #+#    #+#             */
/*   Updated: 2026/08/15 22:13:12 by mschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SKY_ARRAY_H
# define SKY_ARRAY_H

typedef struct s_sky_game
{
	int	size;
	int	**result;
	int	**rules;
}	t_sky_game;

int			arg_to_arr(char *str, t_sky_game *arr);
void		free_arr(int **arr, int size);
void		free_game(t_sky_game *game);
int			**init_arr(int rows, int cols);
t_sky_game	*init_game(int size);

#endif

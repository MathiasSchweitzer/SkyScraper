/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschweit <mschweit@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 12:34:35 by mschweit          #+#    #+#             */
/*   Updated: 2026/08/17 14:38:09 by mschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SKY_UTILS_H
# define SKY_UTILS_H

# include "sky_array.h"

int		ft_strcmp(char *s1, char *s2);
void	ft_putchar(char c);
int		error(t_sky_game *game, char *message);
void	print_arr(int **arr, int size);

#endif

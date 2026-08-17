/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_count.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschweit <mschweit@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 13:42:34 by mschweit          #+#    #+#             */
/*   Updated: 2026/08/15 17:15:26 by mschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SKY_COUNT_H
# define SKY_COUNT_H

int	visible_col(int **result, int col, int size);
int	visible_col_reverse(int **result, int col, int size);
int	visible_row(int **result, int row, int size);
int	visible_row_reverse(int **result, int row, int size);

#endif

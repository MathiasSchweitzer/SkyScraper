/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathias <mschweit@learner.42.tech>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 11:24:14 by mschweit          #+#    #+#             */
/*   Updated: 2026/08/16 04:24:11 by mathias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "sky_utils.h"
#include "sky_array.h"
#include "sky_solve.h"

int	main(int argc, char **argv)
{
	t_sky_game	*game;

	if (argc != 2)
		return (error(NULL, "Invalid arguments amount."));
	game = init_game(4);
	if (arg_to_arr(argv[1], game))
		return (error(game, "Invalid argument value."));
	if (solve_grid(game))
		print_arr(game->result, game->size);
	else
		return (error(game, "No solutions."));
	free_game(game);
	return (0);
}

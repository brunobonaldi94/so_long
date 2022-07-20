/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events_animation_helpers_bonus.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:33:11 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/20 04:09:02 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	add_delay(int number_of_seconds)
{
	int		milli_seconds;
	clock_t	start_time;

	milli_seconds = 1000 * number_of_seconds;
	start_time = clock();
	while (clock() < start_time + milli_seconds)
		;
}

int	generate_random_int(int min, int max)
{
	int	random_nbr;

	srand(time(NULL));
	random_nbr = (rand() % (max + 1 - min)) + min;
	return (random_nbr);
}

void	put_dead_player(t_data *mlx)
{
	mlx->game_play.game_over = TRUE;
	image_change_file_path(mlx, &mlx->img_player, IMG_DEAD_PLAYER_PATH);
	image_put(mlx, &mlx->img_player);
}

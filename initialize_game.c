/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalia <natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:48:18 by natalia           #+#    #+#             */
/*   Updated: 2024/04/16 12:17:56 by natalia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_player_position(t_game	**game)
{
	int	x;
	int	y;

	x = 0;
	while (x < (*game)->height)
	{
		y = 0;
		while (y < (*game)->width)
		{
			if ((*game)->map[x][y] == 'P')
			{
				(*game)->player_position_x = x;
				(*game)->player_position_y = y;
				return ;
			}
			y++;
		}
		x++;
	}
}

static void	set_exit_position(t_game	**game)
{
	int	x;
	int	y;

	x = 0;
	while (x < (*game)->height)
	{
		y = 0;
		while (y < (*game)->width)
		{
			if ((*game)->map[x][y] == 'E')
			{
				(*game)->exit_position_x = x;
				(*game)->exit_position_y = y;
				return ;
			}
			y++;
		}
		x++;
	}
}

static void	count_collectables(t_game	**game)
{
	int	x;
	int	y;

	x = 0;
	(*game)->total_collectable = 0;
	while (x < (*game)->height)
	{
		y = 0;
		while (y < (*game)->width)
		{
			if ((*game)->map[x][y] == 'C')
			{
				(*game)->total_collectable++;
			}
			y++;
		}
		x++;
	}
	printf("total collectable = %d\n", (*game)->total_collectable);
}

void	initialize_game_data(t_game **game, char **map)
{
	(*game)->map = map;
	(*game)->height = height_map(map);
	(*game)->width = ft_strlen_nl(map[0]);
	(*game)->mlx = mlx_init((*game)->width * PIXELS, (*game)->height * PIXELS,
			"SoLong", true);
	if (!(*game)->mlx)
		free_array_and_exit(map);
	(*game)->total_moves = 0;
	(*game)->total_collectable = 0;
	set_player_position(game);
	set_exit_position(game);
	count_collectables(game);
}

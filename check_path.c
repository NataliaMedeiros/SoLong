/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalia <natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:00:32 by natalia           #+#    #+#             */
/*   Updated: 2024/04/14 15:38:48 by natalia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	valid_path(t_game *game)
{
	int	position_x;
	int	position_y;
	int	x;
	int	y;
	bool	path_is_valid;

	position_x = game->player_position_x;
	position_y = game->player_position_y;
	y = 1;
	path_is_valid = true;
	if (game->map[position_x + 1][position_y] == '1'
		&& game->map[position_x - 1][position_y] == '1'
		&& game->map[position_x][position_y + 1] == '1'
		&& game->map[position_x][position_y - 1] == '1')
		path_is_valid = false;
	else
	{
		while (y < game->width - 1)
		{
			x = 1;
			path_is_valid = false;
			while (x < game->height - 1)
			{
				if (game->map[x][y] != '1')
				{
					path_is_valid = true;
					break;
				}
				x++;
			}
			if (!path_is_valid)
				return (path_is_valid);
			y++;
		}
		x = 1;
		while (x < game->height - 1)
		{
			y = 1;
			path_is_valid = false;
			while (y < game->width - 1)
			{
				if (game->map[x][y] != '1')
				{
					path_is_valid = true;
					break;
				}
				y++;
			}
			if (!path_is_valid)
				return (path_is_valid);
			x++;
		}
	}
	return (path_is_valid);
}

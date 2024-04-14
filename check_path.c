/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalia <natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:00:32 by natalia           #+#    #+#             */
/*   Updated: 2024/04/14 19:13:16 by natalia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	surroded_by_wall(char	**map, int x, int y)
{
	if (map[x + 1][y] == '1'
		&& map[x - 1][y] == '1'
		&& map[x][y + 1] == '1'
		&& map[x][y - 1] == '1')
		return (true);
	return (false);
}

bool	free_columns(t_game *game)
{
	int		x;
	int		y;
	bool	path_is_valid;

	y = 1;
	while (y < game->width - 1)
	{
		x = 1;
		path_is_valid = false;
		while (x < game->height - 1)
		{
			if (game->map[x][y] == 'C' && surroded_by_wall(game->map, x, y))
				return (false);
			if (game->map[x][y] != '1')
			{
				path_is_valid = true;
				break ;
			}
			x++;
		}
		if (!path_is_valid)
			return (path_is_valid);
		y++;
	}
	return (path_is_valid);
}

bool	free_rows(t_game *game)
{
	int		x;
	int		y;
	bool	path_is_valid;

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
				break ;
			}
			y++;
		}
		if (!path_is_valid)
			return (path_is_valid);
		x++;
	}
	return (path_is_valid);
}

bool	valid_path(t_game *game)
{
	if (surroded_by_wall(game->map, game->player_position_x,
			game->player_position_y) || surroded_by_wall(game->map,
			game->exit_position_x, game->exit_position_y))
		return (false);
	else
		if (!free_columns(game) || !free_rows(game))
			return (false);
	return (true);
}

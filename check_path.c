/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_path.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/14 15:00:32 by natalia       #+#    #+#                 */
/*   Updated: 2024/04/19 16:09:51 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	surroded_by_wall(char	**map, int x, int y)
{
	if (map[x + 1][y] == '1'
		&& map[x - 1][y] == '1'
		&& map[x][y + 1] == '1'
		&& map[x][y - 1] == '1')
		return (true);
	return (false);
}

static bool	flood_fill(t_game *temp, int x, int y)
{
	if (temp->map[x][y] == '1')
		return (false);
	if (temp->map[x][y] == 'D')
		return (false);
	if (temp->map[x][y] == 'E')
		temp->exit_position_x = 1;
	if (temp->map[x][y] == 'C')
		temp->collected_collectables += 1;
	temp->map[x][y] = '1';
	if (flood_fill(temp, x + 1, y))
		return (true);
	if (flood_fill(temp, x - 1, y))
		return (true);
	if (flood_fill(temp, x, y + 1))
		return (true);
	if (flood_fill(temp, x, y -1))
		return (true);
	return (false);
}

bool	valid_path(t_game *game)
{
	t_game	temp_game;
	int		i;

	if (surroded_by_wall(game->map, game->player_position_x,
			game->player_position_y) || surroded_by_wall(game->map,
			game->exit_position_x, game->exit_position_y))
		return (error("No valid path"), false);
	temp_game.map = ft_calloc(sizeof(t_game), game->height);
	if (!temp_game.map)
		error("Malloc allocation failed");
	i = 0;
	while (i < game->height)
	{
		temp_game.map[i] = strdup(game->map[i]);
		i++;
	}
	temp_game.collected_collectables = 0;
	temp_game.exit_position_x = 0;
	flood_fill(&temp_game, game->player_position_x, game->player_position_y);
	if (temp_game.collected_collectables != game->total_collectable
		|| temp_game.exit_position_x != 1)
		return (free_array(temp_game.map), error("No valid path"), false);
	free_array(temp_game.map);
	return (true);
}

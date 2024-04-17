/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalia <natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:00:32 by natalia           #+#    #+#             */
/*   Updated: 2024/04/16 15:55:25 by natalia          ###   ########.fr       */
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

bool	flood_fill(t_game	*temp_game, int x, int y)
{
	printf("%d and %d\n", x, y);
	if (temp_game->map[x][y] == '1' || temp_game->map[x][y] == 'E')
	{
		if (temp_game->map[x][y] == 'E')
			temp_game->exit_position_x = 1;
		return (false);
	}
	if (temp_game->map[x][y] == 'C')
		temp_game->collected_collectables += 1;
	temp_game->map[x][y] = '1';
	if (flood_fill(temp_game, x + 1, y))
		return (true);
	if (flood_fill(temp_game, x - 1, y))
		return (true);
	if (flood_fill(temp_game, x, y + 1))
		return (true);
	if (flood_fill(temp_game, x, y - 1))
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
	//temp_game = ft_calloc(1, sizeof(t_game));
	temp_game.collected_collectables = 0;
	temp_game.map = (char **)malloc(game->height * sizeof(char *));
	if (!temp_game.map)
		error("Memory allocation failed");
	i = 0;
	while (i < game->height)
	{
		temp_game.map[i] = strdup(game->map[i]); //TODO includ my ft_strdup and change here
		i++;
	}
	flood_fill(&temp_game, game->player_position_x, game->player_position_y);
	if (temp_game.exit_position_x != 1
		|| temp_game.collected_collectables != game->total_collectable)
		return (error("No valid path"), false);
	//free_array(temp_game.map); //TODO check possible memory leak
	return (true);
}

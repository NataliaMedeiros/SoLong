/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_checker.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/14 12:36:28 by natalia       #+#    #+#                 */
/*   Updated: 2024/04/18 20:26:52 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	look_for_collectable(int height, int width, t_game *game)
{
	int	i;

	i = 0;
	if ((game)->map[height][width] == 'C')
	{
		while (i < game->total_collectable)
		{
			if (((game->images->collectable->instances[i].y) / PIXELS) == height
				&& ((game->images->collectable->instances[i].x) / PIXELS)
				== width)
			{
				(game)->collected_collectables++;
				(game)->images->collectable->instances[i].enabled = false;
				(game)->map[height][width] = '0';
			}
			i++;
		}
	}
}

bool	hit_on_enemy(t_game *game, int height, int width)
{
	if (game->map[height][width] == 'D')
	{
		mlx_put_string(game->mlx, "GAME OVER",
			(game->width * PIXELS - 40) / 2, (game->height * PIXELS - 5) / 2);
		return (true);
	}
	return (false);
}

void	collected_all_collectable(t_game *game)
{
	if (game->collected_collectables == game->total_collectable)
	{
		mlx_delete_image(game->mlx, game->images->exit);
		if (mlx_image_to_window(game->mlx, game->images->open_exit,
				game->exit_position_y * PIXELS,
				game->exit_position_x * PIXELS) < 0)
			error("Failed to put image to window");
		if (game->exit_position_y == game->player_position_y
			&& game->exit_position_x == game->player_position_x)
		{
			mlx_close_window(game->mlx);
		}
	}
}

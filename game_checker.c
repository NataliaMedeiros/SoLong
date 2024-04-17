/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_checker.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/14 12:36:28 by natalia       #+#    #+#                 */
/*   Updated: 2024/04/17 14:30:57 by nmedeiro      ########   odam.nl         */
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

void	collected_all_collectable(t_game *game)
{
	if (game->collected_collectables == game->total_collectable)
	{
		mlx_delete_image(game->mlx, game->images->exit);
		if (mlx_image_to_window(game->mlx, game->images->open_exit,
				game->exit_position_y * PIXELS,
				game->exit_position_x * PIXELS) < 0)
			error("Failed to put image to window");
	}
	if (game->collected_collectables == game->total_collectable
		&& game->exit_position_x == game->player_position_x
		&& game->exit_position_y == game->player_position_y)
	{
		mlx_close_window(game->mlx);
		ft_putendl_fd(1, "Congratulations, you won!!!");
	}
}

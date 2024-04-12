/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalia <natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:01:35 by natalia           #+#    #+#             */
/*   Updated: 2024/04/12 22:13:06 by natalia          ###   ########.fr       */
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

t_game	*move_up(t_game	*game)
{
	if (game->map[game->player_position_x - 1][game->player_position_y] != '1')
	{
		game->images->player->instances[0].y -= PIXELS;
		game->player_position_x--;
		look_for_collectable(game->player_position_x,
			game->player_position_y, game);
	}
	else
		printf("Include a phase to when the character heats the wall\n");//TO DO
	return (game);
}

t_game	*move_down(t_game	*game)
{
	if (game->map[game->player_position_x + 1][game->player_position_y] != '1')
	{
		game->images->player->instances[0].y += PIXELS;
		game->player_position_x++;
		look_for_collectable(game->player_position_x,
			game->player_position_y, game);
	}
	else
	{
		printf("Include a phase to when the character heats the wall\n");//TO DO
		//game->images = load_yeow_texture(game->mlx, game->images);
		//mlx_image_to_window(game->mlx, game->images->yeow, (game->player_position_x + 1) * PIXELS, game->player_position_y * PIXELS);
	}
	return (game);
}

t_game	*move_right(t_game	*game)
{
	if (game->map[game->player_position_x][game->player_position_y + 1] != '1')
	{
		game->images->player->instances[0].x += PIXELS;
		game->player_position_y++;
		look_for_collectable(game->player_position_x,
			game->player_position_y, game);
	}
	else
		printf("Include a phase to when the character heats the wall\n");//TO DO
	return (game);
}

t_game	*move_left(t_game	*game)
{
	if (game->map[game->player_position_x][game->player_position_y - 1] != '1')
	{
		game->images->player->instances[0].x -= PIXELS;
		game->player_position_y--;
		look_for_collectable(game->player_position_x,
			game->player_position_y, game);
	}
	else
		printf("Include a phase to when the character heats the wall\n");//TO DO
	return (game);
}

void	ft_hook_moves(mlx_key_data_t key_data, void *mlx)
{
	t_game	*game;

	game = (t_game *)mlx;
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if ((key_data.key == MLX_KEY_UP || key_data.key == MLX_KEY_W )
		&& key_data.action == MLX_PRESS)
		move_up(game);
	if ((key_data.key == MLX_KEY_DOWN || key_data.key == MLX_KEY_S )
		&& key_data.action == MLX_PRESS)
		move_down(game);
	if ((key_data.key == MLX_KEY_RIGHT || key_data.key == MLX_KEY_D )
		&& key_data.action == MLX_PRESS)
		move_right(game);
	if ((key_data.key == MLX_KEY_LEFT || key_data.key == MLX_KEY_A )
		&& key_data.action == MLX_PRESS)
		move_left(game);
}

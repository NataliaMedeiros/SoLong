/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movements.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/12 14:01:35 by natalia       #+#    #+#                 */
/*   Updated: 2024/04/22 12:34:13 by nmedeiro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_game	*move_up(t_game	*game)
{
	if (game->map[game->player_position_x - 1][game->player_position_y] != '1')
	{
		game->player_position_x--;
		game->total_moves++;
		game->images->player->instances->enabled = true;
		game->images->player->instances[0].y -= PIXELS;
		look_for_collectable(game->player_position_x,
			game->player_position_y, game);
		printf("moves: %d\n", game->total_moves);//change
	}
	return (game);
}

static t_game	*move_down(t_game	*game)
{
	if (game->map[game->player_position_x + 1][game->player_position_y] != '1')
	{
		game->player_position_x++;
		game->total_moves++;
		game->images->player->instances->enabled = true;
		game->images->player->instances[0].y += PIXELS;
		look_for_collectable(game->player_position_x,
			game->player_position_y, game);
		printf("moves: %d\n", game->total_moves); //change
	}
	return (game);
}

static t_game	*move_right(t_game	*game)
{
	if (game->map[game->player_position_x][game->player_position_y + 1] != '1')
	{
		game->player_position_y++;
		game->total_moves++;
		game->images->player->instances[0].x += PIXELS;
		look_for_collectable(game->player_position_x,
			game->player_position_y, game);
		printf("moves: %d\n", game->total_moves); //change
	}
	return (game);
}

static t_game	*move_left(t_game	*game)
{
	if (game->map[game->player_position_x][game->player_position_y - 1] != '1')
	{
		game->player_position_y--;
		game->total_moves++;
		game->images->player->instances[0].x -= PIXELS;
		look_for_collectable(game->player_position_x,
			game->player_position_y, game);
		printf("moves: %d\n", game->total_moves);//change
	}
	return (game);
}

void	ft_hook_moves(mlx_key_data_t key_data, void *mlx)
{
	t_game	*game;

	game = (t_game *)mlx;
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (key_data.action == MLX_PRESS)
	{
		if ((key_data.key == MLX_KEY_UP || key_data.key == MLX_KEY_W))
			move_up(game);
		if ((key_data.key == MLX_KEY_DOWN || key_data.key == MLX_KEY_S))
			move_down(game);
		if ((key_data.key == MLX_KEY_RIGHT || key_data.key == MLX_KEY_D))
			move_right(game);
		if ((key_data.key == MLX_KEY_LEFT || key_data.key == MLX_KEY_A))
			move_left(game);
	}
	collected_all_collectable(game);
}

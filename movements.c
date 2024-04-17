/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalia <natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:01:35 by natalia           #+#    #+#             */
/*   Updated: 2024/04/16 15:30:39 by natalia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_moves(t_game *game)
{
	char	*temp;
	char	print_moves[10];

	temp = ft_itoa(game->total_moves);
	strcpy(print_moves, "Moves: ");
	strcat(print_moves, temp);
	mlx_delete_image(game->mlx, game->images->moves_print);
	game->images->moves_print = mlx_put_string(game->mlx, print_moves,
			16, game->height * 64 - 350);
	free(temp);
}

void	print_collectables(t_game	*game)
{
	char	*temp;
	char	print_collectables[20];

	temp = ft_itoa(game->collected_collectables);
	strcpy(print_collectables, "Collected: ");
	strcat(print_collectables, temp);
	strcat(print_collectables, "/");
	strcat(print_collectables, ft_itoa(game->total_collectable));
	mlx_delete_image(game->mlx, game->images->collected_print);
	game->images->collected_print = mlx_put_string(game->mlx,
			print_collectables, 16, game->height * 64 - 370);
	free(temp);
}

t_game	*move_up(t_game	*game)
{
	if (game->map[game->player_position_x - 1][game->player_position_y] != '1')
	{
		game->images->player->instances[0].y -= PIXELS;
		game->player_position_x--;
		game->total_moves++;
		look_for_collectable(game->player_position_x,
			game->player_position_y, game);
		printf("moves: %d\n", game->total_moves);
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
		game->total_moves++;
		look_for_collectable(game->player_position_x,
			game->player_position_y, game);
		printf("moves: %d\n", game->total_moves);
	}
	else
	{
		printf("Include a phase to when the character heats the wall\n");//TO DO
	}
	return (game);
}

static void	change_direction(t_game *game, char c, int x, int y)
{
	// if (c == 'u')
	// 	mlx_image_to_window(game->mlx, game->img->player_up, \
	// 	x * PIXELS, y * PIXELS);
	// if (c == 'd')
	// 	mlx_image_to_window(game->mlx, game->img->player_down, \
	// 	x * PIXELS, y * PIXELS);
	// if (c == 'l')
	// 	mlx_image_to_window(game->mlx, game->img->player_left, \
	// 	x * PIXELS, y * PIXELS);
	if (c == 'r')
	{
		// if (a == 'p')
		// 	mlx_delete_image(game->mlx, game->images->player);
		if (mlx_image_to_window(game->mlx, game->images->player_right,
			x * PIXELS, y * PIXELS) < 0 )
			error("Failed to put image to window");
	}
}

t_game	*move_right(t_game	*game)
{
	if (game->map[game->player_position_x][game->player_position_y + 1] != '1')
	{
		game->player_position_y++;
		game->total_moves++;
		change_direction(game, 'r', game->player_position_x, game->player_position_y);
		game->images->player->instances[0].x += PIXELS;
		look_for_collectable(game->player_position_x,
			game->player_position_y, game);
		printf("moves: %d\n", game->total_moves);
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
		game->total_moves++;
		look_for_collectable(game->player_position_x,
			game->player_position_y, game);
		printf("moves: %d\n", game->total_moves);
	}
	else
		printf("Include a phase to when the character heats the wall\n");//TO DO
	return (game);
}

// void	load_player(t_game *game, mlx_image_t	*player)
// {
// 	if (game->images->player->enabled)
// 		mlx_delete_image(game->mlx, game->images->player);
// 	if (!player->enabled)
// 	{
// 		player->enabled = true;
// 		if (mlx_image_to_window(game->mlx, player,
// 				game->player_position_y * PIXELS,
// 				game->player_position_x * PIXELS) < 0)
// 			error("Failed to put image to window");
// 	}
// }

void	ft_hook_moves(mlx_key_data_t key_data, void *mlx)
{
	t_game	*game;

	game = (t_game *)mlx;
	//game->images->player->instances[0].enabled = false;
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
	print_moves(game);
	print_collectables(game);
	collected_all_collectable(game);
}

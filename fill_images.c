/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_images.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/12 13:56:45 by natalia       #+#    #+#                 */
/*   Updated: 2024/04/19 11:09:17 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	string_to_screen(t_game *game)
{
	char	*temp;
	char	colected_print[20];

	temp = ft_itoa(game->total_collectable);
	strcpy(colected_print, "Collected: 0/");
	strcat(colected_print, temp);
	game->images->moves_print = mlx_put_string(game->mlx, "Moves: 0",
			16, game->height * 64 - 350);
	game->images->collected_print = mlx_put_string(game->mlx, colected_print,
			16, game->height * 64 - 370);
	free(temp);
}

void	load_component_images(t_game *game, int width, int height)
{
	if (game->map[height][width] == '1')
	{
		if (mlx_image_to_window(game->mlx, game->images->wall,
				width * PIXELS, height * PIXELS) < 0)
			error("Failed to put image to window");
	}
	else if (game->map[height][width] == 'C')
	{
		if (mlx_image_to_window(game->mlx, game->images->collectable,
				width * PIXELS, height * PIXELS) < 0)
			error("Failed to put image to window");
	}
	else if (game->map[height][width] == 'E')
	{
		if (mlx_image_to_window(game->mlx, game->images->exit,
				width * PIXELS, height * PIXELS) < 0)
			error("Failed to put image to window");
	}
	else if (game->map[height][width] == 'D')
	{
		if (mlx_image_to_window(game->mlx, game->images->enemy,
				width * PIXELS, height * PIXELS) < 0)
			error("Failed to put image to window");
	}
}

static void	fill_players_images(t_game *game)
{
	int	width;
	int	height;

	width = game->player_position_y;
	height = game->player_position_x;
	if (mlx_image_to_window(game->mlx, game->images->player,
			width * PIXELS, height * PIXELS) < 0)
		error("Failed to put image to window");
	if (mlx_image_to_window(game->mlx, game->images->player_right,
			width * PIXELS, height * PIXELS) < 0)
		error("Failed to put image to window");
	game->images->player_right->instances->enabled = false;
	if (mlx_image_to_window(game->mlx, game->images->player_left,
			width * PIXELS, height * PIXELS) < 0)
		error("Failed to put image to window");
	game->images->player_left->instances->enabled = false;
	if (mlx_image_to_window(game->mlx, game->images->player_dead,
			width * PIXELS, height * PIXELS) < 0)
		error("Failed to put image to window");
	game->images->player_dead->instances->enabled = false;
}

void	fill_background_and_component(t_game *data)
{
	int		width;
	int		height;

	width = 0;
	height = 0;
	while (height < data->height)
	{
		width = 0;
		while (width < data->width)
		{
			if (mlx_image_to_window(data->mlx, data->images->floor,
					width * PIXELS, height * PIXELS) < 0)
				error("Failed to put image to window");
			load_component_images(data, width, height);
			width++;
		}
		height++;
	}
	fill_players_images(data);
	string_to_screen(data);
}


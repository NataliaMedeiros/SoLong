/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalia <natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:56:45 by natalia           #+#    #+#             */
/*   Updated: 2024/04/12 13:58:19 by natalia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_component_images(t_game *game, int width, int height)
{
	if (game->map[height][width] == '1')
	{
		if (mlx_image_to_window(game->mlx, game->images->wall,
				width * PIXELS, height * PIXELS) < 0)
			error("Failed to put image to window");
	}
	else if (game->map[height][width] == 'P')
	{
		if (mlx_image_to_window(game->mlx, game->images->player,
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
}

void	fill_background(t_game *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (mlx_image_to_window(data->mlx, data->images->floor,
					x * PIXELS, y * PIXELS) < 0)
				error("Failed to put image to window");
			x++;
		}
		y++;
	}
}

void	fill_components(t_game	*game)
{
	int		width;
	int		height;

	width = 0;
	height = 0;
	while (height < game->height)
	{
		width = 0;
		while (width < game->width)
		{
			load_component_images(game, width, height);
			width++;
		}
		height++;
	}
}

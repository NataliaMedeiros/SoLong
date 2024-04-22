/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   images.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/12 13:56:45 by natalia       #+#    #+#                 */
/*   Updated: 2024/04/22 12:31:33 by nmedeiro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	*initialize_images(mlx_t	*mlx)
{
	t_image	*images;

	images = ft_calloc(1, sizeof(t_image));
	if (!images)
		return (NULL);
	images = load_floor_texture(mlx, images);
	images = load_wall_texture(mlx, images);
	images = load_player_texture(mlx, images);
	images = load_collectable_texture(mlx, images);
	images = load_exit_texture(mlx, images);
	return (images);
}

static void	load_component_images(t_game *game, int width, int height)
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
}

void	put_images_on_window(t_game *data)
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
}

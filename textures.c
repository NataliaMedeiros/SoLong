/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalia <natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:35:18 by natalia           #+#    #+#             */
/*   Updated: 2024/04/14 14:57:47 by natalia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	*load_floor_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*floor;

	floor = mlx_load_png("./images/grass.png");
	if (!floor)
		error("Problem loading floor image");
	image->floor = mlx_texture_to_image(mlx, floor);
	if (!image->floor)
		error("Problem floor texture to image");
	mlx_delete_texture (floor);
	return (image);
}

t_image	*load_wall_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*wall;

	wall = mlx_load_png("./images/tree2.png");
	if (!wall)
		error("Problem loading wall image");
	image->wall = mlx_texture_to_image(mlx, wall);
	if (!image->wall)
		error("Problem wall texture to image");
	mlx_delete_texture (wall);
	return (image);
}

t_image	*load_player_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*player;

	player = mlx_load_png("./images/player.png");
	if (!player)
		error("Problem loading player image");
	image->player = mlx_texture_to_image(mlx, player);
	if (!image->player)
		error("Problem player texture to image");
	mlx_delete_texture (player);
	return (image);
}

t_image	*load_collectable_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*collectable;

	collectable = mlx_load_png("./images/collectable.png");
	if (!collectable)
		error("Problem loading player image");
	image->collectable = mlx_texture_to_image(mlx, collectable);
	if (!image->collectable)
		error("Problem player texture to image");
	mlx_delete_texture (collectable);
	return (image);
}

t_image	*load_exit_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*exit;

	exit = mlx_load_png("./images/exit4.png");
	if (!exit)
		error("Problem loading player image");
	image->exit = mlx_texture_to_image(mlx, exit);
	if (!image->exit)
		error("Problem player texture to image");
	mlx_delete_texture (exit);
	return (image);
}

t_image	*load_yeow_texture(mlx_t *mlx, t_image *image) // TODO remove if didn't work
{
	mlx_texture_t	*youw;

	youw = mlx_load_png("./images/Yeow!.png");
	if (!youw)
		error("Problem loading player image");
	image->yeow = mlx_texture_to_image(mlx, youw);
	if (!image->yeow)
		error("Problem player texture to image");
	mlx_delete_texture (youw);
	return (image);
}

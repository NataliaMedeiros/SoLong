/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/12 10:35:18 by natalia       #+#    #+#                 */
/*   Updated: 2024/04/18 12:30:32 by nmedeiro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	*load_floor_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*floor;

	floor = mlx_load_png("./images/grass.png");
	if (!floor)
		exit_error("Problem loading wall image");
	image->floor = mlx_texture_to_image(mlx, floor);
	if (!image->floor)
		exit_error("Problem floor texture to image");
	mlx_delete_texture (floor);
	return (image);
}

t_image	*load_wall_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*wall;

	wall = mlx_load_png("./images/tree.png");
	if (!wall)
		exit_error("Problem loading wall image");
	image->wall = mlx_texture_to_image(mlx, wall);
	if (!image->wall)
		exit_error("Problem wall texture to image");
	mlx_delete_texture (wall);
	return (image);
}

t_image	*load_player_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*player;

	player = mlx_load_png("./images/player.png");
	if (!player)
		exit_error("Problem loading player image");
	image->player = mlx_texture_to_image(mlx, player);
	if (!image->player)
		exit_error("Problem player texture to image");
	mlx_delete_texture (player);
	return (image);
}

t_image	*load_walk_player_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*player_right;

	player_right = mlx_load_png("./images/player_right.png");
	if (!player_right)
		exit_error("Problem loading player right image");
	image->player_right = mlx_texture_to_image(mlx, player_right);
	if (!image->player_right)
		exit_error("Problem player texture to image");
	mlx_delete_texture (player_right);
	return (image);
}

t_image	*load_player_left_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*player_left;

	player_left = mlx_load_png("./images/player_left.png");
	if (!player_left)
		exit_error("Problem loading player image");
	image->player_left = mlx_texture_to_image(mlx, player_left);
	if (!image->player_left)
		exit_error("Problem player texture to image");
	mlx_delete_texture (player_left);
	return (image);
}

t_image	*load_collectable_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*collectable;

	collectable = mlx_load_png("./images/collectable.png");
	if (!collectable)
		exit_error("Problem loading player image");
	image->collectable = mlx_texture_to_image(mlx, collectable);
	if (!image->collectable)
		exit_error("Problem player texture to image");
	mlx_delete_texture (collectable);
	return (image);
}

t_image	*load_exit_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*exit;

	exit = mlx_load_png("./images/closed_door.png");
	if (!(exit))
		exit_error("Problem loading player image");
	image->exit = mlx_texture_to_image(mlx, exit);
	if (!image->exit)
		exit_error("Problem player texture to image");
	mlx_delete_texture (exit);
	return (image);
}

t_image	*load_open_exit_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*open_exit;

	open_exit = mlx_load_png("./images/open_door.png");
	if (!open_exit)
		exit_error("Problem loading player image");
	image->open_exit = mlx_texture_to_image(mlx, open_exit);
	if (!image->open_exit)
		exit_error("Problem player texture to image");
	mlx_delete_texture (open_exit);
	return (image);
}

t_image	*load_yeow_texture(mlx_t *mlx, t_image *image) // TODO remove if didn't work
{
	mlx_texture_t	*youw;

	youw = mlx_load_png("./images/Yeow!.png");
	if (!youw)
		exit_error("Problem loading player image");
	image->yeow = mlx_texture_to_image(mlx, youw);
	if (!image->yeow)
		exit_error("Problem player texture to image");
	mlx_delete_texture (youw);
	return (image);
}

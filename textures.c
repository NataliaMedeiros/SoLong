/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/12 10:35:18 by natalia       #+#    #+#                 */
/*   Updated: 2024/04/22 12:19:03 by nmedeiro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	*load_floor_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*floor;

	floor = mlx_load_png("./images/grass.png");
	if (!floor)
		exit_error("Problem loading floor image");
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

t_image	*load_collectable_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*collectable;

	collectable = mlx_load_png("./images/chest.png");
	if (!collectable)
		exit_error("Problem loading chest image");
	image->collectable = mlx_texture_to_image(mlx, collectable);
	if (!image->collectable)
		exit_error("Problem chest texture to image");
	mlx_delete_texture (collectable);
	return (image);
}

t_image	*load_exit_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*exit;

	exit = mlx_load_png("./images/closed_door.png");
	if (!(exit))
		exit_error("Problem loading closed door image");
	image->exit = mlx_texture_to_image(mlx, exit);
	if (!image->exit)
		exit_error("Problem closed door texture to image");
	mlx_delete_texture (exit);
	return (image);
}


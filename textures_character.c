/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures_character.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/19 13:13:19 by natalia       #+#    #+#                 */
/*   Updated: 2024/04/19 13:15:47 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

t_image	*load_player_right_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*player_right;

	player_right = mlx_load_png("./images/player_right.png");
	if (!player_right)
		exit_error("Problem loading player right image");
	image->player_right = mlx_texture_to_image(mlx, player_right);
	if (!image->player_right)
		exit_error("Problem player right texture to image");
	mlx_delete_texture (player_right);
	return (image);
}

t_image	*load_player_left_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*player_left;

	player_left = mlx_load_png("./images/player_left.png");
	if (!player_left)
		exit_error("Problem loading player left image");
	image->player_left = mlx_texture_to_image(mlx, player_left);
	if (!image->player_left)
		exit_error("Problem player left texture to image");
	mlx_delete_texture (player_left);
	return (image);
}

t_image	*load_player_dead_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*player_dead;

	player_dead = mlx_load_png("./images/player_dead2.png");
	if (!player_dead)
		exit_error("Problem loading player dead image");
	image->player_dead = mlx_texture_to_image(mlx, player_dead);
	if (!image->player_dead)
		exit_error("Problem player dead texture to image");
	mlx_delete_texture (player_dead);
	return (image);
}

t_image	*load_enemy_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*enemy;

	enemy = mlx_load_png("./images/dino_iddle.png");
	if (!enemy)
		exit_error("Problem loading enemy image");
	image->enemy = mlx_texture_to_image(mlx, enemy);
	if (!image->enemy)
		exit_error("Problem enemy texture to image");
	mlx_delete_texture (enemy);
	return (image);
}

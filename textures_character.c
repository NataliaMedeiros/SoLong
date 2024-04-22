/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures_character.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/19 13:13:19 by natalia       #+#    #+#                 */
/*   Updated: 2024/04/22 12:18:26 by nmedeiro      ########   odam.nl         */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalia <natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:52:29 by natalia           #+#    #+#             */
/*   Updated: 2024/04/12 14:38:21 by natalia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <string.h>

# define PIXELS 64

typedef struct s_image
{
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*player;
	mlx_image_t	*collectable;
	mlx_image_t	*exit;
}				t_image;

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	mlx_t	*mlx;
	t_image	*images;
	int		player_position_x; //row
	int		player_position_y; //collum
	// TO DO: still implement elements (if add somenthing change on in initialize game)
}				t_game;

typedef struct s_vector2D
{
	int	x;
	int	y;
}	t_vector2D;


/*error_utils*/
void	exit_error(char *error_message);
int		error(char *error_message);
int		rowlen(char **map);

/*handle_errors*/
void	check_map_extention(char *argv);
bool	valid_map(char **map);

/*free_utils*/
void	free_array(char **args);
void	free_array_and_exit(char **args);

/*textures*/
t_image	*load_floor_texture(mlx_t *mlx, t_image *image);
t_image	*load_wall_texture(mlx_t *mlx, t_image *image);
t_image	*load_player_texture(mlx_t *mlx, t_image *image);
t_image	*load_collectable_texture(mlx_t *mlx, t_image *image);
t_image	*load_exit_texture(mlx_t *mlx, t_image *image);

/*fill_images*/
void	fill_background(t_game *data);
void	fill_components(t_game	*game);
void	load_component_images(t_game *game, int width, int height);

/*movements*/
t_game	*move_up(t_game	*game);
t_game	*move_down(t_game	*game);
t_game	*move_right(t_game	*game);
t_game	*move_left(t_game	*game);

#endif

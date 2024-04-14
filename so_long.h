/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalia <natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:52:29 by natalia           #+#    #+#             */
/*   Updated: 2024/04/14 20:23:45 by natalia          ###   ########.fr       */
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
	mlx_image_t	*yeow;
	mlx_image_t	*moves_print;
	mlx_image_t	*collected_print;
}				t_image;

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	mlx_t	*mlx;
	t_image	*images;
	int		player_position_x;
	int		player_position_y;
	int		exit_position_x;
	int		exit_position_y;
	int		total_collectable;
	int		collected_collectables;
	int		total_moves;
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
int		height_map(char **map);

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
t_image	*load_yeow_texture(mlx_t *mlx, t_image *image);

/*fill_images*/
void	fill_background(t_game *data);
void	fill_components(t_game	*game);
void	load_component_images(t_game *game, int width, int height);

/*movements*/
t_game	*move_up(t_game	*game);
t_game	*move_down(t_game	*game);
t_game	*move_right(t_game	*game);
t_game	*move_left(t_game	*game);
void	ft_hook_moves(mlx_key_data_t key_data, void *mlx);

/*game_checker*/
void	collected_all_collectable(t_game *game);
void	look_for_collectable(int height, int width, t_game *game);

/*initialize_game*/
void	initialize_game_data(t_game **game, char **map);
void	set_player_position(t_game	**game);
void	set_exit_position(t_game	**game);
void	count_collectables(t_game	**game);

/*check_path*/
bool	valid_path(t_game *game);

#endif

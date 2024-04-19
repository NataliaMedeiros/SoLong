/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/09 10:52:29 by natalia       #+#    #+#                 */
/*   Updated: 2024/04/19 15:13:40 by natalia       ########   odam.nl         */
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
	mlx_image_t	*player_right;
	mlx_image_t	*player_left;
	mlx_image_t	*player_dead;
	mlx_image_t	*enemy;
	mlx_image_t	*collectable;
	mlx_image_t	*exit;
	mlx_image_t	*open_exit;
	mlx_image_t	*yeow;
	mlx_image_t	*moves_print;
	mlx_image_t	*collected_print;
	mlx_image_t	*winner_message;
	mlx_image_t	*game_over;
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
}				t_game;

typedef struct s_vector2D
{
	int	x;
	int	y;
}	t_vector2D;

/*check_path*/
bool	valid_path(t_game *game);

/*error_utils*/
void	exit_error(char *error_message);
int		error(char *error_message);

/*handle_errors*/
bool	check_map_extention(char *argv);
bool	valid_map(char **map);

/*fill_images*/
void	fill_background_and_component(t_game *data);

/*free_utils*/
void	free_array(char **args);
void	free_array_and_exit(char **args);
void	free_node(t_game **game);

/*game_checker*/
void	look_for_collectable(int height, int width, t_game *game);
bool	hit_on_enemy(t_game *game, int height, int width);
void	collected_all_collectable(t_game *game);

/*handle_errors*/
bool	check_map_extention(char *argv);
bool	valid_map(char **map);

/*initialize_game*/
void	count_collectables(t_game	**game);
t_game	*initialize_game_data(char **map);

/*movements*/
void	ft_hook_moves(mlx_key_data_t key_data, void *mlx);

/*print_on_screen*/
void	string_to_screen(t_game *game);
void	print_moves(t_game *game);
void	print_collectables(t_game	*game);

/*texture_characters*/
t_image	*load_player_texture(mlx_t *mlx, t_image *image);
t_image	*load_player_right_texture(mlx_t *mlx, t_image *image);
t_image	*load_player_left_texture(mlx_t *mlx, t_image *image);
t_image	*load_player_dead_texture(mlx_t *mlx, t_image *image);
t_image	*load_enemy_texture(mlx_t *mlx, t_image *image);

/*textures*/
t_image	*load_floor_texture(mlx_t *mlx, t_image *image);
t_image	*load_wall_texture(mlx_t *mlx, t_image *image);
t_image	*load_collectable_texture(mlx_t *mlx, t_image *image);
t_image	*load_exit_texture(mlx_t *mlx, t_image *image);
t_image	*load_game_over_texture(mlx_t *mlx, t_image *image);

/*utils*/
int		height_map(char **map);
int		count_rows(const char *argv);
void	disable_image(t_game *game);

#endif

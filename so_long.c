/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/09 10:52:38 by natalia       #+#    #+#                 */
/*   Updated: 2024/04/19 17:31:02 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	read_map(char **map, const char *argv)
{
	int		fd;
	int		i;
	char	*line;
	int		len_line;

	fd = open(argv, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		len_line = ft_strlen(line);
		map[i] = malloc(len_line + 1);
		map[i] = ft_strcpy(map[i], line);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

static t_image	*initialize_images(mlx_t	*mlx)
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
	images = load_player_right_texture(mlx, images);
	images = load_player_left_texture(mlx, images);
	images = load_enemy_texture(mlx, images);
	images = load_player_dead_texture(mlx, images);
	images = load_game_over_texture(mlx, images);
	return (images);
}

int	main(int argc, char **argv)
{
	char	**map;
	t_game	*game;

	if (argc != 2 || (!check_map_extention(argv[1])))
		exit_error("Check file: no input or incorret file type");
	map = ft_calloc((count_rows(argv[1]) + 1), sizeof(char *));
	if (!map)
		exit_error("Fail to allocate memory to map");
	read_map(map, argv[1]);
	game = initialize_game_data(map);
	if (game == NULL)
		return (free_array(map), EXIT_FAILURE);
	game->mlx = mlx_init((game)->width * PIXELS, (game)->height * PIXELS,
			"SoLong", false);
	if (!(game)->mlx)
		return (free_array(map), free(game), EXIT_FAILURE);
	game->images = initialize_images(game->mlx);
	if (!game->images)
		return (free_array(map), free_node(&game), EXIT_FAILURE);
	put_images_on_window(game);
	mlx_key_hook(game->mlx, ft_hook_moves, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (free(game->images), free_array(map), free(game), EXIT_SUCCESS);
}

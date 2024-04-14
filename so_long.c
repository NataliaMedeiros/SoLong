/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalia <natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:52:38 by natalia           #+#    #+#             */
/*   Updated: 2024/04/14 20:54:31 by natalia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_rows(const char *argv) //TODO - check if stays here or move to a utils file
{
	int		nb_lines;
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		exit_error("Nonexistent map");
	line = get_next_line(fd);
	if (line == NULL)
		exit_error("Empty map");
	//checar qual o minimo de rows (talvez 3) em um valid map e se preciso fazer validation
	nb_lines = 0;
	while (line != NULL)
	{
		nb_lines++;
		free(line);
		line = get_next_line(fd);
	}
	return (nb_lines);
}

void	read_map(char **map, const char *argv)
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

t_image	*initialize_images_data(mlx_t	*mlx)
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
	images = load_open_exit_texture(mlx, images);
	images = load_yeow_texture(mlx, images); //TODO if don't work delete
	return (images);
}

void	print_map(char **map) //TO DO remove function
{
	int	i;

	i = 0;
	printf("after reading map:\n");
	while (map[i] != NULL)
	{
		printf("%s", map[i]);
		i++;
	}
}

void	string_to_screen(t_game *game)
{
	char	*temp;
	char	colected_print[20];

	temp = ft_itoa(game->total_collectable);
	strcpy(colected_print, "Collected: 0/");
	strcat(colected_print, temp);
	game->images->moves_print = mlx_put_string(game->mlx, "Moves: 0",
			16, game->height * 64 - 350);
	game->images->collected_print = mlx_put_string(game->mlx, colected_print,
			16, game->height * 64 - 370);
}

int	main(int argc, char **argv)
{
	char	**map;
	t_game	*game;

	if (argc != 2)
		exit_error("No input");
	check_map_extention(argv[1]);
	map = ft_calloc((count_rows(argv[1]) + 1), sizeof(char *));
	if (!map)
		return (EXIT_FAILURE);
	read_map(map, argv[1]);
	if (!valid_map(map))
		free_array_and_exit(map);
	game = ft_calloc(1, sizeof(t_game));
	if (game == NULL)
		return (EXIT_FAILURE);
	initialize_game_data(&game, map);
	game->images = initialize_images_data(game->mlx);
	fill_background(game);
	fill_components(game);
	if (!valid_path(game))
		printf("path not valid\n");
	string_to_screen(game);
	mlx_key_hook(game->mlx, ft_hook_moves, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}

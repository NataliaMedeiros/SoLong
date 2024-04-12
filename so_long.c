/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalia <natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:52:38 by natalia           #+#    #+#             */
/*   Updated: 2024/04/12 14:39:39 by natalia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_rows(const char *argv)
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
		//printf("%s", line);
		nb_lines++;
		free(line);
		line = get_next_line(fd);
	}
	//printf("line = %d\n", nb_lines);
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

t_game	*initialize_game_data(char **map)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (game == NULL)
		return (game);
	game->map = map;
	game->height = rowlen(map);
	game->width = ft_strlen_nl(map[0]);
	game->mlx = mlx_init(game->width * PIXELS, game->height * PIXELS,
			"SoLong", true);
	if (!game->mlx)
		free_array_and_exit(map);
	return (game);
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
	return (images);
}

//TO DO remove function
void	print_map(char **map)
{
	int i;

	i = 0;
	printf("after reading map:\n");
	while (map[i] != NULL)
	{
		printf("%s", map[i]);
		i++;
	}
}

void	set_player_position(t_game	**game)
{
	int	x;
	int	y;

	x = 0;
	while (x < (*game)->height)
	{
		y = 0;
		while (y < (*game)->width)
		{
			if ((*game)->map[x][y] == 'P')
			{
				(*game)->player_position_x = x; //coluna
				(*game)->player_position_y = y; //linha
				return ;
			}
			y++;
		}
		x++;
	}
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
		free_array_and_exit(map); //TO DO testar se ficou sem leaks mesmo
	game = initialize_game_data(map);
	game->images = initialize_images_data(game->mlx);
	printf("Image initialized\n");
	fill_background(game);
	fill_components(game);
	set_player_position(&game);
	printf("x = %d and y = %d\n", game->player_position_x, game->player_position_y);
	game = move_up(game);
	game = move_right(game);
	game = move_down(game);
	game = move_left(game);
	printf("background filled with success\n");
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}

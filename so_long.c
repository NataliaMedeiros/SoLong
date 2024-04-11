/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/09 10:52:38 by natalia       #+#    #+#                 */
/*   Updated: 2024/04/11 15:02:53 by natalia       ########   odam.nl         */
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
	return (game);
}

t_image	*load_grass_texture(mlx_t *mlx, t_image *img)
{
	mlx_texture_t	*grass;

	grass = mlx_load_png("./images/Grass2.png");
	if (!grass)
		error("Problem with loading png");
	img->grass = mlx_texture_to_image(mlx, grass);
	if (!img->grass)
		error("Problem with texture to image");
	mlx_delete_texture (grass);
	return (img);
}

t_image	*initialize_images_data(mlx_t	*mlx)
{
	t_image	*images;

	printf("Inside of initialize_images_data");
	images = ft_calloc(1, sizeof(t_image));
	if (!images)
		return (NULL);
	images = load_grass_texture(mlx, images);
	return (images);
}

void	fill_background(t_game *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (mlx_image_to_window(data->mlx, data->images->grass,
					x * 64, y * 64) < 0)
				error("Failed to put image to window");
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	char	**map;
	t_game	*game;
	// t_image	*images;

	if (argc != 2)
		exit_error("No input");
	check_map_extention(argv[1]);
	map = ft_calloc((count_rows(argv[1]) + 1), sizeof(char *));
	if (!map)
		return (1);
	read_map(map, argv[1]);
	int i = 0;//just to print
	printf("after reading map:\n");
	while (map[i] != NULL)
	{
		printf("%s", map[i]);
		i++;
	}
	if (!valid_map(map))
		free_array_and_exit(map); //TO DO testar se ficou sem leaks mesmo
	game = initialize_game_data(map);
	printf("%d, %d\n", game->height, game->width);
	/*start mlx*/
	game->mlx = mlx_init(game->height, game->width, "SoLong", false);
	if (!game->mlx)
		free_array_and_exit(map);
	printf("Game_data successuful initialized\n");
	/*create a new image*/
	mlx_image_t* img = mlx_new_image(game->mlx, 512, 512);
	if (!img)
		error("Erro na criacao da imagem\n");

	// Set every pixel to white
	memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));

	// Display an instance of the image
	if (mlx_image_to_window(game->mlx, img, 0, 0) < 0)
        error("Erro on display image instance\n");

	// images = initialize_images_data(game->mlx);
	// game->images = images;
	// fill_background(game);
	// printf("background filled with success\n");
	mlx_loop(game->mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/09 10:52:38 by natalia       #+#    #+#                 */
/*   Updated: 2024/04/11 12:15:03 by natalia       ########   odam.nl         */
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

int	main(int argc, char **argv)
{
	char	**map;
	t_game	*game;

	if (argc != 2)
		exit_error("No input");
	check_map_extention(argv[1]);
	map = ft_calloc((count_rows(argv[1]) + 1), sizeof(char *));
	if (!map)
		return (1);
	read_map(map, argv[1]);
	// int i = 0;//just to print
	// printf("after reading map:\n");
	// while (map[i] != NULL)
	// {
	// 	printf("%s", map[i]);
	// 	i++;
	// }
	if (!valid_map(map))
	{
		free_array(map);
		exit(1);
	}
	game = initialize_game_data(map);
	mlx_init(game->height, game->width, "SoLong", false);
}

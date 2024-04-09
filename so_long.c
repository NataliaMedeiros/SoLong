/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/09 10:52:38 by natalia       #+#    #+#                 */
/*   Updated: 2024/04/09 17:30:40 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_rows(const char *argv)
{
	int		nb_lines;
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		exit_error("Empty or nonextent map");
	//checar qual o minimo de rows (talvez 3) em um valid map e se preciso fazer validation
	nb_lines = 0;
	while (line != NULL)
	{
		//printf("%s", line);
		nb_lines++;
		line = get_next_line(fd);
	}
	//printf("line = %d\n", nb_lines);
	return (nb_lines);
}

char	**read_map(const char *argv)
{
	char	**map;
	int		fd;
	int		i;
	char	*line;
	int		len_line;

	map = (char **)malloc((count_rows(argv) + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	fd = open(argv, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		len_line = ft_strlen(line);
		//printf("len line = %d\n", len_line);
		map[i] = malloc(len_line + 1);
		map[i] = ft_strcpy(map[i], line);
		//printf("map[%d] = %s", i, map[i]);
		i++;
		line = get_next_line(fd);
	}
	return (map);
}

int	main(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
		exit_error("No input");
	check_extention(argv[1]);
	map = read_map(argv[1]);
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
}

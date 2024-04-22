/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/19 14:28:55 by natalia       #+#    #+#                 */
/*   Updated: 2024/04/22 12:19:14 by nmedeiro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	height_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

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
	nb_lines = 0;
	while (line != NULL)
	{
		nb_lines++;
		free(line);
		line = get_next_line(fd);
	}
	printf("number lines = %d\n", nb_lines);
	return (nb_lines);
}

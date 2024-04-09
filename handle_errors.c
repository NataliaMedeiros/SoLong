/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_errors.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/09 11:35:17 by natalia       #+#    #+#                 */
/*   Updated: 2024/04/09 15:25:38 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_array(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	while (i >= 0)
		free (args[i--]);
	if (args)
		free (args);
}

void	exit_error(char *error_message)
{
	ft_putendl_fd(2, "Error");
	ft_putendl_fd(2, error_message);
	exit (1);
}

int	error(char *error_message)
{
	ft_putendl_fd(2, "Error");
	ft_putendl_fd(2, error_message);
	return (1);
}

void	check_extention(char *argv)
{
	char	*str;
	char	*error_message;

	error_message = "Incorrect file type";
	str = ft_strchr(argv, '.');
	if (str == NULL || (ft_strcmp(str, ".ber")) != 0)
		exit_error(error_message);
}

int	rowlen(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

void	check_map(char **map)
{
	int	i;
	int	j;
	int	p;
	int	e;
	int	c;

	i = 0;
	p = 0;
	e = 0;
	c = 0;
	while(map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\n')
		{
			if ((i == 0 || j == 0 || i == rowlen(map) - 1
					|| j == (int)ft_strlen(map[i]) - 2) && map[i][j] != '1')
				exit_error("Invalid wall");
			if (map[i][j] == 'P')
				p++;
			else if (map[i][j] == 'E')
				e++;
			else if (map[i][j] == 'C')
				c++;
			else if (map[i][j] != '1' && map[i][j] != '0')
				exit_error("Ivalid component, check map");
			j++;
		}
		i++;
	}
	if (p != 1 || e != 1 | c < 1)
		exit_error("Check amount of player, exit and colectables");
}

bool	valid_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\n')
		{
			check_wall(map[i][j]);
			j++;
		}
		i++;
	}
	return (false);
}

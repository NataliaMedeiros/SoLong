/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_errors.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/09 11:35:17 by natalia       #+#    #+#                 */
/*   Updated: 2024/04/11 13:22:52 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_extention(char *argv)
{
	char	*str;
	char	*error_message;

	error_message = "Incorrect file type";
	str = ft_strchr(argv, '.');
	if (str == NULL || (ft_strcmp(str, ".ber")) != 0)
		exit_error(error_message);
}

int	count_component(char **map, char c)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	nb = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\n')
		{
			if (map[i][j] == c)
				nb++;
			j++;
		}
		i++;
	}
	return (nb);
}

bool	valid_wall_and_components(char **map)
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
			if ((i == 0 || j == 0 || i == rowlen(map) - 1
					|| j == ft_strlen_nl(map[i]) - 1) && map[i][j] != '1')
				return (error("Invalid wall"), false);
			else if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P'
				&& map[i][j] != 'E' && map[i][j] != 'C')
				return (error("invalid component"), false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_map_shape(char **map)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(map[i]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (false);
		i++;
	}
	return (true);
}

bool	valid_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (check_map_shape(map) == false)
		return (error("Map is not rectangular"), false);
	if (!valid_wall_and_components(map))
		return (false);
	if (count_component(map, 'P') != 1)
		return (error("Check Player's amount"), false);
	if (count_component(map, 'E') != 1)
		return (error("Check Exit's amount"), false);
	if (count_component(map, 'C') < 1)
		return (error("Check Colectable's amount"), false);
	return (true);
}

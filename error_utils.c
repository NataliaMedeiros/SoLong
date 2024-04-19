/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/09 17:36:43 by natalia       #+#    #+#                 */
/*   Updated: 2024/04/19 11:13:43 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error(char *error_message)
{
	ft_putendl_fd(2, "Error");
	ft_putendl_fd(2, error_message);
	return (1);
}

void	exit_error(char *error_message)
{
	error(error_message);
	exit (EXIT_FAILURE);
}

int	height_map(char **map) //TODO check where this function has been used
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

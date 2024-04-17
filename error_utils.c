/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalia <natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:36:43 by natalia           #+#    #+#             */
/*   Updated: 2024/04/16 11:01:21 by natalia          ###   ########.fr       */
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
	exit (1);
}

void	error_free_and_exit(char *error_message) //TODO check where this function bem used to fix it
{
	//TODO incomplete funtions, freeing nothing
	error(error_message);
	exit (1);
}

int	height_map(char **map) //TODO check where this function has been used
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

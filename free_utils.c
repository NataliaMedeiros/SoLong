/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalia <natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:23:02 by natalia           #+#    #+#             */
/*   Updated: 2024/04/16 10:01:10 by natalia          ###   ########.fr       */
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

void	free_array_and_exit(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	while (i >= 0)
		free (args[i--]);
	if (args)
		free (args);
	exit (1);
}

void	free_node(t_game **game)
{
	if ((*game)->images)
		free((*game)->images);
	free(game);
	*game = NULL;
}

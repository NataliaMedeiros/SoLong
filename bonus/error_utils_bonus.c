/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_utils_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/09 17:36:43 by natalia       #+#    #+#                 */
/*   Updated: 2024/04/22 11:31:17 by nmedeiro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

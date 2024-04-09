/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/09 10:52:29 by natalia       #+#    #+#                 */
/*   Updated: 2024/04/09 17:40:24 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>

/*error_utils*/
void	exit_error(char *error_message);
int		error(char *error_message);
int		rowlen(char **map);

/*handle_errors*/
void	check_extention(char *argv);
bool	valid_map(char **map);

/*free_utils*/
void	free_array(char **args);


#endif

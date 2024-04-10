/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/09 10:52:29 by natalia       #+#    #+#                 */
/*   Updated: 2024/04/10 14:16:09 by nmedeiro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	// TO DO: still implement elements (if add somenthing change on in initialize game)
}				t_game;


/*error_utils*/
void	exit_error(char *error_message);
int		error(char *error_message);
int		rowlen(char **map);

/*handle_errors*/
void	check_map_extention(char *argv);
bool	valid_map(char **map);

/*free_utils*/
void	free_array(char **args);


#endif

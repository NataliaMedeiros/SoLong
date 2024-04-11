/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/09 10:52:29 by natalia       #+#    #+#                 */
/*   Updated: 2024/04/11 15:02:21 by natalia       ########   odam.nl         */
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
# include <string.h>

typedef struct s_image
{
	mlx_image_t	*grass;
}				t_image;

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	mlx_t	*mlx;
	t_image	*images;
	// TO DO: still implement elements (if add somenthing change on in initialize game)
}				t_game;

typedef struct s_vector2D
{
	int	x;
	int	y;
}	t_vector2D;


/*error_utils*/
void	exit_error(char *error_message);
int		error(char *error_message);
int		rowlen(char **map);

/*handle_errors*/
void	check_map_extention(char *argv);
bool	valid_map(char **map);

/*free_utils*/
void	free_array(char **args);
void	free_array_and_exit(char **args);


#endif

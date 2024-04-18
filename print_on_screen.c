/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_on_screen.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmedeiro <nmedeiro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/18 12:34:13 by nmedeiro      #+#    #+#                 */
/*   Updated: 2024/04/18 13:47:33 by nmedeiro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_moves(t_game *game)
{
	char	*temp;
	char	print_moves[20];

	temp = ft_itoa(game->total_moves);
	strcpy(print_moves, "Moves: ");
	strcat(print_moves, temp);
	mlx_delete_image(game->mlx, game->images->moves_print);
	game->images->moves_print = mlx_put_string(game->mlx, print_moves,
			16, game->height * 64 - 350);
	free(temp);
}

void	print_collectables(t_game	*game)
{
	char	*temp;
	char	print_collectables[20];

	temp = ft_itoa(game->collected_collectables);
	strcpy(print_collectables, "Collected: ");
	strcat(print_collectables, temp);
	free(temp);
	strcat(print_collectables, "/");
	temp = ft_itoa(game->total_collectable);
	strcat(print_collectables, temp);
	mlx_delete_image(game->mlx, game->images->collected_print);
	game->images->collected_print = mlx_put_string(game->mlx,
			print_collectables, 16, game->height * 64 - 370);
	free(temp);
}
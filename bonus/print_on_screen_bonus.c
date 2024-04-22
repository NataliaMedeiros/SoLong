/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_on_screen_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/18 12:34:13 by nmedeiro      #+#    #+#                 */
/*   Updated: 2024/04/22 12:27:30 by nmedeiro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	string_to_screen(t_game *game)
{
	char	*temp;
	char	colected_print[20];

	temp = ft_itoa(game->total_collectable);
	ft_strcpy(colected_print, "Collected: 0/");
	ft_strcat(colected_print, temp);
	game->images->moves_print = mlx_put_string(game->mlx, "Moves: 0",
			16, 16);
	game->images->collected_print = mlx_put_string(game->mlx, colected_print,
			16, 36);
	free(temp);
}

void	print_moves(t_game *game)
{
	char	*temp;
	char	print_moves[20];

	temp = ft_itoa(game->total_moves);
	ft_strcpy(print_moves, "Moves: ");
	ft_strcat(print_moves, temp);
	mlx_delete_image(game->mlx, game->images->moves_print);
	game->images->moves_print = mlx_put_string(game->mlx, print_moves,
			16, 16);
	free(temp);
}

void	print_collectables(t_game	*game)
{
	char	*temp;
	char	print_collectables[20];

	temp = ft_itoa(game->collected_collectables);
	ft_strcpy(print_collectables, "Collected: ");
	ft_strcat(print_collectables, temp);
	free(temp);
	ft_strcat(print_collectables, "/");
	temp = ft_itoa(game->total_collectable);
	ft_strcat(print_collectables, temp);
	mlx_delete_image(game->mlx, game->images->collected_print);
	game->images->collected_print = mlx_put_string(game->mlx,
			print_collectables, 16, 36);
	free(temp);
}

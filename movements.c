/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalia <natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:01:35 by natalia           #+#    #+#             */
/*   Updated: 2024/04/12 14:38:55 by natalia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*move_up(t_game	*game)
{
	game->player_position_x--;
	printf("new player position x: %d, y:%d\n", game->player_position_x, game->player_position_y);
	return (game);
}

t_game	*move_down(t_game	*game)
{
	game->player_position_x++;
	printf("new player position x: %d, y:%d\n", game->player_position_x, game->player_position_y);
	return (game);
}

t_game	*move_right(t_game	*game)
{
	game->player_position_y++;
	printf("new player position x: %d, y:%d\n", game->player_position_x, game->player_position_y);
	return (game);
}

t_game	*move_left(t_game	*game)
{
	game->player_position_y--;
	printf("new player position x: %d, y:%d\n", game->player_position_x, game->player_position_y);
	return (game);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen_up_to_nl.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/09 11:02:52 by natalia       #+#    #+#                 */
/*   Updated: 2024/04/09 15:10:09 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_up_to_nl(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\n')
		len++;
	return (len);
}

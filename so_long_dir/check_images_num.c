/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_images_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <asaadeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:20:51 by asaadeh           #+#    #+#             */
/*   Updated: 2025/01/15 17:17:51 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_exit(t_game *game)
{
	int	count;
	int	y;
	int	x;

	count = 0;
	y = 0;
	x = 0;
	while (game->map->arr[y])
	{
		x = 0;
		while (game->map->arr[y][x])
		{
			if (game->map->arr[y][x] == 'E')
				count++;
			x++;
		}
		y++;
	}
	if (count == 0 || count > 1)
	{
		write(1, "Error\nthere is no exit or you have more than one\n", 50);
		return (0);
	}
	return (1);
}

int	count_player(t_game *game)
{
	int	count;
	int	y;
	int	x;

	count = 0;
	y = 0;
	x = 0;
	while (game->map->arr[y])
	{
		x = 0;
		while (game->map->arr[y][x])
		{
			if (game->map->arr[y][x] == 'P')
				count++;
			x++;
		}
		y++;
	}
	if (count == 0 || count > 1)
	{
		write(1, "Error\nthere is no player or you have more than one\n", 51);
		return (0);
	}
	return (1);
}

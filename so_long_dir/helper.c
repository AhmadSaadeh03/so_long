/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <asaadeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:45:48 by asaadeh           #+#    #+#             */
/*   Updated: 2025/01/15 17:23:05 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	element_check(t_game *game, int x, int y)
{
	char	current;

	current = game->map->arr[y][x];
	if (current == '1' || current == '0' || current == 'P' || current == 'C'
		|| current == 'E')
		return (0);
	return (1);
}

void	elements(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map->arr[y] != NULL)
	{
		x = 0;
		while (game->map->arr[y][x] && game->map->arr[y][x] != '\n')
		{
			if (element_check(game, x, y) == 1)
			{
				perror("Error\n Invalid character");
				exit_game(game, 0);
			}
			x++;
		}
		y++;
	}
}

void	nullfunction(t_game *game)
{
	game->map = NULL;
	game->player = NULL;
	game->image = NULL;
	game->mlx = NULL;
	game->window = NULL;
}

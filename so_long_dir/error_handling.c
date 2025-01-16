/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <asaadeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:01:10 by asaadeh           #+#    #+#             */
/*   Updated: 2025/01/15 16:44:18 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall(t_game *game)
{
	int	i;
	int	h;

	h = game->map->high;
	i = 0;
	while ((i < game->map->width))
	{
		if (game->map->arr[0][i] != '1' || game->map->arr[h - 1][i] != '1')
		{
			return (1);
		}
		i++;
	}
	i = 1;
	while (i < h - 1)
	{
		if (game->map->arr[i][0] != '1' || game->map->arr[i][game->map->width
			- 1] != '1')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	is_valid(int new_y, int new_x, t_game *game)
{
	if (new_x >= 0 && new_x < game->map->width && new_y >= 0
		&& new_y < game->map->high)
	{
		if (game->map->arr[new_y][new_x] != '1')
			return (0);
	}
	return (1);
}

int	is_rectangle(t_game *game)
{
	size_t	len;
	int		i;

	len = removeln(game->map->arr[0]);
	i = 0;
	while (game->map->arr[i])
	{
		if (removeln(game->map->arr[i]) != len
			|| removeln(game->map->arr[i]) == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	removeln(char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		len--;
	return (len);
}

void	exit_pos(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map->high)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->arr[i][j] == 'E')
			{
				game->player->exit_x = j;
				game->player->exit_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <asaadeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:41:15 by asaadeh           #+#    #+#             */
/*   Updated: 2025/01/15 17:19:08 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	**allocate_visited(int height, int width)
{
	int	**visited;
	int	i;
	int	j;

	visited = malloc(sizeof(int *) * height);
	if (!visited)
		return (NULL);
	i = -1;
	while (++i < height)
	{
		visited[i] = malloc(sizeof(int) * width);
		if (!visited[i])
		{
			while (i-- > 0)
				free(visited[i]);
			free(visited);
			return (NULL);
		}
		j = -1;
		while (++j < width)
		{
			visited[i][j] = 0;
		}
	}
	return (visited);
}

static void	free_visited(int **visited, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

static void	flood_fill_helper(t_game *game, int y, int x, int **visited)
{
	if (y < 0 || y >= game->map->high || x < 0 || x >= game->map->width)
		return ;
	if (game->map->arr[y][x] == '1' || visited[y][x])
		return ;
	visited[y][x] = 1;
	flood_fill_helper(game, y + 1, x, visited);
	flood_fill_helper(game, y - 1, x, visited);
	flood_fill_helper(game, y, x + 1, visited);
	flood_fill_helper(game, y, x - 1, visited);
}

static int	check_reachability(t_game *game, int **visited)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->high)
	{
		j = 0;
		while (j < game->map->width)
		{
			if ((game->map->arr[i][j] == 'C' || game->map->arr[i][j] == 'E')
				&& !visited[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	flood_fill(t_game *game)
{
	int	**visited;
	int	reachable;

	init_player_position(game);
	visited = allocate_visited(game->map->high, game->map->width);
	if (!visited)
		return (0);
	flood_fill_helper(game, game->player->player_y, game->player->player_x,
		visited);
	reachable = check_reachability(game, visited);
	free_visited(visited, game->map->high);
	return (reachable);
}

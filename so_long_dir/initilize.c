/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initilize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <asaadeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:09:07 by asaadeh           #+#    #+#             */
/*   Updated: 2025/01/15 17:59:39 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_lines(t_game *game, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		exit_game(game, 1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		i++;
		free(line);
	}
	close(fd);
	return (i);
}

static void	allocate_map(t_game *game, int line_count)
{
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		exit_game(game, 1);
	game->map->arr = malloc(sizeof(char *) * (line_count + 1));
	if (!game->map->arr)
	{
		exit_game(game, 1);
	}
}

t_map	*load_map(t_game *game, char **argv)
{
	int	fd;
	int	i;
	int	line_count;

	i = 0;
	line_count = count_lines(game, argv);
	if (!line_count)
		exit_game(game, 1);
	allocate_map(game, line_count);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit_game(game, 1);
	while (1)
	{
		game->map->arr[i] = get_next_line(fd);
		if (game->map->arr[i] == NULL)
			break ;
		i++;
	}
	if (i != line_count)
		exit_game(game, 1);
	close(fd);
	return (game->map);
}

void	size_map(t_game *game)
{
	int	width;
	int	height;

	height = 0;
	width = 0;
	if (game->map->arr[0])
	{
		while (game->map->arr[0][width] != '\n'
			&& game->map->arr[0][width] != '\0')
			width++;
	}
	while (game->map->arr[height])
		height++;
	game->map->high = height;
	game->map->width = width;
}

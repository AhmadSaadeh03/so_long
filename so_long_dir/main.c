/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <asaadeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:08:08 by asaadeh           #+#    #+#             */
/*   Updated: 2025/01/15 18:18:42 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_error(t_game *game)
{
	size_map(game);
	if (is_rectangle(game) == 1)
	{
		write(1, "Error\nThe map is not rectangle\n", 31);
		exit_game(game, 1);
	}
	if (check_wall(game) == 1)
	{
		write(1, "Error\nnot surrounded by walls\n", 30);
		exit_game(game, 1);
	}
	if (count_collectables(game) == 0)
	{
		write(1, "Error\nthere is no collectable\n", 30);
		exit_game(game, 1);
	}
	if (count_exit(game) == 0 || count_player(game) == 0)
		exit_game(game, 1);
	if (flood_fill(game) == 0)
	{
		write(1, "Error\nsome collectables/exits are unreachable.\n", 47);
		exit_game(game, 1);
	}
	elements(game);
}

static t_game	*init_game(char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		exit_game(game, 1);
	nullfunction(game);
	game->player = malloc(sizeof(t_player));
	if (!game->player)
		exit_game(game, 1);
	game->map = load_map(game, argv);
	if (!game->map)
		exit_game(game, 1);
	check_error(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_game(game, 1);
	game->image = init_images(game);
	if (!game->image)
		exit_game(game, 1);
	game->window = mlx_new_window(game->mlx, game->map->width * 64,
			game->map->high * 64, "so_long");
	if (!game->window)
		exit_game(game, 1);
	place_images_on_map(game);
	return (game);
}

int	main(int argc, char *argv[])
{
	t_game	*game;
	int		i;

	if (argc != 2)
		return (0);
	i = 0;
	while (argv[1][i])
		i++;
	i -= 1;
	if (argv[1][i] != 'r' || argv[1][i - 1] != 'e' || argv[1][i - 2] != 'b'
		|| argv[1][i - 3] != '.')
		return (1);
	game = init_game(argv);
	if (!game)
	{
		perror("Error\ninitializing game");
		return (1);
	}
	mlx_hook(game->window, 17, 0, free_game, game);
	mlx_key_hook(game->window, key_hook, game);
	mlx_loop(game->mlx);
	exit_game(game, 0);
}

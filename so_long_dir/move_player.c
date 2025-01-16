/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <asaadeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 20:03:02 by asaadeh           #+#    #+#             */
/*   Updated: 2025/01/15 17:31:55 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_exit(int new_y, int new_x, t_game *game)
{
	if (game->map->arr[new_y][new_x] == 'E' && count_collectables(game) == 0)
	{
		write(1, "You have reached the exit! Exiting the game...\n", 47);
		exit_game(game, 0);
	}
}

static void	update_move(int new_y, int new_x, t_game *game)
{
	game->map->arr[new_y][new_x] = 'P';
	game->map->arr[game->player->player_y][game->player->player_x] = '0';
	game->player->player_x = new_x;
	game->player->player_y = new_y;
}

static void	render_game(int new_y, int new_x, t_game *game)
{
	static int	move = 1;

	ft_putnbr_fd(move, 1);
	write(1, "\n", 1);
	move++;
	check_exit(new_y, new_x, game);
	update_move(new_y, new_x, game);
	place_images_on_map(game);
}

void	init_player_position(t_game *game)
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
			if (game->map->arr[i][j] == 'P')
			{
				game->player->player_x = j;
				game->player->player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	key_hook(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player->player_x;
	new_y = game->player->player_y;
	if (keycode == 65307)
		exit_game(game, 1);
	if ((keycode >= 65361 && keycode <= 65364) || (keycode == 97
			|| keycode == 119 || keycode == 100 || keycode == 115))
	{
		if (keycode == 65361 || keycode == 97)
			new_x -= 1;
		else if (keycode == 65362 || keycode == 119)
			new_y -= 1;
		else if (keycode == 65363 || keycode == 100)
			new_x += 1;
		else if (keycode == 65364 || keycode == 115)
			new_y += 1;
		if (is_valid(new_y, new_x, game) == 0)
			render_game(new_y, new_x, game);
	}
	return (0);
}

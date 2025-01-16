/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <asaadeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:44:59 by asaadeh           #+#    #+#             */
/*   Updated: 2025/01/15 18:30:27 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_path(t_game *game, t_image *image)
{
	if (image->img_floor)
		mlx_destroy_image(game->mlx, image->img_floor);
	if (image->img_collectable)
		mlx_destroy_image(game->mlx, image->img_collectable);
	if (image->img_exit)
		mlx_destroy_image(game->mlx, image->img_exit);
	if (image->img_player)
		mlx_destroy_image(game->mlx, image->img_player);
	if (image->img_wall)
		mlx_destroy_image(game->mlx, image->img_wall);
	free(image);
}

static void	cont_init_images(t_game *game, t_image *image)
{
	image->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&image->width_image, &image->height_image);
	if (!image->img_exit)
		check_path(game, image);
	image->img_player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			&image->width_image, &image->height_image);
	if (!image->img_player)
		check_path(game, image);
	image->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&image->width_image, &image->height_image);
	if (!image->img_wall)
		check_path(game, image);
}

t_image	*init_images(t_game *game)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	if (!image)
		exit_game(game, 1);
	image->img_floor = NULL;
	image->img_collectable = NULL;
	image->img_exit = NULL;
	image->img_player = NULL;
	image->img_wall = NULL;
	image->height_image = 64;
	image->width_image = 64;
	image->img_floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&image->width_image, &image->height_image);
	if (!image->img_floor)
		check_path(game, image);
	image->img_collectable = mlx_xpm_file_to_image(game->mlx,
			"textures/collectable.xpm", &image->width_image,
			&image->height_image);
	if (!image->img_collectable)
		check_path(game, image);
	cont_init_images(game, image);
	return (image);
}

static void	place_image_at_position(t_game *game, int x, int y)
{
	void	*image;

	exit_pos(game);
	if (game->map->arr[y][x] == '1')
		image = game->image->img_wall;
	else if (game->map->arr[y][x] == '0')
		image = game->image->img_floor;
	else if (game->map->arr[y][x] == 'P')
	{
		image = game->image->img_player;
		game->player->player_x = x;
		game->player->player_y = y;
	}
	else if (game->map->arr[y][x] == 'C')
		image = game->image->img_collectable;
	else if (count_collectables(game) != 0 && game->map->arr[y][x] == 'E')
		image = game->image->img_floor;
	else if (count_collectables(game) == 0)
	{
		game->map->arr[game->player->exit_y][game->player->exit_x] = 'E';
		image = game->image->img_exit;
	}
	else
		return ;
	mlx_put_image_to_window(game->mlx, game->window, image, x * 64, y * 64);
}

int	place_images_on_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map->arr[y] != NULL)
	{
		x = 0;
		while (game->map->arr[y][x])
		{
			place_image_at_position(game, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

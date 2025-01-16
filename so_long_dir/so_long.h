/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <asaadeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:33:01 by asaadeh           #+#    #+#             */
/*   Updated: 2025/01/15 17:30:41 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include <mlx.h>

typedef struct s_map
{
	int			high;
	int			width;
	char		**arr;
	int			count_collectable;
}				t_map;
typedef struct s_image
{
	void		*img_player;
	void		*img_wall;
	void		*img_floor;
	void		*img_collectable;
	void		*img_exit;
	int			height_image;
	int			width_image;
}				t_image;

typedef struct s_player
{
	int			player_x;
	int			player_y;
	int			exit_x;
	int			exit_y;
}				t_player;
typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_map		*map;
	t_image		*image;
	t_player	*player;
}				t_game;
void			size_map(t_game *game);
t_map			*load_map(t_game *game, char **argv);
void			open_window(t_game *game);
t_image			*init_images(t_game *game);
int				place_images_on_map(t_game *game);
int				key_hook(int keycode, t_game *game);
void			init_player_position(t_game *game);
int				is_rectangle(t_game *game);
size_t			removeln(char *line);
void			exit_game(t_game *game, int bool);
int				count_collectables(t_game *game);
int				is_valid(int new_y, int new_x, t_game *game);
int				count_exit(t_game *game);
int				count_player(t_game *game);
void			exit_pos(t_game *game);
int				check_wall(t_game *game);
int				flood_fill(t_game *game);
int				free_game(t_game *game);
void			elements(t_game *game);
void			check_path(t_game *game, t_image *image);
void			free_path(t_game *game, t_image *image);
void			nullfunction(t_game *game);
#endif
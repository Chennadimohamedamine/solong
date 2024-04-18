/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:23:32 by mochenna          #+#    #+#             */
/*   Updated: 2024/04/18 02:21:47 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	convert_img(t_solong *img)
{
	int	s;
	int	s1;
	int	f;

	s = ALL;
	s1 = 45;
	f = 100;
	img->walls = mlx_xpm_file_to_image(img->mlx, "img/walls1.xpm", &s, &s);
	img->player[0]
		= mlx_xpm_file_to_image(img->mlx, "img/player_left.xpm", &s, &s);
	img->player[1]
		= mlx_xpm_file_to_image(img->mlx, "img/player_up.xpm", &s, &s);
	img->player[2]
		= mlx_xpm_file_to_image(img->mlx, "img/player_down.xpm", &s, &s);
	img->player[3] = mlx_xpm_file_to_image(img->mlx, "img/player_.xpm", &s, &s);
	img->collect = mlx_xpm_file_to_image(img->mlx, "img/coll.xpm", &s1, &s1);
	img->close = mlx_xpm_file_to_image(img->mlx, "img/close.xpm", &f, &f);
	img->open = mlx_xpm_file_to_image(img->mlx, "img/open.xpm", &f, &f);
	img->bg = mlx_xpm_file_to_image(img->mlx, "img/bg.xpm", &f, &f);
}

void	put_image(t_solong *so_long)
{
	int	i;
	int	j;

	i = -1;
	while (++i < so_long->y)
	{
		j = 0;
		while (j < so_long->x)
		{
			if (so_long->map[i][j] == '1')
				mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
					so_long->walls, j * ALL, i * ALL);
			else if (so_long->map[i][j] == 'P')
				player_direction(so_long, i, j);
			else if (so_long->map[i][j] == 'E')
				put_exit(so_long, i, j);
			else if (so_long->map[i][j] == '0'
					|| so_long->map[i][j] == 'C')
				put_coll_and_bg(so_long, i, j);
			j++;
		}
	}
}

void	game(t_solong *so_long)
{
	get_positon(so_long->map, &so_long->event.y, &so_long->event.x);
	get_positon_exit(so_long->map, &so_long->y_e, &so_long->x_e);
	so_long->event.move = 1;
	so_long->event.collectible = all_collect(so_long->map);
	so_long->direction = 'r';
	put_image(so_long);
	mlx_key_hook(so_long->mlx_win, &key_hook, so_long);
	mlx_hook(so_long->mlx_win, 17, 0, ft_close, so_long);
}

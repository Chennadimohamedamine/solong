/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movehooks_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:43:46 by mochenna          #+#    #+#             */
/*   Updated: 2024/04/23 00:07:19 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	exit_player(t_solong *solong, int y, int x)
{
	solong->map[y][x] = 'P';
	solong->map[y][x] = '0';
	game_over(solong, "<><> you win <><>\n");
}

void	put_bg_coll(t_solong *so_long, int i, int j)
{
	if (so_long->map[i][j] == '0')
		mlx_put_image_to_window(so_long->mlx,
			so_long->mlx_win, so_long->bg, j * ALL, i * ALL);
	else if (so_long->map[i][j] == 'C')
		mlx_put_image_to_window(so_long->mlx,
			so_long->mlx_win, so_long->collect, j * ALL, i * ALL);
}

void	go_x(t_solong *solong, int i, int *y, int *x)
{
	if (solong->enm.e_dir[i] == 0)
		go_to_right(solong, i, y, x);
	else if (solong->enm.e_dir[i] == 1)
		go_to_left(solong, i, y, x);
	else if (solong->enm.e_dir[i] == 2)
		go_to_up(solong, i, y, x);
	else if (solong->enm.e_dir[i] == 3)
		go_to_down(solong, i, y, x);
}

void	animation(t_solong *solong)
{
	int	i;

	i = 0;
	mlx_clear_window(solong->mlx, solong->mlx_win);
	while (i < 2)
	{
		if (i % 2 == 0)
			go_x(solong, i, &solong->enm.e_y[i], &solong->enm.e_x[i]);
		else
			go_x(solong, i, &solong->enm.e_y[i], &solong->enm.e_x[i]);
		i++;
	}
	put_img(solong);
}

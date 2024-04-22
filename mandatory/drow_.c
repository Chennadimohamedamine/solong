/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 02:05:15 by mochenna          #+#    #+#             */
/*   Updated: 2024/04/22 23:57:06 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_exit(t_solong *so_long, int i, int j)
{
	if (so_long->map[i][j] == 'E'
			&& so_long->event.collectible != 0)
		mlx_put_image_to_window(so_long->mlx,
			so_long->mlx_win, so_long->close, j * ALL, i * ALL);
	else if (so_long->map[i][j] == 'E'
			&& so_long->event.collectible == 0)
		mlx_put_image_to_window(so_long->mlx,
			so_long->mlx_win, so_long->open, j * ALL, i * ALL);
}

void	put_coll_and_bg(t_solong *so_long, int i, int j)
{
	if (so_long->map[i][j] == '0')
		mlx_put_image_to_window(so_long->mlx,
			so_long->mlx_win, so_long->bg, j * ALL, i * ALL);
	else
		mlx_put_image_to_window(so_long->mlx,
			so_long->mlx_win, so_long->collect, j * ALL, i * ALL);
}

void	player_direction(t_solong *solong, int i, int j)
{
	if (solong->direction == 'r')
		mlx_put_image_to_window(solong->mlx,
			solong->mlx_win, solong->player[3], j * ALL, i * ALL);
	else if (solong->direction == 'l')
		mlx_put_image_to_window(solong->mlx,
			solong->mlx_win, solong->player[0], j * ALL, i * ALL);
	else if (solong->direction == 'u')
		mlx_put_image_to_window(solong->mlx,
			solong->mlx_win, solong->player[1], j * ALL, i * ALL);
	else if (solong->direction == 'd')
		mlx_put_image_to_window(solong->mlx,
			solong->mlx_win, solong->player[2], j * ALL, i * ALL);
}

int	key_hook(int keycode, t_solong *v)
{
	mlx_clear_window(v->mlx, v->mlx_win);
	if (keycode == 53)
		ft_close(v);
	else if (keycode == 0 || keycode == 123)
		move_to_left(v);
	else if (keycode == 2 || keycode == 124)
		move_to_right(v);
	else if (keycode == 13 || keycode == 126)
		move_to_up(v);
	else if (keycode == 1 || keycode == 125)
		move_to_down(v);
	put_image(v);
	return (0);
}

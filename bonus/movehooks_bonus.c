/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movehooks_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:43:46 by mochenna          #+#    #+#             */
/*   Updated: 2024/04/18 17:00:51 by mochenna         ###   ########.fr       */
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

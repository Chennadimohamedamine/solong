/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:13:18 by mochenna          #+#    #+#             */
/*   Updated: 2024/04/11 21:20:32 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void player_direction(t_solong *solong, int i, int j)
{
    if (solong->direction == 'u')
        mlx_put_image_to_window(solong->mlx, solong->mlx_win,solong->player[1], j * ALL, i * ALL);
    else if (solong->direction == 'r')
        mlx_put_image_to_window(solong->mlx, solong->mlx_win,solong->player[3], j * ALL, i * ALL);
    else if (solong->direction == 'l')
        mlx_put_image_to_window(solong->mlx, solong->mlx_win,solong->player[0], j * ALL, i * ALL);
    else if (solong->direction == 'd')
        mlx_put_image_to_window(solong->mlx, solong->mlx_win,solong->player[2], j * ALL, i * ALL);
}
void exit_status(t_solong *so_long, int i, int j)
{
    if(so_long->event.collectible != 0)
        mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,so_long->close, j * ALL, i * ALL);
    else if(so_long->event.collectible == 0)
        mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,so_long->open, j * ALL, i * ALL);
}
void move_enmy(t_solong *solong, int i, int j)
{
    if (solong->enm.dir == 1)
        mlx_put_image_to_window(solong->mlx, solong->mlx_win,solong->enms[0], j * ALL, i * ALL);
    else if (solong->enm.dir == 0)
        mlx_put_image_to_window(solong->mlx, solong->mlx_win,solong->enms[0], j * ALL, i * ALL);
}
void make_enmy(t_solong *solong)
{
    solong->map[1][solong->x - 1 / 2] = 'N';
    solong->map[solong->y - 2][solong->x - 2] = 'N';
    solong->map[1][4] = 'N';
    solong->map[1][solong->x - 2] = 'N';
    solong->map[solong->y - 2][solong->x - 2] = 'N';
    solong->map[2][solong->x / 2] = 'N';
}
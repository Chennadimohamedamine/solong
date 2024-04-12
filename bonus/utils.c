/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:13:18 by mochenna          #+#    #+#             */
/*   Updated: 2024/04/12 18:07:48 by mochenna         ###   ########.fr       */
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
    solong->anim.x[0] = 17;
    solong->anim.y[0] = solong->y - 2;
    solong->anim.x[1] = 4;
    solong->anim.y[1] = 1;
    solong->anim.x[2] = solong->x - 2;
    solong->anim.y[2] = 1;
    solong->anim.x[3] = solong->x - 2;
    solong->anim.y[3] = solong->y - 2;
    solong->anim.x[4] = solong->x / 2;
    solong->anim.y[4] = 1;
    solong->map[solong->anim.y[0]][solong->anim.x[0]] = 'N';
    solong->map[solong->anim.y[1]][solong->anim.x[1]] = 'N';
    solong->map[solong->anim.y[2]][solong->anim.x[2]] = 'N';
    solong->map[solong->anim.y[3]][solong->anim.x[3]] = 'N';
    solong->map[solong->anim.y[3]][solong->anim.x[3]] = 'N';
    
}
void animation(t_solong *solong, int x, int y)
{
    if (solong->map[solong->event.y][x] == '1' 
        || solong->map[solong->event.y][x] == 'E'
        || solong->map[solong->event.y][x] == 'C')
        return ;
    if (solong->map[solong->event.y][solong->event.x - 1] == 'P')
    {
        solong->map[solong->event.y][x] = 'N';
        solong->map[solong->event.y][x] = '0';
        game_over(solong, "<><> you lost <><>\n");
    }
    else
    {
        solong->map[solong->event.y][x] = 'N';
        solong->map[solong->event.y][x] = '0';
    }
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:13:02 by mochenna          #+#    #+#             */
/*   Updated: 2024/04/16 22:17:16 by mochenna         ###   ########.fr       */
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
        mlx_put_image_to_window(solong->mlx, solong->mlx_win,solong->enms[1], j * ALL, i * ALL);
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
int ft_close_(t_solong *solong)
{
    mlx_destroy_image(solong->mlx, solong->enms[0]);
    mlx_destroy_image(solong->mlx, solong->enms[1]);
    mlx_destroy_image(solong->mlx, solong->player[0]);
    mlx_destroy_image(solong->mlx, solong->player[1]);
    mlx_destroy_image(solong->mlx, solong->player[2]);
    mlx_destroy_image(solong->mlx, solong->player[3]);
    mlx_destroy_image(solong->mlx, solong->walls);
    mlx_destroy_image(solong->mlx, solong->close);
    mlx_destroy_image(solong->mlx, solong->open);
    mlx_destroy_window(solong->mlx, solong->mlx_win);
    freememory(solong->y,solong->map);
    write(1,"<><>> game over <<><>\n",22);
    free(solong->event.move_str);
    exit(0);
}
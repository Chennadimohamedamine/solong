/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:13:02 by mochenna          #+#    #+#             */
/*   Updated: 2024/04/17 18:51:36 by mochenna         ###   ########.fr       */
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
    if (solong->map[solong->y - 2][15] != '1' 
        || solong->map[solong->y - 2][15] != 'E'
        || solong->map[solong->y - 2][15] != 'C'
        || solong->map[solong->y - 2][15] != '0')
    solong->map[solong->y - 2][17] = 'N';
    if (solong->map[1][4] != '1' 
        || solong->map[1][4] != 'E'
        || solong->map[1][4] != 'C'
        || solong->map[1][4] != '0')
    solong->map[1][4] = 'N';
    if (solong->map[1][solong->x - 2] != '1' 
        || solong->map[1][solong->x - 2] != 'E'
        || solong->map[1][solong->x - 2] != 'C'
        || solong->map[1][solong->x - 2] != '0')
    solong->map[1][solong->x - 2] = 'N';
    if (solong->map[solong->y - 2][solong->x - 2] != '1' 
        || solong->map[solong->y - 2][solong->x - 2] != 'E'
        || solong->map[solong->y - 2][solong->x - 2] != 'C'
        || solong->map[solong->y - 2][solong->x - 2] != '0')
    solong->map[solong->y - 2][solong->x - 2] = 'N';
    if (solong->map[1][solong->x / 2 + 3] != '1' 
        || solong->map[1][solong->x / 2 + 3] != 'E'
        || solong->map[1][solong->x / 2 + 3] != 'C'
        || solong->map[1][solong->x / 2  + 3] != '0')
    solong->map[1][solong->x / 2 + 3] = 'N';
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
    if (solong->event.move_str != NULL)
        free(solong->event.move_str);
    exit(0);
}
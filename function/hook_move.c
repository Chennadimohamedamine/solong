/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:07:35 by mochenna          #+#    #+#             */
/*   Updated: 2024/03/28 19:56:56 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void move_to_up(t_solong *solong)
{
    if (solong->event.y <= 0|| solong->map[solong->event.y - 1][solong->event.x] == '1')
        return ;
    // if (solong->map[solong->event.y - 1][solong->event.x] == 'C')
    mlx_put_image_to_window(solong->mlx, solong->mlx_win,solong->img_ptr5, solong->event.x* ALL,solong->event.y-- * ALL);
    mlx_put_image_to_window(solong->mlx, solong->mlx_win,solong->img_ptr1, solong->event.x * ALL,solong->event.y * ALL);
}
void move_to_left(t_solong *solong)
{
    if (solong->event.x <= 0 || solong->map[solong->event.y][solong->event.x - 1] == '1')
        return ;
    // if ()
    mlx_put_image_to_window(solong->mlx, solong->mlx_win,solong->img_ptr5, solong->event.x-- * ALL,solong->event.y * ALL);
    mlx_put_image_to_window(solong->mlx, solong->mlx_win,solong->img_ptr1, solong->event.x * ALL,solong->event.y * ALL);
}
void move_to_right(t_solong *solong)
{
    if (solong->event.x >= solong->x || solong->map[solong->event.y][solong->event.x + 1] == '1')
        return ;
    mlx_put_image_to_window(solong->mlx, solong->mlx_win,solong->img_ptr5, 
        solong->event.x++ * ALL,solong->event.y * ALL);
    mlx_put_image_to_window(solong->mlx, solong->mlx_win,solong->img_ptr1, solong->event.x * ALL,solong->event.y * ALL);
}
void move_to_down(t_solong *solong)
{
    if (solong->event.y >= solong->y || solong->map[solong->event.y + 1][solong->event.x] == '1')
        return ;
    mlx_put_image_to_window(solong->mlx, solong->mlx_win,solong->img_ptr5, solong->event.x* ALL,solong->event.y++ * ALL);
    mlx_put_image_to_window(solong->mlx, solong->mlx_win,solong->img_ptr1, solong->event.x * ALL,solong->event.y * ALL);
}
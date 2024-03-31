/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:07:35 by mochenna          #+#    #+#             */
/*   Updated: 2024/03/31 22:52:33 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void move_to_up(t_solong *solong)
{
    if (solong->event.y <= 0|| solong->map[solong->event.y - 1][solong->event.x] == '1')
        return ;
    if (solong->map[solong->event.y - 1][solong->event.x] == 'C')
    {
        solong->map[solong->event.y - 1][solong->event.x] = 'P';
        solong->map[solong->event.y--][solong->event.x] = '0';
        solong->event.collectible--;
    }
    else
    {
        if (solong->map[solong->event.y - 1][solong->event.x] == 'E')
            return ;
        solong->map[solong->event.y - 1][solong->event.x] = 'P';
        solong->map[solong->event.y--][solong->event.x] = '0';
    }
}
void move_to_left(t_solong *solong)
{
    if (solong->event.x <= 0 || solong->map[solong->event.y][solong->event.x - 1] == '1')
        return ;
    if (solong->map[solong->event.y][solong->event.x - 1] == 'C')
    {
        solong->map[solong->event.y][solong->event.x - 1] = 'P';
        solong->map[solong->event.y][solong->event.x--] = '0';
        solong->event.collectible--;
    }
    else
    {
         if (solong->map[solong->event.y][solong->event.x - 1] == 'E')
            return ;
        solong->map[solong->event.y][solong->event.x - 1] = 'P';
        solong->map[solong->event.y][solong->event.x--] = '0';
    }
}
void move_to_right(t_solong *solong)
{
    if (solong->event.x >= solong->x || solong->map[solong->event.y][solong->event.x + 1] == '1')
        return ;
    if (solong->map[solong->event.y][solong->event.x + 1] == 'C')
    {
        solong->map[solong->event.y][solong->event.x + 1] = 'P';
        solong->map[solong->event.y][solong->event.x++] = '0';
        solong->event.collectible--;
    }
    else
    {
         if (solong->map[solong->event.y][solong->event.x + 1] == 'E')
            return ;
        solong->map[solong->event.y][solong->event.x + 1] = 'P';
        solong->map[solong->event.y][solong->event.x++] = '0';
    }
}
void move_to_down(t_solong *solong)
{
    if (solong->event.y >= solong->y || solong->map[solong->event.y + 1][solong->event.x] == '1')
        return ;
      if (solong->map[solong->event.y + 1][solong->event.x] == 'C')
    {
        solong->map[solong->event.y + 1][solong->event.x] = 'P';
        solong->map[solong->event.y++][solong->event.x] = '0';
        solong->event.collectible--;
    }
    else
    {
         if (solong->map[solong->event.y + 1][solong->event.x] == 'E')
            return ;
        solong->map[solong->event.y + 1][solong->event.x] = 'P';
        solong->map[solong->event.y++][solong->event.x] = '0';
    }
}
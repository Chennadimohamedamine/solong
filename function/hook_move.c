/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:07:35 by mochenna          #+#    #+#             */
/*   Updated: 2024/03/27 23:01:50 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// void move_to_up(t_solong *solong)
// {
    
// }
// void move_to_left(t_solong *solong)
// {
    
// }
void move_to_right(t_solong *solong)
{
    if (solong->event.x >= solong->x || solong->map[solong->event.y][solong->event.x + 1] == '1')
        return ;
        printf("str %c\n",solong->map[solong->event.y][solong->event.y]);
        printf("str + 1 %c\n",solong->map[solong->event.y][solong->event.x+1]);
    // swap_value(solong->map[solong->event.y][solong->event.x],solong->map[solong->event.y][solong->event.x + 1]);
    printf("move %d",solong->event.move);
}
// void move_to_down(t_solong *solong)
// {
    
// }
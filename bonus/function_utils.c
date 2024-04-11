/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:13:02 by mochenna          #+#    #+#             */
/*   Updated: 2024/04/11 20:46:11 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	key_hooks(int keycode, t_solong *v)
{
    print_move(v->event.move++);
    mlx_clear_window(v->mlx,v->mlx_win);
    if (keycode == 53)
    {
        printf("game over\n");
        exit(0);
    }
    else if(keycode == 0 || keycode == 123)
        move_to_left(v);
    else if(keycode == 2 || keycode == 124)
         move_to_right(v);
    else if(keycode == 13 || keycode == 126)
         move_to_up(v);
    else if(keycode == 1 || keycode == 125)
        move_to_down(v);
    put_img(v);
	return (0);
}
int loop_hook(t_solong *solong)
{
    mlx_hook(solong->mlx_win ,02,0, key_hooks ,solong);
    
    return (0);
}
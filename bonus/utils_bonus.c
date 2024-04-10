/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 18:01:44 by mochenna          #+#    #+#             */
/*   Updated: 2024/04/09 18:21:15 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void drow_game(t_solong *solong)
{
    get_positon(solong->map,&solong->event.y,&solong->event.x);
    get_positon_exit(solong->map,&solong->y_e,&solong->x_e);
    solong->event.move = 1;
    solong->event.collectible = all_collect(solong->map);
    solong->direction = 'r';
    solong->enmy.y = solong->y - 1;
    solong->enmy.x = solong->x - 4;
    solong->enmy.x = 0;
    convert_img_(solong);
    put_img(solong);
    printf("HELLO\n");
    printf("hello\n");
    mlx_loop_hook(solong->mlx, &loop_hook, solong);
    // mlx_hook(solong->mlx_win, 17, 0, ft_close, solong);
}
void put_img(t_solong *solong)
{
    int i;
    int j;

    i = 0;
    while(i < solong->y)
    {
        j = 0;
        while(j < solong->x)
        {
            if (j == solong->enmy.x && i == solong->enmy.y)
            {
                if (solong->enmy.direction == 0)
                  mlx_put_image_to_window(solong->mlx, solong->mlx_win,solong->enmy_[0], j * ALL, i * ALL);
                else
                    mlx_put_image_to_window(solong->mlx, solong->mlx_win,solong->enmy_[1], j * ALL, i * ALL); 
            }
            else if(solong->map[i][j] == '1')
                mlx_put_image_to_window(solong->mlx, solong->mlx_win,solong->walls, j * ALL, i * ALL);
            else if(solong->map[i][j] == 'P')
                player_direction(solong, i, j);
            else if(solong->map[i][j] == 'E' && solong->event.collectible != 0)
                mlx_put_image_to_window(solong->mlx, solong->mlx_win,solong->close, j * ALL, i * ALL);
            else if(solong->map[i][j] == 'E' && solong->event.collectible == 0)
                mlx_put_image_to_window(solong->mlx, solong->mlx_win,solong->open, j * ALL, i * ALL);
            else if(solong->map[i][j] == '0')
                mlx_put_image_to_window(solong->mlx, solong->mlx_win,solong->bg, j * ALL, i * ALL);
            else if(solong->map[i][j] == 'C')
                mlx_put_image_to_window(solong->mlx, solong->mlx_win,solong->collect, j * ALL, i * ALL);
            j++;
        }
        i++;
    }
}
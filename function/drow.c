/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:23:32 by mochenna          #+#    #+#             */
/*   Updated: 2024/04/01 01:10:35 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void convert_img(t_solong *img)
{
    int s;
    int s1;
    int f;

    s = ALL;
    s1 = 45;
    f = 100;
    img->walls = mlx_xpm_file_to_image(img->mlx,"img/walls1.xpm",&s,&s);
    img->player = mlx_xpm_file_to_image(img->mlx,"img/player_.xpm",&s,&s);
    img->collect = mlx_xpm_file_to_image(img->mlx,"img/collectible.xpm",&s1,&s1);
    img->close = mlx_xpm_file_to_image(img->mlx,"img/close.xpm",&f,&f);
    img->open = mlx_xpm_file_to_image(img->mlx,"img/open.xpm",&f,&f);
    img->bg = mlx_xpm_file_to_image(img->mlx,"img/bg.xpm",&f,&f);
}
void put_image(t_solong *so_long)
{
    int i;
    int j;

    i = 0;
    while(i < so_long->y)
    {
        j = 0;
        while(j < so_long->x)
        {
            if(so_long->map[i][j] == '1')
                mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,so_long->walls, j * ALL, i * ALL);
            else if(so_long->map[i][j] == 'P')
                mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,so_long->player, j * ALL, i * ALL);
            else if(so_long->map[i][j] == 'E' && so_long->event.collectible != 0)
                mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,so_long->close, j * ALL, i * ALL);
            else if(so_long->map[i][j] == 'E' && so_long->event.collectible == 0)
                mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,so_long->open, j * ALL, i * ALL);
            else if(so_long->map[i][j] == '0')
                mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,so_long->bg, j * ALL, i * ALL);
            else if(so_long->map[i][j] == 'C')
                mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,so_long->collect, j * ALL, i * ALL);
            j++;
        }
        i++;
    }
}
int	key_hook(int keycode, t_solong *v)
{
    print_move(v->event.move++);
    mlx_clear_window(v->mlx,v->mlx_win);
    // if (v->event.collectible == 0)
    //     mlx_put_image_to_window(v->mlx, v->mlx_win,v->open, v->x_e * ALL, v->y_e * ALL);
    if (keycode == 53)
        mlx_destroy_window(v->mlx,v->mlx_win);
    else if(keycode == 0 || keycode == 123)
        move_to_left(v);
    else if(keycode == 2 || keycode == 124)
        move_to_right(v);
    else if(keycode == 13 || keycode == 126)
        move_to_up(v);
    else if(keycode == 1 || keycode == 125)
        move_to_down(v);
    put_image(v);
	return (0);
}
void game(t_solong *so_long)
{
    get_positon(so_long->map,&so_long->event.y,&so_long->event.x);
    get_positon_exit(so_long->map,&so_long->y_e,&so_long->x_e);
    so_long->event.move = 1;
    so_long->event.collectible = all_collect(so_long->map);
    put_image(so_long);
    mlx_key_hook(so_long->mlx_win, key_hook, so_long);
}
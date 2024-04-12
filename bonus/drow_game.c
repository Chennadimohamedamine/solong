/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:13:49 by mochenna          #+#    #+#             */
/*   Updated: 2024/04/12 17:18:18 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void convert_image(t_solong *img)
{
    int s;
    int s1;
    int f;

    s = ALL;
    s1 = 45;
    f = 100;
    img->enms[0] = mlx_xpm_file_to_image(img->mlx,"img/go_left.xpm",&s,&s);
    img->enms[1] = mlx_xpm_file_to_image(img->mlx,"img/go_right.xpm",&s,&s);
    img->walls = mlx_xpm_file_to_image(img->mlx,"img/walls1.xpm",&s,&s);
    img->player[0] = mlx_xpm_file_to_image(img->mlx,"img/to_left.xpm",&s,&s);
    img->player[1] = mlx_xpm_file_to_image(img->mlx,"img/to_up.xpm",&s,&s);
    img->player[2] = mlx_xpm_file_to_image(img->mlx,"img/to_down.xpm",&s,&s);
    img->player[3] = mlx_xpm_file_to_image(img->mlx,"img/to_right.xpm",&s,&s);
    img->collect = mlx_xpm_file_to_image(img->mlx,"img/collectible.xpm",&s1,&s1);
    img->close = mlx_xpm_file_to_image(img->mlx,"img/close.xpm",&f,&f);
    img->open = mlx_xpm_file_to_image(img->mlx,"img/open.xpm",&f,&f);
    img->bg = mlx_xpm_file_to_image(img->mlx,"img/bg.xpm",&f,&f);
}
void put_img(t_solong *so_long)
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
                 player_direction(so_long, i, j);
            else if(so_long->map[i][j] == 'E')
                exit_status(so_long, i, j);
            else if(so_long->map[i][j] == 'N')
                move_enmy(so_long, i, j);
            else if(so_long->map[i][j] == '0')
                mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,so_long->bg, j * ALL, i * ALL);
            else if(so_long->map[i][j] == 'C')
                mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,so_long->collect, j * ALL, i * ALL);
            j++;
        }
        i++;
    }
}
int	key_hooks(int keycode, t_solong *v)
{
    if (keycode == 53)
        game_over(v,"<><> game over <><>\n");
    print_move(v->event.move++);
    mlx_clear_window(v->mlx,v->mlx_win);
    if(keycode == 0 || keycode == 123)
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

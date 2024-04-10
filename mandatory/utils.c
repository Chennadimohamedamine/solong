/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:22:47 by mochenna          #+#    #+#             */
/*   Updated: 2024/04/10 22:30:21 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_ens(char *s, char *s1)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(s[i] && s1[j] && s[i] == s1[j])
    {
        i++;
        j++;
    }
    return (s[i] - s1[j]);
}
int all_collect(char **map)
{
    int i;
    int j;
    int c;

    c = 0;
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'C')
                c++;
            j++;   
        }
        i++;
    }
    return (c);
}
void convert_number(int i)
{
   if (i > 9)
        convert_number(i / 10);
    write(1,&"0123456789"[i % 10],1);
}
void print_move(int i)
{
    write(1,"move number : ",15);
    convert_number(i);
    write(1,"\n",1);
}
int ft_close(t_solong *solong)
{
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
    exit(1);
}
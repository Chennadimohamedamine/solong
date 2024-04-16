/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:49:38 by mochenna          #+#    #+#             */
/*   Updated: 2024/04/16 17:17:25 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
void print_move(t_solong *solong)
{
    char *str;

    str = ft_itoa(solong->event.move++);
    mlx_string_put(solong->mlx,solong->mlx_win,15,15,0xFFFFFFFF,"hey");
    free(str);
}

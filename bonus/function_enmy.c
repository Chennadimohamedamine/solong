/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_enmy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 00:08:50 by mochenna          #+#    #+#             */
/*   Updated: 2024/04/28 00:48:14 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int lenght_enmy(char **map)
{
    int c;
    int i;
    int j;

    i = 0;
    c = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'N')
                c++;
            j++;
        }
        i++;
    }
    return (c);
}
void    get_positon_enumy(t_solong *solong)
{
    int c[2];
    int i;
    int j;

    c[0] = 0;
    c[1] = 0;
    i = 0;
    while (solong->map[i])
    {
        j = 0;
        while (solong->map[i][j] && c[0] < solong->enm.length_enmy)
        {
            if (solong->map[i][j] == 'N')
            {
                solong->enm.e_y[c[0]] = i;
                solong->enm.e_x[c[0]] = j;
                solong->enm.e_dir[c[0]++] = c[1]++;
            }
            j++;
        }
        i++;
    }
}

void handling_enumy_error(t_solong *solong, char *str)
{
    int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	mlx_destroy_window(solong->mlx, solong->mlx_win);
	free(solong->mlx);
    freememory(solong->y, solong->map);
    exit(1);
}
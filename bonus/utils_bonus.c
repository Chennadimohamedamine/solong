/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:49:38 by mochenna          #+#    #+#             */
/*   Updated: 2024/04/17 19:27:02 by mochenna         ###   ########.fr       */
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
void	flood_fill_(char **map, int y, int x, int row)
{
	if (y < 0 || y >= ft_strlen(map[0]) || x < 0 || x >= row || map[x][y] == 'N'
		|| map[x][y] == '1' || map[x][y] == 'F' || map[x][y] == 'E')
		return ;
	map[x][y] = 'F';
	flood_fill_(map, y - 1, x, row);
	flood_fill_(map, y + 1, x, row);
	flood_fill_(map, y, x - 1, row);
	flood_fill_(map, y, x + 1, row);
}
int check_path_(char **s)
{
    int i;
    int j;
    
    i = 0;
    while (s[i])
    {
        j = 0;
        while(s[i][j])
        {
            if(s[i][j] != 'P' && s[i][j] != '1' && s[i][j] != 'F' && s[i][j] != '0' && s[i][j] != 'E' && s[i][j] != 'N')
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}
void check_validgame(t_solong *solong)
{
    int i;
    int p[2];
    char    **map;

    i = 0;
    map = splitnewline(solong->event.copy_map, &i, '\n');
    p[0] = 0;    
    p[1] = 0;
    get_positon(map,&p[0],&p[1]);
    flood_fill_(map,p[1],p[0],i);
    if(check_path_(map))
        error_handling(solong->event.copy_map,map,i);
    freememory(i,map);
    free(solong->event.copy_map);
    solong->event.copy_map = NULL;
}

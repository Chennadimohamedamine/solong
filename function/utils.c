/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:22:47 by mochenna          #+#    #+#             */
/*   Updated: 2024/03/28 15:24:24 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
// void out(t_solong *f)
// {
//     freememory(f->y,f->map);
//     free(f);
    
// }
void swap_value(char *s1,char *s2)
{
    char c;
    c = *s2;
    *s2 = *s1;
   *s1 = *s2;
}
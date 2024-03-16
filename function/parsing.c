/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:52:18 by mochenna          #+#    #+#             */
/*   Updated: 2024/03/16 18:09:46 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
void check_size_reapt(char **s, int i)
{
    int j;
    int len;

    j = 1;
    len = ft_strlen(s[0]);
    while(s[j])
    {
        if(len != ft_strlen(s[j]))
            error_handling(NULL,s,i);
        j++;
    }
    
}
void checkall(char **s,int i)
{
    if (i < 3)
        error_handling(NULL,s,i);
    check_size_reapt(s,i);
    
}
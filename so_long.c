/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:55:52 by mochenna          #+#    #+#             */
/*   Updated: 2024/03/16 18:07:28 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void first_step(char *s)
{
    char **lines;
    int i;
    
    lines = splitnewline(s,&i,'\n');
    free(s);
    checkall(lines,i);
}
void program(int ac, char **av)
{
   int fd;
   char *s;
   
   s = ft_strjoin(ft_strdup("file/"),av[1]);
   fd = open(s,O_RDONLY);
   free(s);
   s = readall(fd);
   first_step(s);
   close(fd);
}
int main(int ac, char **av)
{
    if (ac != 2 || av[1] == 0)
    {
        write(2, "Error\n",6);
        return (1);
    }
    // system("leaks so_long");
    program(ac, av);
    return (0);
}
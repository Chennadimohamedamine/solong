/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:22:47 by mochenna          #+#    #+#             */
/*   Updated: 2024/03/16 18:06:58 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void freememory(int c, char **v)
{
	int	i;

	if(c == 0)
		return ;
	i = 0;
	while (i < c)
	{
		free(v[i]);
		i++;
	}
	free(v);
}
char *readall(int fd)
{
	char	*buffer;
	int		r;
	char	*str;

	str = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	r = 1;
	buffer = NULL;
	while (r > 0)
	{
		r = read(fd, str, BUFFER_SIZE);
		if (r < 0)
			failer_malloc(NULL,buffer,str,0);
		str[r] = '\0';
		buffer = ft_strjoin(buffer, str);
		if (!buffer)
			failer_malloc(NULL,buffer,str,0);
		if (r == 0)
			break ;
	}
	free(str);
	return (buffer);
}
void failer_malloc(char **s, char *s2, char *s1, int i)
{
	if (i > 0)
		freememory(i,s);
	if(s1)
		free(s1);
	if(s2)
		free(s2);
	exit(1);	
}
void error_handling(char *s, char **s1,int i)
{
	if (s)
		free(s);
	s1[1] =0;
	i = 0; 
	freememory(i,s1);
	write(2,"Error\n",6);
	exit(1);
}
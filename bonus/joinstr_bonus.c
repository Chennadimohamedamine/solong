/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joinstr_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:49:12 by mochenna          #+#    #+#             */
/*   Updated: 2024/04/15 19:50:31 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*cpy;
	int		l;
	int		i;

	l = ft_strlen(s1);
	i = 0;
	cpy = (char *)malloc(sizeof(char) * l + 1);
	if (cpy == NULL)
		return (NULL);
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	int		i;
	int		j;

	if (!s1)
		return (ft_strdup(s2));
	i = 0;
	j = 0;
	s = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s)
		return (NULL);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	while (s2[j])
		s[i++] = s2[j++];
	s[i] = 0;
	free(s1);
	return (s);
}

void	failer_malloc(char **s, char *s2, char *s1, int i)
{
	if (i > 0)
		freememory(i, s);
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	exit(1);
}

void	error_handling(char *s, char **s1, int i)
{
	if (s != NULL)
		free(s);
	freememory(i, s1);
	write(2, "Error\n", 6);
	exit(1);
}
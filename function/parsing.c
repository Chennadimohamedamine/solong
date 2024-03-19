/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:52:18 by mochenna          #+#    #+#             */
/*   Updated: 2024/03/19 17:29:18 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	emty(char *s)
{
	int	i;

	if (s[0] == '\n')
		return (1);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n' && (s[i + 1] == '\n' || s[i + 1] == 0))
			return (1);
		i++;
	}
	return (0);
}

int	check_double(char *s)
{
	int	i;
	int	g[4];

	i = 0;
	while (i < 4)
		g[i++] = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == 'C')
			g[0]++;
		else if (s[i] == 'P' || s[i] == 'E')
			g[1]++;
		else if (s[i] == '0')
			g[3]++;
		if ((s[i] == 'P' || s[i] == 'E' || s[i] == 'C')
			&& (s[i - 1] == '1' && s[i + 1] == '1'))
			return (1);
		i++;
	}
	if (g[0] == 0 || g[1] != 2 || g[3] == 0)
		return (1);
	return (0);
}

void	check_gui(char *s1, char **s, int i)
{
	int	j;
	int	len;
	int	c;

	j = 0;
	len = ft_strlen(s[0]);
	while (s[j])
	{
		if (len != ft_strlen(s[j]) || (s[j][0] != '1' || s[j][len - 1] != '1'))
			error_handling(s1, s, i);
		if (j == 0 || j == i - 1)
		{
			c = 0;
			while (s[j][c])
			{
				if (s[j][c++] != '1')
					error_handling(s1, s, i);
			}
		}
		j++;
	}
	if (check_double(s1))
		error_handling(s1, s, i);
}

void	checkall(char *s1, char **s, int i)
{
	if (i < 3 || emty(s1))
		error_handling(s1, s, i);
	check_gui(s1, s, i);
	free(s1);
	printf("all good\n");
}

char	**lines(char *av)
{
	char	**lines;
	char	*s;
	int		fd;

	s = ft_strjoin(ft_strdup("file/"), av);
	fd = open(s, O_RDONLY);
	s = readall(s, fd);
	close(fd);
	lines = splitnewline(s, &fd, '\n');
	checkall(s, lines, fd);
	return (lines);
}

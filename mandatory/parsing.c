/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:52:18 by mochenna          #+#    #+#             */
/*   Updated: 2024/04/10 22:30:12 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		if (!(s[i] == 'P' || s[i] == 'E' || s[i] == 'C'
			|| s[i] != '1' || s[i] != '0'))
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
		i++;
	}
	if (g[0] == 0 || g[1] != 2)
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
	// check_game(s1, s, i);
}

char	**lines(char *av, int *y)
{
	char	**lines;
	char	*s;
	int		fd;

	if (check_ens(av + (ft_strlen(av) - 4), ".ber") != 0)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	fd = open(av, O_RDONLY);
	s = readall(fd);
	close(fd);
	lines = splitnewline(s, &fd, '\n');
	checkall(s, lines, fd);
	invalid_game(s);
	*y = fd;
	free(s);
	return (lines);
}

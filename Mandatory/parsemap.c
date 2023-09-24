/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlhafi <youlhafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 04:40:03 by mhabib-a          #+#    #+#             */
/*   Updated: 2023/09/23 05:27:06 by youlhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	mapsize(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	checkbox(char **str, int i, int j)
{
	if (str[i][j] != '0' && str[i][j] != 'W' && str[i][j] != 'E'
		&& str[i][j] != 'S' && str[i][j] != 'N')
		return (0);
	else if (((i - 1) < 0 || (i + 1) >= mapsize(str))
		|| ((j - 1) < 0 || (j + 1) > (int)ft_strlen(str[i])))
		return (1);
	else if (!str[i - 1][j] || str[i - 1][j] == ' ' || str[i - 1][j] == '\t')
		return (1);
	else if (!str[i + 1][j] || str[i + 1][j] == ' ' || str[i + 1][j] == '\t')
		return (1);
	else if (!str[i][j - 1] || str[i][j - 1] == ' ' || str[i][j - 1] == '\t')
		return (1);
	else if (!str[i][j + 1] || str[i][j + 1] == ' ' || str[i][j + 1] == '\t')
		return (1);
	return (0);
}

int	checkmapbox(char **str)
{
	int	i;
	int	y;

	i = 0;
	while (str[i])
	{
		y = 0;
		while (str[i][y])
		{
			if (checkbox(str, i, y))
				return (1);
			y++;
		}
		i++;
	}
	return (0);
}

int	checkmapsize(char **str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (len < (int)ft_strlen(str[i]))
			len = ft_strlen(str[i]);
		i++;
	}
	if (i < 3 || len < 3)
		return (1);
	return (0);
}

int	checkplayer(t_pmap *map, int i)
{
	char	**str;
	int		count;
	int		y;

	count = 0;
	str = map->map;
	while (str[i])
	{
		y = 0;
		while (str[i][y])
		{
			if (str[i][y] != '1' && str[i][y] != '0'
				&& str[i][y] != ' ' && str[i][y] != '\t' && str[i][y] != '\n')
			{
				if (str[i][y] != 'N' && str[i][y] != 'S'
					&& str[i][y] != 'E' && str[i][y] != 'W')
					return (2);
				map->player = str[i][y];
				count++;
			}
			y++;
		}
		i++;
	}
	return (count); 
}

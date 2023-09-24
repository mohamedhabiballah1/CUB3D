/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseTexturesTools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlhafi <youlhafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 02:46:40 by mhabib-a          #+#    #+#             */
/*   Updated: 2023/09/23 05:15:13 by youlhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	**getkeys(char **str, char *file, t_keys *keys, int i)
{
	char	**tmp;
	int		y;
	int		j;

	y = 0;
	j = 0;
	tmp = malloc(sizeof(char *) * (file_lenght(file) + 1));
	if (!tmp)
		return (NULL);
	while (str[i])
	{
		j = 0;
		while (str[i][j] && (str[i][j] == ' ' || str[i][j] == '\t'))
			j++;
		if (str[i][j] == '1' || str[i][j] == '0')
			break ;
		if (str[i] && str[i][0] && str[i][0] != '\n')
			tmp[y++] = ft_strdup(str[i++]);
		else
			i++;
	}
	tmp[y] = NULL;
	null_it(keys);
	return (tmp);
}

char	**getmaptool(char **str, char **map, int i)
{
	int	y;
	int	j;

	y = 0;
	while (str[i])
	{
		if (str[i][0] == '\n')
			break ;
		map[y] = ft_strdup(str[i]);
		i++;
		y++;
	}
	while (str[i])
	{
		j = 0;
		while (str[i][j] && (str[i][j] == ' ' || str[i][j] == '\t'))
			j++;
		if (str[i][j] && str[i][j] != '\n'
			&& str[i][j] != ' ' && str[i][j] != '\t')
			return (NULL);
		i++;
	}
	map[y] = NULL;
	return (map);
}

char	**getmap(char **str, char *file)
{
	char	**map;
	int		i;
	int		y;
	int		j;

	i = 0;
	y = 0;
	j = 0;
	map = malloc(sizeof(char *) * (file_lenght(file) + 1));
	if (!map)
		return (NULL);
	while (str[i])
	{
		j = 0;
		while (str[i][j] && (str[i][j] == ' ' || str[i][j] == '\t'))
			j++;
		if (str[i][j] == '1')
			break ;
		i++;
	}
	return (getmaptool(str, map, i));
}

int	countargskeys(char **str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int	checkifstiilnull(t_keys *keys)
{
	if (!keys->no_key)
		return (1);
	else if (!keys->so_key)
		return (1);
	else if (!keys->we_key)
		return (1);
	else if (!keys->ea_key)
		return (1);
	else if (!keys->f_key)
		return (1);
	else if (!keys->c_key)
		return (1);
	return (0);
}

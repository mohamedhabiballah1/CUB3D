/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseTextures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlhafi <youlhafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 02:43:28 by mhabib-a          #+#    #+#             */
/*   Updated: 2023/09/23 04:54:25 by youlhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	cmpkeys(char *str, char *cmp)
{
	int	i;
	int	y;
	int	k;

	i = 0;
	y = 0;
	k = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	y = i;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
		i++;
	while (y < i)
	{
		if (str[y] != cmp[k])
			return (1);
		k++;
		y++;
	}
	return (0);
}

int	handlekeys(t_keys *keys)
{
	int	i;

	i = 0;
	while (keys->tmp[i])
	{
		if (!cmpkeys(keys->tmp[i], "NO"))
			keys->no_key = ft_strdup(keys->tmp[i]);
		if (!cmpkeys(keys->tmp[i], "SO"))
			keys->so_key = ft_strdup(keys->tmp[i]);
		if (!cmpkeys(keys->tmp[i], "WE"))
			keys->we_key = ft_strdup(keys->tmp[i]);
		if (!cmpkeys(keys->tmp[i], "EA"))
			keys->ea_key = ft_strdup(keys->tmp[i]);
		if (!cmpkeys(keys->tmp[i], "F"))
			keys->f_key = ft_strdup(keys->tmp[i]);
		if (!cmpkeys(keys->tmp[i], "C"))
			keys->c_key = ft_strdup(keys->tmp[i]);
		i++;
	}
	ft_free_str(keys->tmp);
	if (checkifstiilnull(keys))
		return (1);
	return (0);
}

char	*gettrimed(char *str)
{
	char	*dst;
	int		i;
	int		y;
	int		len;
	int		k;

	len = 0;
	i = 0;
	y = ft_strlen(str) - 1;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[y] && (str[y] == ' ' || str[y] == '\t'))
		y--;
	k = i;
	while (i <= y)
	{
		len++;
		i++;
	}
	dst = ft_substr(str, k, len);
	return (dst);
}

char	*checkkeyvalue(char *str, char *key)
{
	int		fd;
	int		i;
	int		y;
	char	*tmp;

	i = 0;
	y = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i] && str[i] == key[y])
	{
		y++;
		i++;
	}
	tmp = gettrimed(&str[i]);
	fd = open(tmp, O_RDONLY);
	if (fd == -1)
		return (free(str), free(tmp), NULL);
	close(fd);
	if (file_format(tmp, ".xpm"))
		return (free(str), free(tmp), NULL);
	free(str);
	return (tmp);
}

int	parsetextures(t_keys *keys)
{
	keys->no_key = checkkeyvalue(keys->no_key, "NO");
	if (!keys->no_key)
		return (1);
	keys->so_key = checkkeyvalue(keys->so_key, "SO");
	if (!keys->so_key)
		return (1);
	keys->we_key = checkkeyvalue(keys->we_key, "WE");
	if (!keys->we_key)
		return (1);
	keys->ea_key = checkkeyvalue(keys->ea_key, "EA");
	if (!keys->ea_key)
		return (1);
	return (0);
}

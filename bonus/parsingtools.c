/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingtools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlhafi <youlhafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 05:14:43 by youlhafi          #+#    #+#             */
/*   Updated: 2023/09/23 05:23:50 by youlhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	null_it(t_keys *keys)
{
	keys->no_key = NULL;
	keys->so_key = NULL;
	keys->we_key = NULL;
	keys->ea_key = NULL;
	keys->f_key = NULL;
	keys->c_key = NULL;
	keys->f_colors = NULL;
	keys->c_colors = NULL;
}

char	**trimkeys(char **tmp)
{
	int		i;
	char	*temp;

	i = 0;
	while (tmp[i])
	{
		temp = tmp[i];
		tmp[i] = ft_strtrim(tmp[i], "\n");
		free(temp);
		temp = tmp[i];
		tmp[i] = gettrimed(tmp[i]);
		free(temp);
		i++;
	}
	return (tmp);
}

void	maplenght(t_pmap *map, t_parse *prs)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (map->map[i])
	{
		if (len < (int)ft_strlen(map->map[i]))
			len = ft_strlen(map->map[i]);
		i++;
	}
	prs->height = i;
	prs->width = len;
}

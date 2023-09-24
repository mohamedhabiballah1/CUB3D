/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseMapKeys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlhafi <youlhafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:08:15 by mhabib-a          #+#    #+#             */
/*   Updated: 2023/09/23 05:28:03 by youlhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	parsekeys(t_keys *keys)
{
	if (countargskeys(keys->tmp) != 6)
		return (parsingerror("To much/No Map Arguments"), 1);
	if (handlekeys(keys))
		return (freekeys(keys), parsingerror("Some Arguments Are Missed"), 1);
	if (parsetextures(keys))
		return (freekeys(keys),
			parsingerror("Something Wrong In The Textures"), 1);
	else if (parsecolor(keys))
		return (parsingerror("Colors Error"), 1);
	return (0);
}

int	parsemap(t_pmap *map)
{
	if (checkmapsize(map->map))
		return (parsingerror("Map Size Error"), 1);
	if (checkmapbox(map->map))
		return (parsingerror("The Map Is Not Surrounded By The Wall"), 1);
	if (checkplayer(map, 0) != 1)
		return (parsingerror("Too Much/NO Players In The Map"), 1);
	return (0);
}

void	getparsedstract(t_keys *keys, t_pmap *map, t_parse *prs)
{
	maplenght(map, prs);
	prs->map = map->map;
	prs->no_text = keys->no_key;
	prs->so_text = keys->so_key;
	prs->we_text = keys->we_key;
	prs->ea_text = keys->ea_key;
	prs->rceil = ft_atoi(keys->c_colors[0]);
	prs->gceil = ft_atoi(keys->c_colors[1]);
	prs->bceil = ft_atoi(keys->c_colors[2]);
	prs->rfloor = ft_atoi(keys->f_colors[0]);
	prs->gfloor = ft_atoi(keys->f_colors[1]);
	prs->bfloor = ft_atoi(keys->f_colors[2]);
	ft_free_str(keys->c_colors);
	ft_free_str(keys->f_colors);
	ft_free_str(prs->mapstr);
	prs->player = map->player;
}

int	parsefilecontent(t_parse *prs, char *file)
{
	t_keys	keys;
	t_pmap	maps;
	char	**str;
	char	*tmp;
	int		i;

	i = 0;
	str = prs->mapstr;
	keys.tmp = getkeys(str, file, &keys, 0);
	keys.tmp = trimkeys(keys.tmp);
	maps.map = getmap(str, file);
	if (!maps.map || !keys.tmp)
		return (parsingerror("Error"), 1);
	i = 0;
	while (maps.map[i])
	{
		tmp = maps.map[i];
		maps.map[i] = ft_strtrim(maps.map[i], "\n");
		free(tmp);
		i++;
	}
	if (parsekeys(&keys) || parsemap(&maps))
		return (1);
	getparsedstract(&keys, &maps, prs);
	return (0);
}

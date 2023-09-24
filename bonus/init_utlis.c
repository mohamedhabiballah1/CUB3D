/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utlis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlhafi <youlhafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 22:24:45 by youlhafi          #+#    #+#             */
/*   Updated: 2023/09/24 20:59:40 by youlhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	count_lines(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	max_len(char **map)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	max = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (max < j)
			max = j;
		i++;
	}
	return (max);
}

double	get_rotation(char c)
{
	if (c == 'E')
		return (0);
	else if (c == 'S')
		return (M_PI / 2);
	else if (c == 'W')
		return (M_PI);
	else
		return (3 * (M_PI / 2));
}

void	get_player_pos(t_map *map, t_player *player, char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (ft_strchr("NSEW", str[i][j]))
			{
				player->x = (double)((j) * map->tile_size);
				player->y = (double)((i) * map->tile_size);
				player->rotangle = get_rotation(str[i][j]);
			}
			j++;
		}
		i++;
	}
}

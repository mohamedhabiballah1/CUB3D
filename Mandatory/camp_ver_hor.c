/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camp_ver_hor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlhafi <youlhafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 22:25:40 by youlhafi          #+#    #+#             */
/*   Updated: 2023/09/23 22:25:41 by youlhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double	diff(double x1, double y1, double x2, double y2)
{
	return ((sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))));
}

void	camp_ver_hor(t_cub *data, t_ray *ray)
{
	if (ray->found_hor_wall)
		ray->hor.distance = diff(data->player.x, data->player.y,
				ray->hor.wall_hit_horx, ray->hor.wall_hit_hory);
	else
		ray->hor.distance = INT_MAX;
	if (ray->found_ver_wall)
		ray->ver.distance = diff(data->player.x, data->player.y,
				ray->ver.wall_hit_verx, ray->ver.wall_hit_very);
	else
		ray->ver.distance = INT_MAX;
	if (ray->hor.distance < ray->ver.distance)
	{
		ray->wall_hit_x = ray->hor.wall_hit_horx;
		ray->wall_hit_y = ray->hor.wall_hit_hory;
		ray->distance = ray->hor.distance;
		ray->hit_vertical = 0;
	}
	else
	{
		ray->wall_hit_x = ray->ver.wall_hit_verx;
		ray->wall_hit_y = ray->ver.wall_hit_very;
		ray->distance = ray->ver.distance;
		ray->hit_vertical = 1;
	}
}

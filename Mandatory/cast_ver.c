/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlhafi <youlhafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 22:25:49 by youlhafi          #+#    #+#             */
/*   Updated: 2023/09/23 22:25:50 by youlhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	vertical_interstep(t_cub *data, t_ray *ray)
{
	ray->ver.xinter = floor(data->player.x / data->map.tile_size)
		* data->map.tile_size;
	if (!ray->facing_left)
		ray->ver.xinter += data->map.tile_size;
	ray->ver.yinter = data->player.y + ((ray->ver.xinter - data->player.x)
			* tan(ray->ray_angle));
	ray->ver.xstep = data->map.tile_size;
	if (ray->facing_left)
		ray->ver.xstep *= -1;
	ray->ver.ystep = data->map.tile_size * tan(ray->ray_angle);
	if (!ray->facing_down && ray->ver.ystep > 0)
		ray->ver.ystep *= -1;
	if (ray->facing_down && ray->ver.ystep < 0)
		ray->ver.ystep *= -1;
}

void	vertical_cast(t_cub *data, t_ray *ray)
{
	double	checkx;

	while (ray->ver.xinter >= 0 && (ray->ver.xinter) < data->map.map_w - 1
		&& ray->ver.yinter >= 0 && (ray->ver.yinter) < data->map.map_h - 1)
	{
		if (ray->facing_left)
			checkx = (ray->ver.xinter) - 1;
		else
			checkx = (ray->ver.xinter) + 1;
		if (if_wall(checkx, ray->ver.yinter, data))
		{
			ray->found_ver_wall = 1;
			ray->ver.wall_hit_verx = ray->ver.xinter;
			ray->ver.wall_hit_very = ray->ver.yinter;
			break ;
		}
		else
		{
			ray->ver.xinter += ray->ver.xstep;
			ray->ver.yinter += ray->ver.ystep;
		}
	}
}

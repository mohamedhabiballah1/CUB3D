/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_hor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlhafi <youlhafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 22:25:43 by youlhafi          #+#    #+#             */
/*   Updated: 2023/09/23 22:25:44 by youlhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	horizontal_interstep(t_cub *data, t_ray *ray)
{
	ray->hor.yinter = floor(data->player.y / data->map.tile_size)
		* data->map.tile_size;
	if (ray->facing_down)
		ray->hor.yinter += data->map.tile_size;
	ray->hor.xinter = data->player.x + ((ray->hor.yinter - data->player.y)
			/ tan(ray->ray_angle));
	ray->hor.ystep = data->map.tile_size;
	if (!ray->facing_down)
		ray->hor.ystep *= -1;
	ray->hor.xstep = data->map.tile_size / tan(ray->ray_angle);
	if (ray->facing_left && ray->hor.xstep > 0)
		ray->hor.xstep *= -1;
	if (!ray->facing_left && ray->hor.xstep < 0)
		ray->hor.xstep *= -1;
}

void	horizontal_cast(t_cub *data, t_ray *ray)
{
	double	checky;

	while (1)
	{
		if (ray->facing_down)
			checky = ray->hor.yinter + 1;
		else
			checky = ray->hor.yinter - 1;
		if (if_wall(ray->hor.xinter, checky, data))
		{
			ray->found_hor_wall = 1;
			ray->hor.wall_hit_horx = (ray->hor.xinter);
			ray->hor.wall_hit_hory = (ray->hor.yinter);
			break ;
		}
		else
		{
			ray->hor.xinter += ray->hor.xstep;
			ray->hor.yinter += ray->hor.ystep;
		}
	}
}

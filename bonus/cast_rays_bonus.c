/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlhafi <youlhafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 22:24:15 by youlhafi          #+#    #+#             */
/*   Updated: 2023/09/25 09:01:57 by youlhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_ray(double rayangle, t_ray *ray)
{
	ray->hor.wall_hit_horx = 0;
	ray->hor.wall_hit_hory = 0;
	ray->ver.wall_hit_verx = 0;
	ray->ver.wall_hit_very = 0;
	ray->wall_hit_x = 0;
	ray->wall_hit_y = 0;
	ray->found_hor_wall = 0;
	ray->found_ver_wall = 0;
	ray->hit_vertical = 0;
	ray->facing_down = 0;
	ray->facing_left = 0;
	if (rayangle > 0 && rayangle < M_PI)
		ray->facing_down = 1;
	if (rayangle > M_PI_2 && rayangle < (3 * M_PI_2))
		ray->facing_left = 1;
}

void	dda(t_ray *ray, t_cub *data)
{
	horizontal_interstep(data, ray);
	vertical_interstep(data, ray);
	horizontal_cast(data, ray);
	vertical_cast(data, ray);
	camp_ver_hor(data, ray);
}

void	cast_rays(t_cub *data)
{
	t_ray	ray;
	int		i;

	i = 0;
	ray.ray_angle = normalize(data->player.rotangle
			- (data->ray.fov_angle / 2));
	while (i < data->ray.num_rays)
	{
		init_ray(ray.ray_angle, &ray);
		draw_floor(data, i);
		draw_ceil(data, i);
		dda(&ray, data);
		draw_line(ray.ray_angle, &ray, data, i);
		ray.ray_angle = normalize(ray.ray_angle
				+ (data->ray.fov_angle / data->ray.num_rays));
		i++;
	}
}

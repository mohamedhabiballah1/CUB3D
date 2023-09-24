/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlhafi <youlhafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 22:25:52 by youlhafi          #+#    #+#             */
/*   Updated: 2023/09/24 20:45:04 by youlhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	get_hit_text(double ray_angle, t_ray *ray, t_cub *data)
{
	if (ray->hit_vertical)
	{
		if (normalize(ray_angle) > M_PI_2
			&& normalize(ray_angle) < (3 * M_PI_2))
			ray->text_wallhit = data->wetext;
		else
			ray->text_wallhit = data->eatext;
	}
	else
	{
		if (normalize(ray_angle) > 0
			&& normalize(ray_angle) < M_PI)
			ray->text_wallhit = data->sotext;
		else
			ray->text_wallhit = data->notext;
	}
	return (0);
}

int	calc_offsetx(t_ray *ray, t_cub *data)
{
	int	offsetx;

	if (ray->hit_vertical)
		offsetx = fmod(ray->wall_hit_y * ray->text_wallhit.width
				/ data->map.tile_size, ray->text_wallhit.width);
	else
		offsetx = fmod(ray->wall_hit_x * ray->text_wallhit.width
				/ data->map.tile_size, ray->text_wallhit.width);
	return (offsetx);
}

int	put_wall(t_ray *ray, t_cub *data, t_img text_wallhit)
{
	double	high;
	double	px;
	double	py;
	int		dist_top;

	px = data->wall.start_x;
	py = data->wall.start_y;
	ray->offsetx = calc_offsetx(ray, data);
	high = data->wall.wall_h;
	while (high > 0)
	{
		if (high >= data->win_h)
			high = data->win_h - 1;
		dist_top = py + (data->wall.wall_h / 2) - (data->win_h / 2);
		ray->offsety = dist_top * (text_wallhit.height / data->wall.wall_h);
		data->img.addr[((int)py * (int)data->win_w + (int)px)]
			= text_wallhit.addr[(int)ray->offsety * (int)text_wallhit.width
			+ (int)ray->offsetx];
		py++;
		high--;
	}
	return (0);
}

void	draw_line(double rayangle, t_ray *ray, t_cub *data, int i)
{
	double	wall_dist;

	wall_dist = ray->distance * cos(rayangle - data->player.rotangle);
	data->wall.wall_h = (data->map.tile_size / wall_dist)
		* data->ray.distprojplane;
	data->wall.start_x = i;
	data->wall.start_y = (data->win_h / 2) - (data->wall.wall_h / 2);
	if (data->wall.start_y < 0)
		data->wall.start_y = 0;
	data->wall.end_x = i;
	data->wall.end_y = (data->win_h / 2) + (data->wall.wall_h / 2);
	if (data->wall.end_y >= data->win_h)
		data->wall.end_y = data->win_h - 1.0;
	get_hit_text(rayangle, ray, data);
	put_wall(ray, data, ray->text_wallhit);
}

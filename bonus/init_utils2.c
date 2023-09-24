/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlhafi <youlhafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 22:24:42 by youlhafi          #+#    #+#             */
/*   Updated: 2023/09/24 01:35:12 by youlhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	inittex(t_cub *data, t_img *img, char *textpath)
{
	img->ptr = mlx_xpm_file_to_image(data->mlx,
			textpath, &img->width, &img->height);
	if (!img->ptr)
	{
		write(2, "EMPTY FILE\n", 12);
		exit(EXIT_FAILURE);
	}
	img->addr = (int *)mlx_get_data_addr(img->ptr,
			&img->pixel_bits, &img->line_bytes, &img->endian);
}

double	normalize(double rayAngle)
{
	rayAngle = fmod(rayAngle, 2 * M_PI);
	if (rayAngle < 0)
		rayAngle = (2 * M_PI) + rayAngle;
	return (rayAngle);
}

int	if_wall(double x, double y, t_cub *data)
{
	int	i;
	int	j;

	if ((int)x < 0 || (int)x > data->map.map_w
		|| (int)y < 0 || (int)y > data->map.map_h)
		return (1);
	i = (int)x / data->map.tile_size;
	j = (int)y / data->map.tile_size;
	if (i >= (int)ft_strlen(data->parsing.map[j]))
		return (1);
	if (data->parsing.map[(int)j][(int)i] == '1')
		return (1);
	return (0);
}

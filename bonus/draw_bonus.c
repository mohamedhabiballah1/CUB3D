/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlhafi <youlhafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 22:24:23 by youlhafi          #+#    #+#             */
/*   Updated: 2023/09/25 09:26:21 by youlhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	get_rgb(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}

void	draw_floor(t_cub *data, int i)
{
	int		j;
	double	half;

	half = floor((double)(data->win_h / 2));
	j = (int)half;
	while (j < data->win_h)
	{
		data->img.addr[(int)(j * data->win_w + i)]
			= get_rgb(data->parsing.rfloor, data->parsing.gfloor,
				data->parsing.bfloor);
		j++;
	}
}

void	draw_ceil(t_cub *data, int i)
{
	int		j;
	double	half;

	half = floor((double)(data->win_h / 2));
	j = 0;
	while (j < (int)half)
	{
		data->img.addr[(int)(j * data->win_w + i)]
			= get_rgb(data->parsing.rceil, data->parsing.gceil,
				data->parsing.bceil);
		j++;
	}
}

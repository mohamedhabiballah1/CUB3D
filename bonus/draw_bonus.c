/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlhafi <youlhafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 22:24:23 by youlhafi          #+#    #+#             */
/*   Updated: 2023/09/24 20:45:04 by youlhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	get_rgb(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}

void	draw_floor(t_cub *data)
{
	int		w;
	int		h;
	double	half;

	half = floor((double)(data->win_h / 2));
	h = (int)half;
	while (h < data->win_h)
	{
		w = 0;
		while (w < data->win_w)
		{
			data->img.addr[(int)(h * data->win_w + w)]
				= get_rgb(data->parsing.rfloor, data->parsing.gfloor,
					data->parsing.bfloor);
			w++;
		}
		h++;
	}
}

void	draw_ceil(t_cub *data)
{
	int		w;
	int		h;
	double	half;

	half = floor((double)(data->win_h / 2));
	h = 0;
	while (h < (int)half)
	{
		w = 0;
		while (w < data->win_w)
		{
			data->img.addr[(int)(h * data->win_w + w)]
				= get_rgb(data->parsing.rceil, data->parsing.gceil,
					data->parsing.bceil);
			w++;
		}
		h++;
	}
}

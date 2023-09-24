/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlhafi <youlhafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 22:23:50 by youlhafi          #+#    #+#             */
/*   Updated: 2023/09/24 21:08:00 by youlhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_cadr(t_cub *data, int width, int hight)
{
	int	i;
	int	j;

	i = 70 - 10;
	while (i < hight + 10)
	{
		j = 70 - 10 ;
		while (j < width + 10)
		{
			if (i < 70 || i >= hight)
				data->img.addr[(int)((j)
						* (int)data->win_w + (i))] = 0x414a4c;
			else if (j < 70 || j >= width)
				data->img.addr[(int)((j)
						* (int)data->win_w + (i))] = 0x414a4c;
			j++;
		}
		i++;
	}
}

int	get_pos_draw(double pos)
{
	double	p;
	int		i;

	i = 0;
	p = pos - i;
	while (p > 0 && i < 64 * 5)
	{
		p = pos - i;
		i++;
	}
	return (p);
}

void	put_pixel(t_cub *data, t_mini *mini)
{
	if (mini->y <= 0 || mini->x <= 0 || mini->y >= data->map.map_rows * 64 
		|| mini->x >= data->map.map_cols * 64
		|| if_wall(mini->x, mini->y, data))
		data->img.addr[(int)((mini->starty)
				* (int)data->win_w + (mini->startx))] = 0x000000;
	if (mini->y >= data->player.y - 15
		&& mini->y <= data->player.y + 15
		&& mini->x >= data->player.x - 15
		&& mini->x <= data->player.x + 15)
		data->img.addr[(int)((mini->starty)
				* (int)data->win_w + (mini->startx))] = 0x000000;
}

void	map2d(t_cub *data)
{
	data->mini.y = get_pos_draw(data->player.y);
	data->mini.starty = 70;
	while (data->mini.starty < 320)
	{
		data->mini.startx = 70;
		data->mini.x = get_pos_draw(data->player.x);
		while (data->mini.startx < 420)
		{
			put_pixel(data, &data->mini);
			if (data->mini.y >= 0 && data->mini.x >= 0
				&& data->mini.y < data->map.map_rows * 64 
				&& data->mini.x < data->map.map_cols * 64)
				data->mini.x += 3;
			data->mini.startx++;
		}
		data->mini.y += 3;
		data->mini.starty++;
	}
	draw_cadr(data, 320, 420);
}

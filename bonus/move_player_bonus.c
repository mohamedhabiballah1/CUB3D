/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlhafi <youlhafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 22:25:02 by youlhafi          #+#    #+#             */
/*   Updated: 2023/09/24 01:36:00 by youlhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	update_pos(t_cub *data)
{
	double	moveangle;
	double	tmp_x;
	double	tmp_y;

	if (data->player.walkdir)
	{
		moveangle = data->player.rotangle;
		if (data->player.walkdir == 'w')
			moveangle = normalize(moveangle);
		else if (data->player.walkdir == 's')
			moveangle = normalize(moveangle + M_PI);
		else if (data->player.walkdir == 'a')
			moveangle = normalize(moveangle - M_PI_2);
		else if (data->player.walkdir == 'd')
			moveangle = normalize(moveangle + M_PI_2);
		tmp_x = data->player.x + (cos(moveangle) * data->player.movespeed);
		tmp_y = data->player.y + (sin(moveangle) * data->player.movespeed);
		if (!if_wall(tmp_x, tmp_y, data))
		{
			data->player.x = tmp_x;
			data->player.y = tmp_y;
		}
	}
}

void	move_player(t_cub *data)
{
	if (data->player.turndir != 0)
	{
		data->player.rotangle = normalize(data->player.rotangle
				+ (data->player.turndir * data->player.rotatespeed));
	}
	update_pos(data);
}

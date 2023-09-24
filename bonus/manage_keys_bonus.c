/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_keys_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlhafi <youlhafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 22:24:49 by youlhafi          #+#    #+#             */
/*   Updated: 2023/09/24 01:39:41 by youlhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	free_exit(t_cub *data)
{
	int	i;

	i = 0;
	free(data->parsing.no_text);
	free(data->parsing.so_text);
	free(data->parsing.we_text);
	free(data->parsing.ea_text);
	while (data->parsing.map[i])
	{
		free(data->parsing.map[i]);
		i++;
	}
	free(data->parsing.map);
	mlx_destroy_window(data->mlx, data->win);
	exit(EXIT_SUCCESS);
	return (0);
}

int	keypress(int keycode, t_cub *data)
{
	if (keycode == ESC_KEY)
		free_exit(data);
	if (keycode == W_KEY)
		data->player.walkdir = 'w';
	else if (keycode == S_KEY)
		data->player.walkdir = 's';
	else if (keycode == A_KEY)
		data->player.walkdir = 'a';
	else if (keycode == D_KEY)
		data->player.walkdir = 'd';
	else if (keycode == RIGHT_ARROW)
		data->player.turndir = 1;
	else if (keycode == LEFT_ARROW)
		data->player.turndir = -1;
	return (0);
}

int	keyrelease(int keycode, t_cub *data)
{
	if (keycode == W_KEY)
		data->player.walkdir = 0;
	else if (keycode == S_KEY)
		data->player.walkdir = 0;
	else if (keycode == A_KEY)
		data->player.walkdir = 0;
	else if (keycode == D_KEY)
		data->player.walkdir = 0;
	else if (keycode == RIGHT_ARROW)
		data->player.turndir = 0;
	else if (keycode == LEFT_ARROW)
		data->player.turndir = 0;
	return (0);
}

int	mousemove(int x, int y, t_cub *data)
{
	int	half;

	(void)y;
	half = data->win_w / 2;
	if (x < (half - 100) && x >= 0)
		data->player.turndir = -1;
	else if (x > data->win_w)
		data->player.turndir = 0;
	else if (x > (half + 100))
		data->player.turndir = 1;
	else if (x > (half - 100) && x < (half + 100))
		data->player.turndir = 0;
	else if (x < 0)
		data->player.turndir = 0;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_strct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlhafi <youlhafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 22:26:01 by youlhafi          #+#    #+#             */
/*   Updated: 2023/09/24 21:00:44 by youlhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_map(t_cub *data)
{
	data->map.map_rows = count_lines(data->parsing.map);
	data->map.map_cols = max_len(data->parsing.map);
	data->map.tile_size = 64;
	data->map.map_h = data->map.map_rows * (data->map.tile_size);
	data->map.map_w = data->map.map_cols * (data->map.tile_size);
}

void	init_win(t_cub *data)
{
	data->mlx = mlx_init();
	data->win_w = 30 * (data->map.tile_size);
	data->win_h = 17 * (data->map.tile_size);
	data->win = mlx_new_window(data->mlx,
			data->win_w, data->win_h, "CUB3D");
}

void	init_player(t_cub *data)
{
	get_player_pos(&data->map, &data->player, data->parsing.map);
	data->player.turndir = 0;
	data->player.walkdir = 0;
	data->player.movespeed = 7;
	data->player.rotatespeed = 2 * (M_PI / 180);
}

void	init_texts(t_cub *data)
{
	inittex(data, &data->notext, data->parsing.no_text);
	inittex(data, &data->sotext, data->parsing.so_text);
	inittex(data, &data->wetext, data->parsing.we_text);
	inittex(data, &data->eatext, data->parsing.ea_text);
}

void	init_rays(t_cub *data)
{
	data->ray.fov_angle = 60 * (M_PI / 180);
	data->ray.num_rays = data->win_w;
	data->ray.distprojplane = (data->win_w / 2) / tan(data->ray.fov_angle / 2);
}

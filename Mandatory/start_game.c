/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlhafi <youlhafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 22:26:26 by youlhafi          #+#    #+#             */
/*   Updated: 2023/09/24 20:45:04 by youlhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	click_exit(int keycode, t_cub *data)
{
	(void)keycode;
	(void)data;
	exit(EXIT_FAILURE);
}

void	init_strct(t_cub *data)
{
	init_map(data);
	init_win(data);
	init_player(data);
	init_texts(data);
	init_rays(data);
}

int	put(t_cub *data)
{
	data->img.ptr = mlx_new_image(data->mlx, data->win_w,
			data->win_h);
	data->img.addr = (int *)mlx_get_data_addr(data->img.ptr,
			&data->img.pixel_bits, &data->img.line_bytes,
			&data->img.endian);
	move_player(data);
	draw_floor(data);
	draw_ceil(data);
	cast_rays(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
	mlx_destroy_image(data->mlx, data->img.ptr);
	return (0);
}

int	start_game(t_cub *data)
{
	init_strct(data);
	mlx_hook(data->win, 2, 1L << 0, &keypress, data);
	mlx_hook(data->win, 3, 1L << 1, &keyrelease, data);
	mlx_hook(data->win, 17, 1L << 17, &click_exit, data);
	mlx_loop_hook(data->mlx, &put, data);
	mlx_loop(data->mlx);
	return (0);
}

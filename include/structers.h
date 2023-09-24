/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structers.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlhafi <youlhafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 02:04:54 by youlhafi          #+#    #+#             */
/*   Updated: 2023/09/24 20:48:14 by youlhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTERS_H
# define STRUCTERS_H

typedef struct s_keys
{
	char	**tmp;
	char	*no_key;
	char	*so_key;
	char	*we_key;
	char	*ea_key;
	char	*f_key;
	char	*c_key;
	char	**c_colors;
	char	**f_colors;
}			t_keys;

typedef struct s_pmap
{
	char	**map;
	int		map_size;
	char	player;
	char	player_vue;
}			t_pmap;

typedef struct s_parse
{
	char	**map;
	char	*no_text;
	char	*so_text;
	char	*we_text;
	char	*ea_text;
	int		rfloor;
	int		gfloor;
	int		bfloor;
	int		rceil;
	int		gceil;
	int		bceil;
	char	player;
	char	**mapstr;
	int		width;
	int		height;
}			t_parse;

typedef struct s_img
{
	void	*ptr;
	int		*addr;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	int		width;
	int		height;
}			t_img;

typedef struct s_map
{
	double	tile_size;
	int		map_w;
	int		map_h;
	double	map_rows;
	double	map_cols;
}			t_map;

typedef struct s_player
{
	double		x;
	double		y;
	char		walkdir;
	int			turndir;
	double		rotangle;
	double		movespeed;
	double		rotatespeed;
}				t_player;

typedef struct s_wall
{
	double		start_x;
	double		start_y;
	double		end_x;
	double		end_y;
	double		wall_h;
}				t_wall;

typedef struct s_mini
{
	int	startx;
	int	starty;
	int	x;
	int	y;
}		t_mini;

typedef struct s_hor
{
	double		xstep;
	double		ystep;
	double		xinter;
	double		yinter;
	double		wall_hit_horx;
	double		wall_hit_hory;
	double		distance;
}				t_hor;

typedef struct s_ver
{
	double		xstep;
	double		ystep;
	double		xinter;
	double		yinter;
	double		wall_hit_verx;
	double		wall_hit_very;
	double		distance;

}				t_ver;

typedef struct s_ray
{
	double		fov_angle;
	int			num_rays;
	double		distprojplane;
	double		ray_angle;
	int			facing_down;
	int			facing_left;
	double		wall_hit_x;
	double		wall_hit_y;
	int			found_hor_wall;
	int			found_ver_wall;
	double		distance;
	int			hit_vertical;
	int			offsetx;
	int			offsety;
	t_hor		hor;
	t_ver		ver;
	t_img		text_wallhit;
}				t_ray;

typedef struct s_cub
{
	void		*mlx;
	void		*win;
	double		win_w;
	double		win_h;
	t_parse		parsing;
	t_map		map;
	t_player	player;
	t_img		img;
	t_wall		wall;
	t_ray		ray;
	t_img		notext;
	t_img		sotext;
	t_img		eatext;
	t_img		wetext;
	t_mini		mini;
}				t_cub;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlhafi <youlhafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 02:04:30 by youlhafi          #+#    #+#             */
/*   Updated: 2023/09/24 21:00:09 by youlhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <unistd.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "structers.h"
# include "define.h"
# define BUFFER_SIZE 1

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
int		file_format(char *file, char *format);
int		file_lenght(char *file);
char	**read_file(char *file);
int		check_file(char *file);
char	**split(char **str, char c, int i);
void	ft_free_str(char **str);
int		ft_strcmp(const char *s1, const char *s2);
int		parsefilecontent(t_parse *prs, char *file);
void	parsingerror(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		cmpkeys(char *str, char *cmp);
int		handlekeys(t_keys *keys);
char	*gettrimed(char *str);
char	*checkkeyvalue(char *str, char *key);
int		parsetextures(t_keys *keys);
int		checkifstiilnull(t_keys *keys);
int		countargskeys(char **str);
char	**getmap(char **str, char *file);
char	**getkeys(char **str, char *file, t_keys *keys, int i);
int		parsecolor(t_keys *keys);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
char	**getcolorvalue(char *str);
int		checkcolorvalue(char **str);
int		parseNumbers(char *str);
int		ft_isdigit(int c);
int		checkcolor_rgb(char **str);
int		checkcomma(char *str);
int		checkmapsize(char **str);
int		checkmapbox(char **str);
int		checkplayer(t_pmap *map, int i);
char	*ft_strtrim(char const *str, char const *set);
void	freekeys(t_keys *keys);
void	null_it(t_keys *keys);
void	maplenght(t_pmap *map, t_parse *prs);
char	**trimkeys(char **tmp);
void	ft_error(char *err);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
int		ft_atoi(const char *str);
int		start_game(t_cub *data);
void	init_win(t_cub *data);
void	init_map(t_cub *data);
int		count_lines(char **map);
int		max_len(char **map);
double	cal_tilesize(t_cub *data);
void	init_player(t_cub *data);
void	inittex(t_cub *data, t_img *img, char *textpath);
void	init_texts(t_cub *data);
void	init_rays(t_cub *data);
void	get_player_pos(t_map *map, t_player *player, char **str);
int		keyrelease(int keycode, t_cub *data);
int		keypress(int keycode, t_cub *data);
double	normalize(double rayAngle);
void	move_player(t_cub *data);
int		if_wall(double x, double y, t_cub *data);
void	draw_floor(t_cub *data);
void	draw_ceil(t_cub *data);
void	cast_rays(t_cub *data);
void	vertical_cast(t_cub *data, t_ray *ray);
void	vertical_cast(t_cub *data, t_ray *ray);
void	vertical_interstep(t_cub *data, t_ray *ray);
void	horizontal_interstep(t_cub *data, t_ray *ray);
void	horizontal_cast(t_cub *data, t_ray *ray);
void	horizontal_cast(t_cub *data, t_ray *ray);
void	camp_ver_hor(t_cub *data, t_ray *ray);
void	draw_line(double rayangle, t_ray *ray, t_cub *data, int i);
int		draw_map(t_cub *a);
void	line2(t_cub *data, double rayangle);
void	map2d(t_cub *data);
int		mousemove(int x, int y, t_cub *data);
int		click_exit(int keycode, t_cub *data);
#endif

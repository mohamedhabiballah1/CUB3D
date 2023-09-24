/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlhafi <youlhafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 00:56:33 by mhabib-a          #+#    #+#             */
/*   Updated: 2023/09/23 04:11:04 by youlhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	parsingerror(char *str)
{
	write(2, str, ft_strlen(str));
	exit (1);
}

void	freekeys(t_keys *keys)
{
	if (keys->no_key)
		free(keys->no_key);
	else if (keys->so_key)
		free(keys->so_key);
	else if (keys->ea_key)
		free(keys->ea_key);
	else if (keys->we_key)
		free(keys->we_key);
	else if (keys->c_colors)
		ft_free_str(keys->c_colors);
	else if (keys->f_colors)
		ft_free_str(keys->f_colors);
}

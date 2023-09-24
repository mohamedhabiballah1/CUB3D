/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseColors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlhafi <youlhafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 03:35:21 by mhabib-a          #+#    #+#             */
/*   Updated: 2023/09/23 04:14:01 by youlhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	checkcolor_rgb(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_atoi(str[i]) > 255 || ft_atoi(str[i]) < 0)
			return (1);
		i++;
	}
	return (0);
}

int	checkcomma(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		return (1);
	return (0);
}

int	parsecolor(t_keys *keys)
{
	if (checkcomma(keys->f_key) || checkcomma(keys->c_key))
		return (1);
	keys->f_colors = getcolorvalue(keys->f_key);
	keys->c_colors = getcolorvalue(keys->c_key);
	free(keys->f_key);
	free(keys->c_key);
	if (checkcolorvalue(keys->f_colors) || checkcolorvalue(keys->c_colors))
		return (1);
	else if (checkcolor_rgb(keys->f_colors) || checkcolor_rgb(keys->c_colors))
		return (1);
	return (0);
}

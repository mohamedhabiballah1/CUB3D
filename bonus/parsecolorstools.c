/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseColorsTools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlhafi <youlhafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 04:31:54 by mhabib-a          #+#    #+#             */
/*   Updated: 2023/09/23 04:13:39 by youlhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	parsenumbers(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	checkcolorvalue(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (parsenumbers(str[i]))
			return (1);
		i++;
	}
	if (i != 3)
		return (1);
	return (0);
}

char	**getcolorvalue(char *str)
{
	char	**f;
	char	*tmp;
	int		i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
		i++;
	f = ft_split(&str[i], ',');
	i = 0;
	while (f[i])
	{
		tmp = f[i];
		f[i] = gettrimed(tmp);
		free(tmp);
		i++;
	}
	return (f);
}

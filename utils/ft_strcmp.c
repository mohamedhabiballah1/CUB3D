/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlhafi <youlhafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:58:08 by mhabib-a          #+#    #+#             */
/*   Updated: 2023/09/24 02:27:27 by youlhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1)
		return (1);
	while (s1[i] == s2[i] && (s1[i] && s2[i]) != '\0')
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

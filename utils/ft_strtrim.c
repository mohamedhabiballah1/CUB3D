/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlhafi <youlhafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 02:34:48 by mhabib-a          #+#    #+#             */
/*   Updated: 2023/09/24 02:27:37 by youlhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	check(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *str, char const *set)
{
	char	*dst;
	int		i;
	int		start;
	int		end;
	int		newlen;

	start = 0;
	while (str[start] && check(str[start], set))
		start++;
	end = ft_strlen(str);
	while ((end > start) && check(str[end - 1], set))
		end--;
	newlen = (end - start);
	dst = malloc(sizeof(char) * newlen + 1);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (start < end)
	{
		dst[i] = str[start];
		i++;
		start++;
	}
	dst[i] = '\0';
	return (dst);
}

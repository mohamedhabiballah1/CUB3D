/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlhafi <youlhafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 02:21:32 by mhabib-a          #+#    #+#             */
/*   Updated: 2023/09/24 02:25:30 by youlhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*ft_strjoin_get(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	if (!s2)
		return (NULL);
	if (!s1)
		s1 = ft_strdup("");
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	free(s1);
	return (new);
}

char	*join(char **str)
{
	char	*dst;
	int		i;

	dst = NULL;
	i = 0;
	while (str[i])
		dst = ft_strjoin_get(dst, str[i++]);
	return (dst);
}

int	count_words(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
			count++;
		i++;
	}
	return (count);
}

char	*copy_word(char *str, int *n, char c)
{
	int		i;
	int		len;
	int		y;

	y = *n;
	i = *n;
	len = 0;
	while (str[i] && str[i] != c)
	{
		i++;
		len++;
	}
	*n += len;
	return (ft_substr(str, y, len));
}

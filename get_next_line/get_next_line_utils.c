/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlhafi <youlhafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:15:02 by youlhafi          #+#    #+#             */
/*   Updated: 2023/09/25 09:27:14 by youlhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
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

char	*ft_strdup(const char *s)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;
	unsigned int	j;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	j = 0;
	i = 0;
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	while (s[j])
	{
		if (j >= start && i < len)
		{
			str[i] = s[j];
			i++;
		}
		j++;
	}
	str[i] = '\0';
	return (str);
}

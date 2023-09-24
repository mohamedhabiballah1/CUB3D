/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileTools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlhafi <youlhafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 02:16:36 by mhabib-a          #+#    #+#             */
/*   Updated: 2023/09/22 22:37:10 by youlhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	file_lenght(char *file)
{
	char	*dst;
	int		fd;
	int		count;

	fd = open(file, O_RDONLY);
	dst = get_next_line(fd);
	count = 0;
	while (dst)
	{
		count++;
		free(dst);
		dst = get_next_line(fd);
	}
	close(fd);
	return (count);
}

char	**read_file(char *file)
{
	char	**map;
	char	*dst;
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	map = malloc(sizeof(char *) * (file_lenght(file) + 1));
	if (!map)
		return (NULL);
	dst = get_next_line(fd);
	while (dst)
	{
		map[i] = ft_strdup(dst);
		free(dst);
		dst = get_next_line(fd);
		i++;
	}
	close(fd);
	map[i] = NULL;
	return (map);
}

int	file_format(char *file, char *format)
{
	int	i;

	i = ft_strlen(file) - 1;
	while (file[i] && file[i] != '.')
		i--;
	if (ft_strcmp(&file[i], format))
		return (1);
	return (0);
}

int	check_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	if (file_format(file, ".cub"))
		return (1);
	return (0);
}

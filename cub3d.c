/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlhafi <youlhafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 22:26:32 by youlhafi          #+#    #+#             */
/*   Updated: 2023/09/24 02:31:19 by youlhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	parse(char *file, t_parse *prs)
{
	prs->mapstr = read_file(file);
	if (!prs->mapstr)
		parsingerror("Empty file !!");
	if (parsefilecontent(prs, file))
		exit(1);
}

void	leaks()
{
	system("leaks cub3D");
}

int	main(int ac, char **av)
{
	t_cub	data;

	atexit(leaks);
	if (ac == 2)
	{
		if (check_file(av[1]))
		{
			write(2, "Map file not found!!\n", 20);
			return (1);
		}
		parse(av[1], &data.parsing);
		start_game(&data); 
	}
	else
		write(1, "Arguments Error!\n", 17);
	return (0);
}

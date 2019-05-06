/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_points.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 20:04:16 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/06 14:45:18 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "read_points.h"
#include <get_next_line.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include <math.h>
#include <stdio.h>

int		read_points(char *filename, t_vec3 *points, int *points_count, int *height)
{
	char	*line;
	char	**nums;
	int		ret;
	int		fd;
	t_vec3	p;

	fd = open(filename, O_RDONLY);
	line = NULL;
	ret = 1;
	*points_count = 0;
	p = mk_vec3(0, 0, 0);
	while (ret >= 1)
	{
		ret = get_next_line(fd, &line);
		if (line)
		{
			p.x = 0;
			nums = ft_strsplit(line, ' ');
			while (nums[(int)(p.x)] && *points_count < 1000000)
			{
				p.y = -(double)ft_atoi(nums[(int)(p.x)]) / 10;
				points[*points_count] = p;
				(*points_count)++;
				p.x++;
			}
			(*height)++;
		}
		free(line);
		p.z++;
	}
	(void)points;
	(void)points_count;
	return (0);
}

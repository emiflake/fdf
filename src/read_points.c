/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_points.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 20:04:16 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/05 14:05:16 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "read_points.h"
#include <get_next_line.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include <math.h>
#include <stdio.h>

int		read_points(char *filename, t_vec3 points[10000], int *points_count)
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
			while (nums[(int)(p.x)])
			{
				p.z = (double)ft_atoi(nums[(int)(p.x)]) / 100;
				points[*points_count] = p;
				// printf("x: %lf, y: %lf, z: %lf\n", p.x, p.y, p.z);
				(*points_count)++;
				p.x++;
			}
		}
		free(line);
		p.y++;
	}
	(void)points;
	(void)points_count;
	return (0);
}

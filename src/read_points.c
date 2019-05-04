/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_points.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 20:04:16 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/04 13:52:21 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "read_points.h"
#include <get_next_line.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include <math.h>
#include <stdio.h>

int		read_points(char *filename, t_vec3 **points, int *points_count)
{
	char	*line;
	char	**nums;
	int		ret;
	int		fd;
	int		n;
	t_vec3	p;

	fd = open(filename, O_RDONLY);
	line = NULL;
	ret = 1;
	n = 0;
	*points_count = 32;
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
				p.z = (double)ft_atoi(nums[(int)(p.x)]);
				if (n >= *points_count)
				{
					ft_realloc(*points, *points_count, *points_count * 2);
					*points_count *= 2;
				}
				(*points)[n] = p;
				printf("x: %lf, y: %lf, z: %lf\n", p.x, p.y, p.z);
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

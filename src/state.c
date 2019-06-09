/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 20:50:12 by nmartins       #+#    #+#                */
/*   Updated: 2019/06/09 15:10:37 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>
#include <libft.h>
#include "state.h"
#include "read_points.h"

void			init_state(t_state *trgt, char *filename)
{
	int	i;

	ft_memset(trgt, 0, sizeof(t_state));
	trgt->points = malloc(sizeof(t_vec3) * 1000000);
	read_points(filename, trgt->points, &trgt->point_count, &trgt->height);
	i = 0;
	trgt->max_height = 1;
	while (i < trgt->point_count)
	{
		trgt->max_height = ft_max(trgt->points[i].y, trgt->max_height);
		i++;
	}
	trgt->fov = 500;
	trgt->camera.position = mk_vec3(10, 10, 10);
	trgt->camera.rotation = mk_vec3(0, 0, 0);
	trgt->projection = PROJ_PERSPECTIVE;
	trgt->magnitude = 1;
}

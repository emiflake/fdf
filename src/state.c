/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 20:50:12 by nmartins       #+#    #+#                */
/*   Updated: 2019/06/03 17:29:00 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>
#include <libft.h>
#include "state.h"
#include "read_points.h"

void			init_state(t_state *trgt, char *filename)
{
	ft_memset(trgt, 0, sizeof(t_state));
	ft_putstr(" --- Initializing state ---\n");
	ft_putstr("Reading file ");
	ft_putstr(filename);
	ft_putstr("...\n");
	trgt->points = malloc(sizeof(t_vec3) * 1000000);
	read_points(filename, trgt->points, &trgt->point_count, &trgt->height);
	ft_putstr("Read ");
	ft_putnbr(trgt->point_count);
	ft_putstr(" points, ");
	ft_putnbr(trgt->height);
	ft_putstr("x");
	ft_putnbr(trgt->point_count / trgt->height);
	ft_putstr("\n");
	trgt->fov = 500;
	trgt->camera.position = mk_vec3(10, 10, 10);
	trgt->camera.rotation = mk_vec3(0, 0, 0);
}

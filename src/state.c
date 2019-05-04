/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 20:50:12 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/02 23:45:06 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>
#include <libft.h>
#include "state.h"
#include "read_points.h"

void			init_state(t_state *trgt, char *filename)
{
	ft_memset(trgt, 0, sizeof(t_state));
	trgt->points = NULL;
	read_points(filename, &trgt->points, &trgt->point_count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_points.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 20:05:23 by nmartins       #+#    #+#                */
/*   Updated: 2019/06/09 15:58:18 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_POINTS_H
# define READ_POINTS_H

# include <libgfx.h>

int		read_points(
	int fd,
	t_vec3 *points,
	int *point_count,
	int *height);

#endif

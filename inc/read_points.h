/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_points.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 20:05:23 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/06 14:42:51 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_HEIGHTS_H
# define READ_HEIGHTS_H

# include <libgfx.h>

int		read_points(char *filename, t_vec3 *points, int *point_count, int *height);

#endif

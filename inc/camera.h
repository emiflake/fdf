/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 17:17:18 by nmartins       #+#    #+#                */
/*   Updated: 2019/06/03 17:29:23 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include <libgfx.h>

typedef struct	s_camera
{
	t_vec3	position;
	t_vec3	rotation;
}				t_camera;

void	camera_move(t_camera *camera, double dx, double dy, double dz);
void	camera_rotate(t_camera *camera, double dx, double dy, double dz);

#endif

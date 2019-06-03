/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 17:16:58 by nmartins       #+#    #+#                */
/*   Updated: 2019/06/03 17:41:05 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

#include <math.h>

void	camera_move(t_camera *camera, double dx, double dy, double dz)
{
	camera->position.x += sin(camera->rotation.y + M_PI_2)
		* dx + sin(camera->rotation.y) * dz;
	camera->position.y += dy;
	camera->position.z += -cos(camera->rotation.y)
		* dz + sin(camera->rotation.y) * dx;
}

void	camera_rotate(t_camera *camera, double dx, double dy, double dz)
{
	camera->rotation.x += dx;
	camera->rotation.y += dy;
	camera->rotation.z += dz;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_vec3.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 19:10:30 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/02 19:12:48 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>

t_vec3	mk_vec3(double x, double y, double z)
{
	t_vec3 v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

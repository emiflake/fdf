/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_primitive_types.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 00:55:09 by nmartins       #+#    #+#                */
/*   Updated: 2019/04/30 16:58:46 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>
#include <math.h>

t_point			mk_point(int x, int y)
{
	t_point p;

	p.x = x;
	p.y = y;
	return (p);
}

t_point			point_add(t_point a, t_point b)
{
	return (mk_point(a.x + b.x, a.y + b.y));
}

t_dimensions	mk_dimensions(int width, int height)
{
	t_dimensions p;

	p.width = width;
	p.height = height;
	return (p);
}

t_vec2			mk_vec2(double x, double y)
{
	t_vec2 p;

	p.x = x;
	p.y = y;
	return (p);
}

t_point			demote_vec2(t_vec2 vec)
{
	return (mk_point(floor(vec.x), floor(vec.y)));
}

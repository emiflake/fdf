/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_vec.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 00:55:09 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/02 18:34:19 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>
#include <math.h>

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

double			vec2_distance(t_vec2 a, t_vec2 b)
{
	return (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
}

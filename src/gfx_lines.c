/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_lines.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 16:18:04 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/01 19:10:56 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gfx_lines.h"

#include <math.h>

#define SIGN(n) (n > 0 ? 1 : -1)

static void	gfx_line_bresenham_octant_low(
	t_gfx_state *st,
	t_render_target trgt,
	t_line l,
	int color)
{
	t_point	delta;
	t_point	p;
	int		derror;
	int		yi;

	delta.x = l.b.x - l.a.x;
	delta.y = l.b.y - l.a.y;
	yi = 1;
	if (delta.y < 0)
	{
		yi = -1;
		delta.y = -delta.y;
	}
	derror = 2 * delta.y - delta.x;
	p = mk_point(l.a.x, l.a.y);
	while (p.x < l.b.x)
	{
		gfx_blit_pixel(st, trgt, p, color);
		if (derror > 0)
		{
			p.y += yi;
			derror -= 2 * delta.x;
		}
		derror += 2 * delta.y;
		p.x++;
	}
}

static void	gfx_line_bresenham_octant_high(
	t_gfx_state *st,
	t_render_target trgt,
	t_line l,
	int color)
{
	t_point	delta;
	t_point	p;
	int		derror;
	int		xi;

	delta.x = l.b.x - l.a.x;
	delta.y = l.b.y - l.a.y;
	xi = 1;
	if (delta.x < 0)
	{
		xi = -1;
		delta.x = -delta.x;
	}
	derror = 2 * delta.x - delta.y;
	p = mk_point(l.a.x, l.a.y);
	while (p.y < l.b.y)
	{
		gfx_blit_pixel(st, trgt, p, color);
		if (derror > 0)
		{
			p.x += xi;
			derror -= 2 * delta.y;
		}
		derror += 2 * delta.x;
		p.y++;
	}
}

void	gfx_line(
	t_gfx_state *st,
	t_render_target trgt,
	t_line l,
	int color)
{
	if (abs(l.b.y - l.a.y) < abs(l.b.x - l.a.x))
	{
		if (l.a.x > l.b.x)
			gfx_line_bresenham_octant_low(st, trgt, mk_line(l.b, l.a), color);
		else
			gfx_line_bresenham_octant_low(st, trgt, mk_line(l.a, l.b), color);
	}
	else
	{
		if (l.a.y > l.b.y)
			gfx_line_bresenham_octant_high(st, trgt, mk_line(l.b, l.a), color);
		else
			gfx_line_bresenham_octant_high(st, trgt, mk_line(l.a, l.b), color);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_color.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 13:06:10 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/01 17:28:07 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>
# include <stdio.h>
#include <math.h>

/*
** Potentially useless alpha
*/

int		gfx_color(int r, int g, int b, int a)
{
	int color;

	color = 0;
	color |= ((255 - a) << 24);
	color |= (r << 16);
	color |= (g << 8);
	color |= (b << 0);
	return (color);
}

t_rgb	gfx_hsl2rgb(t_hsl hsl)
{
	double	chroma;
	double	hue_epoch;
	double	second;
	double	m;
	t_rgb	rgb;

	rgb = mk_rgb(0, 0, 0);
	chroma = (1.0 - fabs(2.0 * hsl.l - 1.0)) * hsl.s;
	hue_epoch = hsl.h / 60.0;
	second = chroma * (1 - fabs(fmod(hue_epoch, 2) - 1));
	m = hsl.l - chroma / 2;
	if (0 <= hue_epoch && hue_epoch <= 1)
		rgb = (mk_rgb(255 * (m + chroma), 255 * (m + second), m * 255));
	if (1 <= hue_epoch && hue_epoch <= 2)
		rgb = (mk_rgb(255 * (m + second), 255 * (m + chroma), m * 255));
	if (2 <= hue_epoch && hue_epoch <= 3)
		rgb = (mk_rgb(m * 255, 255 * (m + chroma), 255 * (m + second)));
	if (3 <= hue_epoch && hue_epoch <= 4)
		rgb = (mk_rgb(m * 255, 255 * (m + second), 255 * (m + chroma)));
	if (4 <= hue_epoch && hue_epoch <= 5)
		rgb = (mk_rgb(255 * (m + second), m * 255, 255 * (m + chroma)));
	if (5 <= hue_epoch && hue_epoch <= 6)
		rgb = (mk_rgb(255 * (m + chroma), 255 * m, 255 * (m + second)));
	return (rgb);
}

t_rgb	mk_rgb(int r, int g, int b)
{
	t_rgb rgb;

	rgb.r = r;
	rgb.g = g;
	rgb.b = b;
	return (rgb);
}

t_hsl	mk_hsl(int h, double s, double l)
{
	t_hsl hsl;

	hsl.h = h;
	hsl.s = s;
	hsl.l = l;
	return (hsl);
}

int		gfx_color_from_rgb(t_rgb rgb)
{
	return (gfx_color(rgb.r, rgb.g, rgb.b, 255));
}

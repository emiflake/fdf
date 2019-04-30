/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_color.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 13:06:10 by nmartins       #+#    #+#                */
/*   Updated: 2019/04/30 13:10:07 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>

/*
** Potentially useless alpha
*/

int	gfx_color(int r, int g, int b, int a)
{
	int color;

	color = 0;
	color |= ((255 - a) << 24);
	color |= (r << 16);
	color |= (g << 8);
	color |= (b << 0);
	return (color);
}

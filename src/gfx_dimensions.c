/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_dimensions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 18:33:56 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/02 18:34:11 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>

t_dimensions	mk_dimensions(int width, int height)
{
	t_dimensions p;

	p.width = width;
	p.height = height;
	return (p);
}

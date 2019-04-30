/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_primitive_shapes.h                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 00:57:01 by nmartins       #+#    #+#                */
/*   Updated: 2019/04/30 13:47:22 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_PRIMITIVE_SHAPES_H
# define GFX_PRIMITIVE_SHAPES_H

# include "gfx_state.h"
# include "gfx_image.h"

/*
** blit pixel to render target
*/

void	gfx_blit_pixel(
	t_gfx_state *st,
	t_render_target trgt,
	t_point p,
	int colour);

/*
** blit img to the screen, at origin (x, y)
*/

void	gfx_blit_image(
	t_gfx_state *st,
	t_render_target img,
	t_point orig);

#endif

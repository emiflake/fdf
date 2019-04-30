/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_primitive_shapes.h                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 00:57:01 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/01 00:30:12 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_PRIMITIVE_SHAPES_H
# define GFX_PRIMITIVE_SHAPES_H

# include "gfx_state.h"
# include "gfx_image.h"
# include "gfx_primitive_types.h"

/*
** blit pixel to render target
*/

void	gfx_blit_pixel(
	t_gfx_state *st,
	t_render_target trgt,
	t_point p,
	int color);

/*
** fill an image with a colour
*/
void	gfx_fill_trgt(
	t_gfx_state *st,
	t_render_target trgt,
	int color);

#endif

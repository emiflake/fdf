/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_image.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 13:22:15 by nmartins       #+#    #+#                */
/*   Updated: 2019/04/30 13:43:37 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_IMAGE_H
# define GFX_IMAGE_H

# include <mlx.h>
# include <stdlib.h>
# include "gfx_state.h"
# include "gfx_primitive_types.h"

typedef struct	s_gfx_image
{
	void			*img_ptr;
	t_dimensions	dim;
}				t_gfx_image;

typedef t_gfx_image *t_render_target;

/*
** Macro for rendering to the window, instead of to an image
*/
# define RENDER_WINDOW (t_render_target)NULL

t_gfx_image *create_image(t_gfx_state *st, t_dimensions dim);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_lines.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 16:14:21 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/02 19:40:01 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_LINES_H
# define GFX_LINES_H

# include "gfx_primitive_shapes.h"
# include "gfx_state.h"
# include "gfx_image.h"

void	gfx_line(t_gfx_state *st, t_gfx_image *img, t_line l, int color);

void	gfx_aa_line(t_gfx_state *st, t_gfx_image *img, t_line l, int color); // TODO: Anti-aliased line rendering

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_image.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 13:43:21 by nmartins       #+#    #+#                */
/*   Updated: 2019/04/30 13:43:32 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gfx_image.h"

t_gfx_image *create_image(t_gfx_state *st, t_dimensions dim)
{
	t_gfx_image *img;

	img = (t_gfx_image *)malloc(sizeof(t_gfx_image));
	img->dim = dim;
	img->img_ptr = mlx_new_image(st->mlx_ptr, dim.width, dim.height);
	return (img);
}

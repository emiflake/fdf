/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_primitive_shapes.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 00:58:33 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/02 19:02:06 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>
#include <libft.h>

inline void	gfx_blit_pixel(
	t_gfx_state *st,
	t_gfx_image *img,
	t_point p,
	int color)
{
	int loc;

	(void)st;
	loc = (p.x + p.y * img->dim.width) * img->bits_per_pixel / 8;
	img->data_addr[loc + 3] = color >> 24;
	img->data_addr[loc + 2] = color >> 16;
	img->data_addr[loc + 1] = color >> 8;
	img->data_addr[loc + 0] = color >> 0;
}

void		gfx_fill_trgt(
	t_gfx_state *st,
	t_render_target trgt,
	int color)
{
	int pixel;
	int loc;

	(void)st;
	pixel = 0;
	loc = 0;
	while (pixel < trgt->dim.width * trgt->dim.height)
	{
		loc += trgt->bits_per_pixel / 8;
		trgt->data_addr[loc + 3] = color >> 24;
		trgt->data_addr[loc + 2] = color >> 16;
		trgt->data_addr[loc + 1] = color >> 8;
		trgt->data_addr[loc + 0] = color >> 0;
		pixel++;
	}
}

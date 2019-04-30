/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_primitive_shapes.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 00:58:33 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/01 00:52:41 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>
#include <libft.h>

void	gfx_blit_pixel(
	t_gfx_state *st,
	t_render_target trgt,
	t_point p,
	int color)
{
	int loc;
	if (trgt == RENDER_WINDOW)
		mlx_pixel_put(st->mlx_ptr, st->win_ptr, p.x, p.y, color);
	else
	{
		loc = (p.x + p.y * trgt->dim.width) * trgt->bits_per_pixel / 8;
		trgt->data_addr[loc + 3] = color >> 24;
		trgt->data_addr[loc + 2] = color >> 16;
		trgt->data_addr[loc + 1] = color >> 8;
		trgt->data_addr[loc + 0] = color >> 0;
	}
}

void	gfx_fill_trgt(
	t_gfx_state *st,
	t_render_target trgt,
	int color)
{
	int pixel;

	(void)st;
	if (trgt == RENDER_WINDOW)
	{
		ft_putendl_fd("NOT YET IMPLEMENTED: GFX_FILL_TRGT", 2);
		exit(1);
	}
	pixel = 0;
	while (pixel < trgt->dim.width * trgt->dim.height)
	{
		trgt->data_addr[pixel * trgt->bits_per_pixel / 8 + 3] = color >> 24;
		trgt->data_addr[pixel * trgt->bits_per_pixel / 8 + 2] = color >> 16;
		trgt->data_addr[pixel * trgt->bits_per_pixel / 8 + 1] = color >> 8;
		trgt->data_addr[pixel * trgt->bits_per_pixel / 8 + 0] = color >> 0;
		pixel++;
	}
}

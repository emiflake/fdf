/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_primitive_shapes.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 00:58:33 by nmartins       #+#    #+#                */
/*   Updated: 2019/04/30 20:55:03 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>
#include <libft.h>

void	gfx_blit_pixel(
	t_gfx_state *st,
	t_render_target trgt,
	t_point p,
	int colour)
{
	if (trgt == RENDER_WINDOW)
		mlx_pixel_put(st->mlx_ptr, st->win_ptr, p.x, p.y, colour);
	else
	{
		ft_putendl_fd("NOT YET IMPLEMENTED: GFX_BLIT_PIXEL FOR IMAGES", 2);
		exit(1);
	}
}

void	gfx_fill_trgt(
	t_gfx_state *st,
	t_render_target trgt,
	int colour)
{
	// int x;
	// int y;

	(void)st;
	if (trgt == RENDER_WINDOW)
	{
		ft_putendl_fd("NOT YET IMPLEMENTED: GFX_FILL_TRGT", 2);
		exit(1);
	}
	(void)colour;
	// trgt->data_addr[100] = gfx_color(255, 0, 0, 255);
	// y = 0;
	// while (y < trgt->dim.height)
	// {
	// 	x = 0;
	// 	while (x < trgt->dim.width)
	// 	{
	// 		trgt->data_addr[(x + y * trgt->size_line) *
	// 			(trgt->bits_per_pixel / 8)] = colour;
	// 		x++;
	// 	}
	// 	y++;
	// }
}

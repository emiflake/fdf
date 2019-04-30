/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_primitive_shapes.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 00:58:33 by nmartins       #+#    #+#                */
/*   Updated: 2019/04/30 16:57:44 by nmartins      ########   odam.nl         */
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
	{
		mlx_pixel_put(st->mlx_ptr, st->win_ptr, p.x, p.y, colour);
	}
	else
	{
		ft_putendl_fd("NOT YET IMPLEMENTED: GFX_BLIT_PIXEL FOR IMAGES", 2);
		exit(1);
	}
}

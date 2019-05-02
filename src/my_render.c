/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   my_render.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 20:17:48 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/02 20:20:16 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>
#include <libft.h>
#include "const.h"

int	render(t_gfx_state *st)
{
	char *fps;

	fps = ft_itoa(gfx_get_fps(1));
	mlx_clear_window(st->mlx_ptr, st->win_ptr);
	gfx_fill_trgt(st, st->buffer, 0x00);
	gfx_blit_image(st, st->buffer, mk_point(0, 0));
	mlx_string_put(st->mlx_ptr,
		st->win_ptr, WIN_WIDTH - 200, 10, gfx_color(255, 255, 255, 255), fps);
	free(fps);
	return (0);
}

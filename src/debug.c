/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/09 15:08:35 by nmartins       #+#    #+#                */
/*   Updated: 2019/06/09 15:14:16 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "state.h"
#include "const.h"
#include "render.h"

void			debug_info(t_gfx_state *st)
{
	t_state		*mst;
	char		*fps;
	int			color;

	color = gfx_color_from_rgb(gfx_hsl2rgb(
			mk_hsl((gfx_get_current_epoch() / 10) % 360, 1, 0.5)));
	mst = st->user_state;
	fps = ft_itoa(gfx_get_fps(1));
	ft_strreplace(&fps, ft_strjoin(fps, " frames per second"));
	mlx_string_put(st->mlx_ptr,
		st->win_ptr, WIN_WIDTH - 300, 50,
		color, fps);
	mlx_string_put(st->mlx_ptr, st->win_ptr,
		50, 50, color, "WASD:        Move");
	mlx_string_put(st->mlx_ptr, st->win_ptr,
		50, 70, color, "Arrow Keys:  Look around");
	mlx_string_put(st->mlx_ptr, st->win_ptr,
		50, 90, color, "Space:       Change Perspective");
	mlx_string_put(st->mlx_ptr, st->win_ptr,
		50, 110, color, "Mouse Wheel: Zoom in/out");
	mlx_string_put(st->mlx_ptr, st->win_ptr,
		50, 130, color, "Shift:       \"Sprint\"");
	free(fps);
}

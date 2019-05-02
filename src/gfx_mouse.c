/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_mouse.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 19:15:55 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/02 18:30:48 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gfx_mouse.h"
#include "gfx_primitive_types.h"

void			gfx_mouse_state_down(t_gfx_mouse *mouse, int button_code)
{
	mouse->button_state[button_code] = 1;
}

void			gfx_mouse_state_up(t_gfx_mouse *mouse, int button_code)
{
	mouse->button_state[button_code] = 0;
}

void			gfx_mouse_update_position(t_gfx_mouse *mouse, int x, int y)
{
	mouse->mouse_pos.x = x;
	mouse->mouse_pos.y = y;
}

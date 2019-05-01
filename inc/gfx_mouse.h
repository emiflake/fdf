/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_mouse.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 13:15:03 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/01 19:27:39 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_MOUSE_H
# define GFX_MOUSE_H

# include "gfx_primitive_types.h"

# define MC_LEFT 1
# define MC_RIGHT 2
# define MC_MIDDLE 3
# define MC_SCROLLUP 4
# define MC_SCROLLDOWN 5
# define MC_SCROLLLEFT 6
# define MC_SCROLLRIGHT 7

/*
** Store all the possible mouse button states (DOWN/UP)
*/

typedef	char	t_mouse_button_state[8];

typedef struct	s_gfx_mouse
{
	/*
	** Represents the position of the mouse on the window
	*/
	t_point					mouse_pos;

	t_mouse_button_state	button_state;
}				t_gfx_mouse;

void			gfx_mouse_state_down(t_gfx_mouse *mouse, int button_code);
void			gfx_mouse_state_up(t_gfx_mouse *mouse, int button_code);
void			gfx_mouse_update_position(t_gfx_mouse *mouse, int x, int y);

#endif

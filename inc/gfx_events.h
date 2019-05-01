/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_events.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 00:56:54 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/01 19:52:16 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_EVENTS_H
# define GFX_EVENTS_H

# define EVT_KEYPRESS 2
# define EVT_KEYRELEASE 3
# define EVT_MOUSEPRESS 4
# define EVT_MOUSERELEASE 5
# define EVT_MOUSEMOVE 6
# define EVT_EXPOSE 12
# define EVT_CLOSE 17

typedef struct  s_hooks
{
	int		(*render)(t_gfx_state *state);

    /*
    ** refer to gfx_keys.h
    */

	int     (*keypress)(int key_code, t_gfx_state *state);
	int     (*keyrelease)(int key_code, t_gfx_state *state);

	/*
	** refer to gfx_mouse.h
	*/

	int     (*mousepress)(int button_code, int x, int y, t_gfx_state *state);
	int     (*mouserelease)(int button_code, int x, int y, t_gfx_state *state);
	int     (*mousemove)(int x, int y, t_gfx_state *state);

	/*
	** upon window opening
	*/

	int     (*expose)(t_gfx_state *state);

	/*
	** upon close event
	*/

	int     (*close)(t_gfx_state *state);
}               t_hooks;


void    gfx_register_hooks(t_gfx_state *st, t_hooks hooks);
void	gfx_loop(t_gfx_state *st);

#endif

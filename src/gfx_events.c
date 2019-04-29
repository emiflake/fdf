/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_events.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 00:56:43 by nmartins       #+#    #+#                */
/*   Updated: 2019/04/30 01:30:41 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libgfx.h>

/*
** Eternal loop. *ah*
*/
void	    gfx_loop(t_gfx_state *st)
{
    mlx_loop(st->mlx_ptr);
}

static void _gfx_register_hook_safe(t_gfx_state *st, int evt_code, int(*handler)())
{
    if (handler)
        mlx_hook(st->win_ptr, evt_code, 0, handler, (void*)st);
}

void        gfx_register_hooks(t_gfx_state *st, t_hooks hooks)
{
    _gfx_register_hook_safe(st, EVT_KEYPRESS, hooks.keypress);
    _gfx_register_hook_safe(st, EVT_KEYRELEASE, hooks.keyrelease);
    _gfx_register_hook_safe(st, EVT_MOUSEPRESS, hooks.mousepress);
    _gfx_register_hook_safe(st, EVT_MOUSERELEASE, hooks.mouserelease);
    _gfx_register_hook_safe(st, EVT_MOUSEMOVE, hooks.mousemove);
    _gfx_register_hook_safe(st, EVT_EXPOSE, hooks.expose);
    _gfx_register_hook_safe(st, EVT_CLOSE, hooks.close);
}
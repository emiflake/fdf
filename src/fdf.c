/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/29 19:32:58 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/02 20:53:13 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>
#include <libft.h>
#include "read_heights.h"
#include "events.h"
#include "const.h"
#include "state.h"

int	main(void)
{
	t_gfx_state	st;
	t_hooks		hooks;
	t_state		state;

	init_state(&state);
	ft_memset(&st, 0, sizeof(t_gfx_state));
	ft_memset(&hooks, 0, sizeof(t_hooks));
	st.user_state = &state;
	if (gfx_mk_state(&st, mk_dimensions(WIN_WIDTH, WIN_HEIGHT),
		"FdF - A Wireframe Viewer") == -1)
		return (EXIT_FAILURE);
	hooks.keypress = keypress;
	hooks.keyrelease = keyrelease;
	hooks.close = close;
	hooks.expose = expose;
	hooks.render = render;
	hooks.mousemove = mousemove;
	hooks.mousepress = mousepress;
	hooks.mouserelease = mouserelease;
	gfx_register_hooks(&st, hooks);
	gfx_loop(&st);
	return (EXIT_SUCCESS);
}

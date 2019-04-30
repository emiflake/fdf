/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/29 19:32:58 by nmartins       #+#    #+#                */
/*   Updated: 2019/04/30 18:33:33 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mlx.h>
#include <libgfx.h>
#include <libft.h>
#include <math.h>

typedef struct	s_state
{
}				t_state;

int	keypress(int key_code, t_gfx_state *st)
{
	gfx_key_state_down(st->key_state, key_code);
	if (key_code == KC_ESC || key_code == KC_Q)
		exit(0);
	return (0);
}

int	keyrelease(int key_code, t_gfx_state *st)
{
	gfx_key_state_up(st->key_state, key_code);
	return (0);
}

int	close(t_gfx_state *st)
{
	(void)st;
	exit(0);
	return (0);
}

/*
** Window: *appears*
** owo what's this
*/

int	expose(t_gfx_state *st)
{
	(void)st;
	return (0);
}

/*
** Render?
*/

int	render(t_gfx_state *st)
{
	t_state *user_state;

	user_state = st->user_state;
	mlx_clear_window(st->mlx_ptr, st->win_ptr);
	return (0);
}

int	main(void)
{
	t_gfx_state	st;
	t_hooks		hooks;
	t_state		ust;

	ft_memset(&hooks, 0, sizeof(t_hooks));
	st.user_state = &st;
	if (gfx_mk_state(&st, mk_dimensions(640, 480), "Basic Window") == -1)
		return (EXIT_FAILURE);
	hooks.keypress = keypress;
	hooks.keyrelease = keyrelease;
	hooks.close = close;
	hooks.expose = expose;
	hooks.render = render;
	st.user_state = &ust;
	gfx_register_hooks(&st, hooks);
	gfx_loop(&st);
	ft_putendl("Hello");
	return (EXIT_SUCCESS);
}

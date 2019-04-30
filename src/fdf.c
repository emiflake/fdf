/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/29 19:32:58 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/01 00:54:01 by nmartins      ########   odam.nl         */
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
	gfx_free_state(st);
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

int	render(t_gfx_state *st)
{
	t_state *user_state;
	
	user_state = st->user_state;
	mlx_clear_window(st->mlx_ptr, st->win_ptr);
	gfx_fill_trgt(st, st->buffer, gfx_color(255, 255, 255, 255));
	for(size_t i = 0; i < 100; i++)
	{
		gfx_blit_pixel(st, st->buffer,
			mk_point(i + 100, floor(sin((double)i / 10) * 100)),
			0x00FFB7C1);
	}
	gfx_blit_image(st, st->buffer, GFX_P_ORIGIN);
	
	return (0);
}

int	main(void)
{
	t_gfx_state	st;
	t_hooks		hooks;
	t_state		ust;

	ft_memset(&hooks, 0, sizeof(t_hooks));
	st.user_state = &st;
	if (gfx_mk_state(&st, mk_dimensions(640, 480), "FdF - A Wireframe Viewer") == -1)
		return (EXIT_FAILURE);
	hooks.keypress = keypress;
	hooks.keyrelease = keyrelease;
	hooks.close = close;
	hooks.expose = expose;
	hooks.render = render;
	st.user_state = &ust;
	gfx_register_hooks(&st, hooks);
	gfx_loop(&st);
	return (EXIT_SUCCESS);
}

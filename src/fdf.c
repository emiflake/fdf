/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/29 19:32:58 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/01 20:17:13 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mlx.h>
#include <libgfx.h>
#include <libft.h>
#include <math.h>

#define WIN_HEIGHT 900
#define WIN_WIDTH 1600

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

int mousepress(int button_code, int x, int y, t_gfx_state *st)
{
	(void)x;
	(void)y;
	gfx_mouse_state_down(&st->mouse_state, button_code);
	return (0);
}

int mouserelease(int button_code, int x, int y, t_gfx_state *st)
{
	(void)x;
	(void)y;
	gfx_mouse_state_up(&st->mouse_state, button_code);
	return (0);
}

int mousemove(int x, int y, t_gfx_state *st)
{
	gfx_mouse_update_position(&st->mouse_state, x, y);
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
	static int count;
	t_state *user_state;
	count++;
	user_state = st->user_state;
	gfx_debug_print_keystate(st->key_state);
	mlx_clear_window(st->mlx_ptr, st->win_ptr);
	gfx_fill_trgt(st, st->buffer, 0xFFFFFF);
	t_point p = mk_point(gfx_math_clamp(st->mouse_state.mouse_pos.x, 0, WIN_WIDTH - 1), gfx_math_clamp(st->mouse_state.mouse_pos.y, 0, WIN_HEIGHT - 1));
	for (int x = 0; x < WIN_WIDTH; x += 50)
		for (int y = 0; y < WIN_WIDTH; y += 50)
				gfx_line(st, st->buffer, mk_line(mk_point(x, y), p), gfx_color(255, 0, 0, 255));
	gfx_blit_image(st, st->buffer, GFX_P_ORIGIN);
	mlx_string_put(st->mlx_ptr, st->win_ptr, 10, 10, gfx_color(0, 0, 0, 255), ft_itoa(gfx_get_fps(1)));
	return (0);
}

int	main(void)
{
	t_gfx_state	st;
	t_hooks		hooks;
	t_state		ust;

	ft_memset(&st, 0, sizeof(t_gfx_state));
	ft_memset(&hooks, 0, sizeof(t_hooks));
	st.user_state = &st;
	if (gfx_mk_state(&st, mk_dimensions(WIN_WIDTH, WIN_HEIGHT), "FdF - A Wireframe Viewer") == -1)
		return (EXIT_FAILURE);
	hooks.keypress = keypress;
	hooks.keyrelease = keyrelease;
	hooks.close = close;
	hooks.expose = expose;
	hooks.render = render;
	hooks.mousemove = mousemove;
	hooks.mousepress = mousepress;
	hooks.mouserelease = mouserelease;
	st.user_state = &ust;
	gfx_register_hooks(&st, hooks);
	gfx_loop(&st);
	return (EXIT_SUCCESS);
}

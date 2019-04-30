/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/29 19:32:58 by nmartins       #+#    #+#                */
/*   Updated: 2019/04/30 17:03:19 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mlx.h>
#include <libgfx.h>
#include <libft.h>
#include <math.h>

int	keypress(int key_code, t_gfx_state *st)
{
	(void)st;
	if (key_code == KC_ESC || key_code == KC_Q)
		exit(0);
	return (0);
}

int	close(t_gfx_state *st)
{
	(void)st;
	exit(0);
}

/*
** Window appears
*/

int	expose(t_gfx_state *st)
{
	(void)st;
	return (0);
}

/*
** Render?
*/

typedef struct	s_ball
{
	t_vec2	pos;
	t_vec2	vel;
}				t_ball;

static t_ball mk_ball(t_vec2 pos)
{
	t_ball ball;

	ball.pos = pos;
	ball.vel = mk_vec2(2, 4);
	return (ball);
}

typedef struct	s_state
{
	t_ball *ball;
}				t_state;

static void	ball_update(t_ball *ball)
{
	ball->pos.x += ball->vel.x;
	ball->pos.y += ball->vel.y;

	if (ball->pos.x > 640 - 50)
	{
		ball->pos.x = 640 - 50;
		ball->vel.x = -ball->vel.x;
	}
	if (ball->pos.y > 480 - 50)
	{
		ball->pos.y = 480 - 50;
		ball->vel.y = -ball->vel.y;
	}
	if (ball->pos.x < 50)
	{
		ball->pos.x = 50;
		ball->vel.x = -ball->vel.x;
	}
	if (ball->pos.y < 50)
	{
		ball->pos.y = 50;
		ball->vel.y = -ball->vel.y;
	}
}

static void ball_render(t_gfx_state *st, t_ball *ball)
{
	for (int y = -50; y < 50; y++)
		for (int x = -50; x < 50; x++)
			if (abs((int)(pow((float)x, 2) + pow((float)y, 2))) < 1000)
				gfx_blit_pixel(st,
					RENDER_WINDOW,
					point_add(mk_point(x, y), demote_vec2(ball->pos)),
					gfx_color(255, 255, 255, 255));
}

int	render(t_gfx_state *st)
{
	t_state *user_state;

	user_state = st->user_state;
	mlx_clear_window(st->mlx_ptr, st->win_ptr);
	ball_update(user_state->ball);
	ball_render(st, user_state->ball);
	return (0);
}

int	main(void)
{
	t_gfx_state	st;
	t_hooks		hooks;
	t_state		ust;
	t_ball		ball;

	ball = mk_ball(mk_vec2(100, 100));
	ft_memset(&hooks, 0, sizeof(t_hooks));
	st.user_state = &st;
	if (gfx_mk_state(&st, mk_dimensions(640, 480), "Basic Window") == -1)
		return (EXIT_FAILURE);
	hooks.keypress = keypress;
	hooks.close = close;
	hooks.expose = expose;
	hooks.render = render;
	ust.ball = &ball;
	st.user_state = &ust;
	gfx_register_hooks(&st, hooks);
	gfx_loop(&st);
	ft_putendl("Hello");
	return (EXIT_SUCCESS);
}

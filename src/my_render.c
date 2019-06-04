/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   my_render.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 19:03:36 by nmartins       #+#    #+#                */
/*   Updated: 2019/06/04 14:18:02 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>
#include <math.h>
#include <libft.h>
#include "const.h"
#include "state.h"
#include "camera.h"

int			handle_keys(t_gfx_state *st)
{
	const double	rot_speed = 0.02;
	const double	mov_speed = st->key_state[KC_SHIFT] ? 0.5 : 0.1;
	t_state			*mst;

	mst = st->user_state;
	camera_move(&mst->camera,
		st->key_state[KC_D] * -mov_speed + st->key_state[KC_A] * mov_speed,
		st->key_state[KC_Q] * -mov_speed + st->key_state[KC_E] * mov_speed,
		st->key_state[KC_S] * -mov_speed + st->key_state[KC_W] * mov_speed);
	camera_rotate(&mst->camera,
		st->key_state[KC_DOWN] * -rot_speed + st->key_state[KC_UP] * rot_speed,
		st->key_state[KC_RIGHT] * -rot_speed
			+ st->key_state[KC_LEFT] * rot_speed,
		st->key_state[KC_O] * -rot_speed + st->key_state[KC_U] * rot_speed);
	return (0);
}

t_point		project(const t_vec3 *p, const t_state *mst)
{
	if (mst->projection == PROJ_PERSPECTIVE)
		return (mk_point(
			WIN_WIDTH / 2 + (p->x + mst->camera.position.x) /
				(p->z + mst->camera.position.z) * mst->fov,
			WIN_HEIGHT / 2 - (p->y + mst->camera.position.y) /
			(p->z + mst->camera.position.z) * mst->fov));
	else if (mst->projection == PROJ_ISOMETRIC)
		return (mk_point(
			WIN_WIDTH / 2 +
				(p->x - p->y * cos(0.523599)) * mst->fov,
			WIN_HEIGHT / 2 +
				(-p->z + (p->x + p->y) * sin(0.523599)) * mst->fov));
	else
		return (mk_point(0, 0));
}

void		render_lines(t_gfx_state *st, t_vec3 a, t_vec3 b)
{
	t_state *mst;
	t_vec3 alterated_a;
	t_vec3 alterated_b;
	t_point proj_a;
	t_point proj_b;

	mst = st->user_state;
	alterated_a = a;
	alterated_b = b;
	alterated_a = sub_vec3(gfx_rotation(add_vec3(a, mst->camera.position),
		mst->camera.rotation), mst->camera.position);
	alterated_b = sub_vec3(gfx_rotation(add_vec3(b, mst->camera.position),
		mst->camera.rotation), mst->camera.position);
	proj_a = project(&alterated_a, mst);
	proj_b = project(&alterated_b, mst);
	if ((alterated_a.z + mst->camera.position.z) * mst->fov <= 0
		|| (alterated_b.z + mst->camera.position.z) * mst->fov <= 0
		|| ((proj_a.x < 0 || proj_a.x >= WIN_WIDTH
		|| proj_a.y < 0 || proj_a.y >= WIN_HEIGHT)
		&& (proj_b.x < 0 || proj_b.x >= WIN_WIDTH
		|| proj_b.y < 0 || proj_b.y >= WIN_HEIGHT)))
		return ;
	gfx_line(st, st->buffer, mk_line(proj_a, proj_b), 0xAAAAAA);
		// gfx_color_from_rgb(gfx_hsl2rgb(mk_hsl(0, 1, 0.5))));
}

void		debug_info(t_gfx_state *st)
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

void		render(t_gfx_state *st)
{
	t_state	*mst;
	t_point	p;
	int		width;

	mst = st->user_state;
	handle_keys(st);
	gfx_fill_trgt(st, st->buffer, 0x00);
	p.y = 0;
	width = mst->point_count / mst->height;
	while (p.y < mst->height)
	{
		p.x = 0;
		while (p.x < width)
		{
			if (p.x < width - 1)
				render_lines(st, mst->points[p.y * width + p.x],
								mst->points[p.y * width + p.x + 1]);
			if (p.y < mst->height - 1)
				render_lines(st, mst->points[p.y * width + p.x],
								mst->points[(p.y + 1) * width + p.x]);
			p.x++;
		}
		p.y++;
	}
	gfx_blit_image(st, st->buffer, mk_point(0, 0));
	debug_info(st);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   my_render.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 20:17:48 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/05 13:16: by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>
#include <libft.h>
#include "const.h"
#include "state.h"
# include <stdio.h>
#include <math.h>

int	handle_keys(t_gfx_state *st)
{
	t_state *mst;

	mst = st->user_state;
	mst->camera_pos.z += st->key_state[KC_S] * 0.5;
	mst->camera_pos.z -= st->key_state[KC_W] * 0.5;
	mst->camera_pos.x -= st->key_state[KC_D] * 0.5;
	mst->camera_pos.x += st->key_state[KC_A] * 0.5;
	mst->camera_pos.y += st->key_state[KC_Q] * 0.5;
	mst->camera_pos.y -= st->key_state[KC_Q] * 0.5;
	if (st->key_state[KC_Q])
		mst->camera_pos.y += 0.5;
	if (st->key_state[KC_E])
		mst->camera_pos.y -= 0.5;
	if (st->key_state[KC_UP])
		mst->camera_rotation.x += 0.01;
	if (st->key_state[KC_DOWN])
		mst->camera_rotation.x -= 0.01;
	if (st->key_state[KC_O])
		mst->camera_rotation.z -= 0.01;
	if (st->key_state[KC_U])
		mst->camera_rotation.z += 0.01;
	if (st->key_state[KC_LEFT])
		mst->camera_rotation.y += 0.01;
	if (st->key_state[KC_RIGHT])
		mst->camera_rotation.y -= 0.01;
	return (0);
}

int	render_lines(t_gfx_state *st, t_vec3 a, t_vec3 b)
{
	t_state *mst;
	t_vec3 alterated_a;
	t_vec3 alterated_b;
	t_point proj_a;
	t_point proj_b;
	t_matrix rotator;
	int fov;

	mst = st->user_state;
	fov = mst->fov;
	// alterated_a = a;
	// alterated_b = b;
	ft_memset(rotator, 0l, sizeof(t_matrix));
	gfx_rotation_matrix_x(rotator, mst->camera_rotation.x);
	alterated_a = sub_vec3(gfx_rotate(rotator, add_vec3(a, mst->camera_pos)), mst->camera_pos);
	alterated_b = sub_vec3(gfx_rotate(rotator, add_vec3(b, mst->camera_pos)), mst->camera_pos);
	proj_a = mk_point(
		WIN_WIDTH / 2 + (alterated_a.x + mst->camera_pos.x) /
			(alterated_a.z + mst->camera_pos.z) * fov,
		WIN_HEIGHT / 2 - (alterated_a.y + mst->camera_pos.y) /
		(alterated_a.z + mst->camera_pos.z) * fov);
	proj_b = mk_point(
		WIN_WIDTH / 2 + (alterated_b.x + mst->camera_pos.x) /
		(alterated_b.z + mst->camera_pos.z) * fov,
		WIN_HEIGHT / 2 - (alterated_b.y + mst->camera_pos.y) /
		(alterated_b.z + mst->camera_pos.z) * fov);
	if ((alterated_a.z + mst->camera_pos.z) * fov <= 0
	 || (alterated_b.z + mst->camera_pos.z) * fov <= 0
	 || ((proj_a.x < 0
	 || proj_a.x >= WIN_WIDTH
	 || proj_a.y < 0
	 || proj_a.y >= WIN_HEIGHT)
	 && (proj_b.x < 0
	 || proj_b.x >= WIN_WIDTH
	 || proj_b.y < 0
	 || proj_b.y >= WIN_HEIGHT
	 )))
	 {
		//  ft_putchar('.');
		 return (-1);
	 }
	gfx_line(st, st->buffer, mk_line(proj_a, proj_b), gfx_color_from_rgb(gfx_hsl2rgb(mk_hsl(((int)a.x + gfx_get_current_epoch() / 10)/10 % 360, 1, 0.5))));
		// gfx_color_from_rgb(gfx_hsl2rgb(mk_hsl(0, fmax(0, fmin(1, -a.y/100)), 0.5))));
	return (0);
}

int	render(t_gfx_state *st)
{
	t_state *mst;
	char	*fps;

	mst = st->user_state;
	handle_keys(st);
	gfx_fill_trgt(st, st->buffer, 0x00);
	int width;
	width = mst->point_count / mst->height;
	for (int y = 0; y < mst->height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (x < width - 1)
				render_lines(st, mst->points[y * width + x], mst->points[y * width + x + 1]);
			if (y < mst->height - 1)
				render_lines(st, mst->points[y * width + x], mst->points[(y + 1) * width + x]);
		}
	}
	gfx_blit_image(st, st->buffer, mk_point(0, 0));
	fps = ft_itoa(gfx_get_fps(1));
	ft_strreplace(&fps, ft_strjoin(fps, " frames per second"));
	mlx_string_put(st->mlx_ptr,
		st->win_ptr, WIN_WIDTH - 300, 10, gfx_color_from_rgb(gfx_hsl2rgb(mk_hsl((gfx_get_current_epoch() / 10) % 360, 1, 0.5))), fps);
	free(fps);
	return (0);
}

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

int	handle_keys(t_gfx_state *st)
{
	t_state *mst;

	mst = st->user_state;
	if (st->key_state[KC_UP])
		mst->camera_pos.z += 0.3;
	if (st->key_state[KC_DOWN])
		mst->camera_pos.z -= 0.3;
	if (st->key_state[KC_LEFT])
		mst->camera_pos.x += 0.1;
	if (st->key_state[KC_RIGHT])
		mst->camera_pos.x -= 0.1;
	if (st->key_state[KC_A])
		mst->camera_pos.y += 0.1;
	if (st->key_state[KC_O])
		mst->camera_pos.y -= 0.1;
	if (st->key_state[KC_P])
		mst->camera_rotation.x += 0.01;
	if (st->key_state[KC_Y])
		mst->camera_rotation.x -= 0.01;
	return (0);
}

int	render(t_gfx_state *st)
{
	t_state *mst;
	char	*fps;

	mst = st->user_state;
	handle_keys(st);
	gfx_fill_trgt(st, st->buffer, 0x00);
	fps = ft_itoa(gfx_get_fps(1));
	// printf("%d points\n", mst->point_count);
	for (int i = 0; i < mst->point_count; i++)
	{
		double fov_dividend = mst->camera_pos.z / 100;
		t_vec3 v3 = mst->points[i];
		v3 = sub_vec3(gfx_rotation_x(add_vec3(v3, mst->camera_pos), mst->camera_rotation.x), mst->camera_pos);
		t_point p = mk_point(WIN_WIDTH / 2 + (v3.x + mst->camera_pos.x) / (v3.z + fov_dividend), WIN_HEIGHT / 2 + (v3.y + mst->camera_pos.y) / (v3.z + fov_dividend));
		if (p.x > WIN_WIDTH || p.x < 0 || p.y > WIN_HEIGHT || p.y < 0 || v3.z + fov_dividend <= 0)
			continue;
		gfx_blit_pixel(st, st->buffer, p, 0xFFFFFF);
	}
	gfx_blit_image(st, st->buffer, mk_point(0, 0));
	mlx_string_put(st->mlx_ptr,
		st->win_ptr, WIN_WIDTH - 200, 10, gfx_color(255, 255, 255, 255), fps);
	free(fps);
	return (0);
}

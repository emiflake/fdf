/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_state.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 00:58:46 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/01 19:23:07 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>
#include <string.h>

int		gfx_mk_state(
	t_gfx_state *st,
	t_dimensions dimensions,
	char *window_title)
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (-1);
	st->mlx_ptr = mlx_ptr;
	win_ptr = mlx_new_window(mlx_ptr, dimensions.width,
		dimensions.height, window_title);
	if (win_ptr == NULL)
		return (-1);
	st->win_ptr = win_ptr;
	st->dimensions = dimensions;
	st->buffer = gfx_create_image(st, dimensions);
	if (st->buffer == NULL)
		return (-1);
	return (0);
}

int		gfx_free_state(
	t_gfx_state *st)
{
	gfx_free_image(st, &st->buffer);
	mlx_destroy_window(st->mlx_ptr, st->win_ptr);
	return (0);
}

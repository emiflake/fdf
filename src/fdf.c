/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/29 19:32:58 by nmartins       #+#    #+#                */
/*   Updated: 2019/04/30 01:32:09 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mlx.h>
#include <libgfx.h>
#include <libft.h>

int	keypress(int key_code, t_gfx_state *st)
{
	(void)st;
	if (key_code == KC_ESC || key_code == KC_Q)
		exit(0);
	return (0);
}

int main(void)
{
	t_gfx_state	st;
	t_hooks		hooks;

	if (gfx_mk_state(&st, mk_dimensions(640, 480), "Basic Window") == -1)
		return (EXIT_FAILURE);
	ft_memset(&hooks, 0, sizeof(t_hooks));
	hooks.keypress = keypress;
	gfx_register_hooks(&st, hooks);
	gfx_loop(&st);
    return (EXIT_SUCCESS);
}

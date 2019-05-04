/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   my_keys.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 20:20:40 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/02 22:04:59 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libgfx.h>
#include "state.h"

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

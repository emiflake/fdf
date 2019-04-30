/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_keys.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 00:56:08 by nmartins       #+#    #+#                */
/*   Updated: 2019/04/30 17:52:04 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>

void			gfx_key_state_down(t_key_state ks, int key_code)
{
	ks[key_code] = 1;
}

void			gfx_key_state_up(t_key_state ks, int key_code)
{
	ks[key_code] = 0;
}

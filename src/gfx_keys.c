/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_keys.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 00:56:08 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/01 19:55:50 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>
#include <libft.h>

void			gfx_key_state_down(t_key_state ks, int key_code)
{
	ks[key_code] = 1;
}

void			gfx_key_state_up(t_key_state ks, int key_code)
{
	ks[key_code] = 0;
}

void			gfx_debug_print_keystate(t_key_state keystate)
{
	int idx;

	ft_putstr("Keys currently down: <<<");
	idx = 0;
	while (idx < KEY_LIMIT)
	{
		if (keystate[idx] == 1)
		{
			ft_putnbr(idx);
			ft_putstr("; ");
		}
		idx++;
	}
	ft_putendl(">>>");
}

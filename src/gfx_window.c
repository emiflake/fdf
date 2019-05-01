/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_window.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 18:30:33 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/01 18:31:18 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "gfx_window.h"

void		gfx_clear_window(t_gfx_state *st)
{
	mlx_clear_window(st->mlx_ptr, st->win_ptr);
}

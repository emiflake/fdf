/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 20:50:12 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/02 20:51:56 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>
#include <libft.h>
#include "state.h"

void			init_state(t_state *trgt)
{
	ft_memset(trgt, 0, sizeof(t_state));
	trgt->counter = 0;
}

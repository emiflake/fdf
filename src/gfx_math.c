/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_math.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 19:56:50 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/01 20:02:29 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gfx_math.h"
#include <math.h>

int	gfx_math_clamp(int value, int min, int max)
{
	if (value > max)
		return (max);
	if (value < min)
		return (min);
	return (value);
}

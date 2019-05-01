/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_math.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 14:16:17 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/01 20:02:35 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_MATH_H
# define GFX_MATH_H

# define RANGE_LERP(n,lower,upper,min,max) (((b)-(a))*((x)-(min))/((max)-(min)))+(a)

int	gfx_math_clamp(int value, int min, int max);

#endif

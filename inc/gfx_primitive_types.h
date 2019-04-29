/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_primitive_types.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 00:57:04 by nmartins       #+#    #+#                */
/*   Updated: 2019/04/30 01:04:26 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_PRIMITIVE_TYPES_H
# define GFX_PRIMITIVE_TYPES_H

# define GFX_P_ORIGIN (mk_point(0, 0))
# define GFX_V_ORIGIN (mk_vec2(0, 0))

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

t_point			mk_point(int, int);

typedef struct	s_vec2
{
	double x;
	double y;
}				t_vec2;

t_vec2			mk_vec2(double, double);

/*
** Same as point, but for dimensions
*/
typedef struct	s_dimensions
{
	int width;
	int height;
}				t_dimensions;

t_dimensions	mk_dimensions(int, int);

#endif

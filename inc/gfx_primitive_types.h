/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_primitive_types.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 00:57:04 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/01 16:23:20 by nmartins      ########   odam.nl         */
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
t_point			point_add(t_point, t_point);

typedef struct	s_vec2
{
	double x;
	double y;
}				t_vec2;

t_vec2			mk_vec2(double, double);
double			vec2_distance(t_vec2, t_vec2);

/*
** Same as point, but for dimensions
*/
typedef struct	s_dimensions
{
	int width;
	int height;
}				t_dimensions;

t_dimensions	mk_dimensions(int, int);

/*
** Demotes a vec2 to a point, removing
** decimal information.
*/
t_point			demote_vec2(t_vec2 vec);

typedef struct	s_line
{
	t_point a;
	t_point b;
}				t_line;

t_line			mk_line(t_point a, t_point b);


#endif

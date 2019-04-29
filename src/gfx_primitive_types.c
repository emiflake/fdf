/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_primitive_types.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 00:55:09 by nmartins       #+#    #+#                */
/*   Updated: 2019/04/30 01:05:02 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>

t_point mk_point(int x, int y)
{
    t_point p;

    p.x = x;
    p.y = y;
    return (p);
}

t_dimensions mk_dimensions(int width, int height)
{
    t_dimensions p;

    p.width = width;
    p.height = height;
    return (p);
}
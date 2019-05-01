/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libgfx.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 00:57:14 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/01 18:31:31 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGFX_H
# define LIBGFX_H

/*
**  __      __  ______  ______  ______  __  __
** /\ \    /\ \/\  == \/\  ___\/\  ___\/\_\_\_\
** \ \ \___\ \ \ \  __<\ \ \__ \ \  __\\/_/\_\/_
**  \ \_____\ \_\ \_____\ \_____\ \_\    /\_\/\_\
**   \/_____/\/_/\/_____/\/_____/\/_/    \/_/\/_/
** --
** This file is an agglomeration file that will
** include all of the libgfx header files.
** --
** libgfx is my small library of functions related
** to graphical rendering.
*/

/*
** TODO: move entire library into a separate repo
*/
# include "gfx_color.h"
# include "gfx_keys.h"
# include "gfx_primitive_shapes.h"
# include "gfx_primitive_types.h"
# include "gfx_state.h"
# include "gfx_events.h"
# include "gfx_mouse.h"
# include "gfx_math.h"
# include "gfx_fps_counter.h"
# include "gfx_lines.h"
# include "gfx_window.h"

#endif

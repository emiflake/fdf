/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_fps_counter.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 15:52:37 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/01 16:01:52 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_FPS_COUNTER_H
# define GFX_FPS_COUNTER_H

# include <time.h>

long	gfx_get_current_epoch(void);
int		gfx_get_fps(int do_tick);

#endif

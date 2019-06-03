/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 20:48:59 by nmartins       #+#    #+#                */
/*   Updated: 2019/06/03 17:25:14 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H

# include "camera.h"

typedef struct	s_state
{
	t_camera	camera;
	t_vec3		*points;
	int			height;
	int			point_count;
	int			fov;
}				t_state;

void			init_state(t_state *trgt, char *filename);

#endif

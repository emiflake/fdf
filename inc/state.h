/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 20:48:59 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/06 14:41:32 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H

typedef struct	s_state
{
	t_vec3	camera_pos;
	t_vec3	camera_rotation;
	t_vec3	*points;
	int		height;
	int		point_count;
}				t_state;

void			init_state(t_state *trgt, char *filename);

#endif

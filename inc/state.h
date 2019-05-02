/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 20:48:59 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/02 20:50:06 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H

typedef struct	s_state
{
	int counter;
}				t_state;

void			init_state(t_state *trgt);

#endif

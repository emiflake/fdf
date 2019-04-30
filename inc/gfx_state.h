/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_state.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 00:57:10 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/01 00:48:22 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_STATE_H
# define GFX_STATE_H

# include "gfx_primitive_types.h"
# include "gfx_keys.h"

struct			s_gfx_image;

typedef struct	s_gfx_state
{
	/*
	** A pointer to the Minilib reference
	*/
	void				*mlx_ptr;

	/*
	** A pointer to the window being handled
	** Potential TODO: support multiple windows.
	*/
	void				*win_ptr;

	/*
	** User provided state, to be kept as a global
	** pointer.
	*/
	void				*user_state;

	/*
	** A stoorage of key state
	*/
	t_key_state			key_state;

	/*
	** Dimensions of the window
	*/
	t_dimensions		dimensions;

	struct s_gfx_image	*buffer;
}				t_gfx_state;

/*
** Create a gfx state, given basic properties
** TODO: make an options type
** returns success
*/
int				gfx_mk_state(
		t_gfx_state *out,
		t_dimensions dimensions,
		char *window_title);

/*
** Free inner elements.
** Does not free pointer.
*/
int				gfx_free_state(
		t_gfx_state *state);


#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_state.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 00:58:46 by nmartins       #+#    #+#                */
/*   Updated: 2019/04/30 01:07:22 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>
#include <string.h>

int				gfx_mk_state(
		t_gfx_state *out,
		t_dimensions dimensions,
		char *window_title)
{
    void *mlx_ptr;
    void *win_ptr;
    
    mlx_ptr = mlx_init();
    if (mlx_ptr == NULL)
        return (-1);
    out->mlx_ptr = mlx_ptr;
    win_ptr = mlx_new_window(mlx_ptr, dimensions.width, dimensions.height, window_title);
    if (win_ptr == NULL)
        return (-1);
    out->win_ptr = win_ptr;
    return (0);
}
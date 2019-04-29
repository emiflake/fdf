/* ************************************************************************** */
/*                                                                            */
/*                                                             ::::::::       */
/*   fdf.c                                                   :+:    :+:       */
/*                                                          +:+               */
/*   By: nmartins <nmartins@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2019/04/29 19:32:58 by nmartins            #+#    #+#           */
/*   Updated: 2019/04/29 21:11:20 by nmartins            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mlx.h>
#include <libgfx.h>

typedef struct    s_mlx_data
{
    void          *mlx_ptr;
    void          *mlx_win;
}                 t_mlx_data;

#define K_ESC 53

int key_press(int keycode, void *param)
{
	if (keycode == K_ESC)
		exit(0);
	(void)param;
	return (0);
}

int main(void)
{
    t_mlx_data        data;

    if ((data.mlx_ptr = mlx_init()) == NULL)
        return (EXIT_FAILURE);
    if ((data.mlx_win = mlx_new_window(data.mlx_ptr, 640, 480, "Hello world")) == NULL)
        return (EXIT_FAILURE);
	for (int y = 0; y < 480; y++)
		for (int x = 0; x < 640; x++)
			mlx_pixel_put(data.mlx_ptr, data.mlx_win, x, y, mk_color(x % 255, y % 255, 0xC1, 255));

	for (int x = 10; x > 0; x--)
		mlx_string_put(data.mlx_ptr, data.mlx_win, x, x, mk_color(0xFF / x, 0xB7 / x, 0xC1 / x, 0), "Hello Dominique");

	mlx_hook(data.mlx_win, 2, 0, key_press, 0);
    mlx_loop(data.mlx_ptr);
    return (EXIT_SUCCESS);
}

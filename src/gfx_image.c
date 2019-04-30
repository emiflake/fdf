/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_image.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 13:43:21 by nmartins       #+#    #+#                */
/*   Updated: 2019/04/30 20:31:12 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gfx_image.h"

t_gfx_image	*gfx_create_image(t_gfx_state *st, t_dimensions dim)
{
	t_gfx_image *img;

	img = (t_gfx_image *)malloc(sizeof(t_gfx_image));
	if (img == NULL)
		return (NULL);
	img->dim = dim;
	img->img_ptr = NULL;
	img->img_ptr = mlx_new_image(st->mlx_ptr, dim.width, dim.height);
	if (img->img_ptr == NULL)
	{
		free(img);
		return (NULL);
	}
	img->data_addr =
		mlx_get_data_addr(img->img_ptr,
			&img->bits_per_pixel,
			&img->size_line, &img->endian);
	if (img->data_addr == NULL)
	{
		mlx_destroy_image(st->mlx_ptr, img->img_ptr);
		free(img);
		return (NULL);
	}
	return (img);
}

void				gfx_free_image(t_gfx_state *st, t_gfx_image **img)
{
	mlx_destroy_image(st->mlx_ptr, (*img)->img_ptr);
	free(*img);
	*img = NULL;
}

void				gfx_blit_image(t_gfx_state *st, t_gfx_image *img, t_point p)
{
	mlx_put_image_to_window(st->mlx_ptr, st->win_ptr, img->img_ptr, p.x, p.y);
}

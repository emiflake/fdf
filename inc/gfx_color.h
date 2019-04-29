#include <mlx.h>

#ifndef COLOR_H
# define COLOR_H

typedef struct	s_rgb
{
	int r;
	int g;
	int b;
}				t_rgb;

typedef struct	s_hsl
{
	int h;
	int s;
	int l;
}				t_hsl;

/*
** Convert RGB color to int32 color
*/
int	gfx_color(int r, int g, int b, int a);

t_rgb gfx_hsl2rgb(t_hsl); // TODO
t_hsl gfx_rgb2hsl(t_rgb); // TODO

#endif

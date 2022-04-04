#include <math.h>
#include "event_bonus.h"
#include "vector3_bonus.h"

static int	rgb_extract(int mlx_color, t_color_mask type)
{
	return ((mlx_color >> type) & 0xFF);
}

static double	bilinear_interpolation(t_interpolation info, t_color_mask type)
{
	double	rgb;

	rgb = (1 - info.beta) * ((1 - info.alpha) * rgb_extract(info.a, type)
			+ info.alpha * rgb_extract(info.b, type))
		+ info.beta * ((1 - info.alpha) * rgb_extract(info.d, type)
			+ info.alpha * rgb_extract(info.c, type));
	return (rgb / 256);
}

static int	bilinear_set(double *weight, int index, double ratio)
{
	int		index_low;

	*weight = ((double)index + 0.5) * ratio - 0.5;
	index_low = floor(*weight);
	*weight -= index_low;
	return (index_low);
}

int	oversampling(t_xpm_image *image, int x, int y)
{
	t_interpolation	info;
	int				x_low;
	int				y_low;

	x_low = bilinear_set(&info.alpha, x, image->ratio_w);
	y_low = bilinear_set(&info.beta, y, image->ratio_h);
	info.a = xpm_pixel_get(image, x_low, y_low);
	info.b = xpm_pixel_get(image, x_low + 1, y_low);
	info.c = xpm_pixel_get(image, x_low + 1, y_low + 1);
	info.d = xpm_pixel_get(image, x_low, y_low + 1);
	return (color3_to_pixel(color3(
				bilinear_interpolation(info, RED),
				bilinear_interpolation(info, GREEN),
				bilinear_interpolation(info, BLUE))));
}

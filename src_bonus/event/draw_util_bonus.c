#include "event_bonus.h"

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line + x * (image->bpp / 8));
	*(unsigned int *)dst = color;
}

int	my_mlx_pixel_get(t_image *image, int x, int y)
{
	char	*dst;

	dst = image->addr + (y * image->line + x * (image->bpp / 8));
	return (*(unsigned int *)dst);
}

int	color_calc(double rgb)
{
	int	color;

	color = (int)(256 * rgb);
	if (color > 255)
		color = 255;
	return (color);
}

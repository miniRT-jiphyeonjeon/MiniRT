#include "print.h"

static int	calc_color(double rgb)
{
	int	color;

	color = (int)(256 * rgb);
	if (color > 255)
		color = 255;
	return (color);
}

void	write_color(t_color3 pixel_color)
{
	printf("%d %d %d\n",
			calc_color(pixel_color.x),
			calc_color(pixel_color.y),
			calc_color(pixel_color.z));
}
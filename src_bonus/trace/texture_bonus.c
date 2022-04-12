#include <math.h>
#include "trace_bonus.h"

t_bool	is_checkerboard(t_color_info texture)
{
	if (!texture.checkboard)
		return (FALSE);
	return (TRUE);
}

t_bool	is_bumptexture(t_color_info texture)
{
	if (!texture.bumpmap)
		return (FALSE);
	return (TRUE);
}

t_bool	is_bumpmap(t_color_info texture)
{
	if (!texture.bumpmap->bump)
		return (FALSE);
	return (TRUE);
}

t_color3	checker_color(double u, double v, t_color_info color)
{
	int	u_int;
	int	v_int;

	u_int = floor(u * color.checkboard->width);
	v_int = floor(v * color.checkboard->height);
	if ((u_int + v_int) % 2)
		return (color.color);
	else
		return (color.checkboard->check_color);
}

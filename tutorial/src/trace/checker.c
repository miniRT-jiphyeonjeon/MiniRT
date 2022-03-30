#include <math.h>
#include "trace.h"
#include "utils.h"

t_checker	checker(t_bool on, t_color3 even, t_color3 odd)
{
	t_checker	check;

	check.on = on;
	check.even = even;
	check.odd = odd;
	return (check);
}

t_color3	checker_color(double u, double v, t_point3 p, t_checker check)
{
	double			sines;
	const double	size = 10;

	sines = sin(size * p.x) * sin(size * p.y) * sin(size * p.z);
	if (sines < 0)
		return (check.odd);
	else
		return (check.even);
}

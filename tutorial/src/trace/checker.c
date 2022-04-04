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
	int	u2;
	int	v2;

	u2 = floor(u * CHECKER_WIDTH);
	v2 = floor(v * CHECKER_HEIGHT);

	if ((u2 + v2) % 2)
		return (check.odd);
	else
		return (check.even);
}

#include "ft_math.h"

double	ft_fmod_abs(double x, double mod)
{
	if (x < 0)
		return (x + mod);
	return (x);
}

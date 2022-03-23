#include "libft.h"
#include <stdlib.h>

static double	return_func(double d, int *valid, int i)
{
	*valid = i;
	return (d);
}

/*
e+10 e-10 E+10 E-10 미구현, 찾아봐야할듯
25줄 이슈 있음
*/
double	ft_atof(char *str, int *valid)
{
	double		integer;
	double		decimal;
	int			sign;
	int			decimal_idx;

	integer = 0.0;
	decimal = 0.0;
	sign = 1;
	decimal_idx = 0;
	if (str == NULL)
		return (return_func(integer, valid, -1));
	while (ft_isspace(*str) == 1)
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		++str;
	}
	if (ft_isdigit(*str) == 0 && *str != '.')
		return (return_func(integer, valid, 0));
	while (*str != '\0' && ft_isdigit(*str) == 1)
	{
		integer = integer * 10 + *str - '0';
		++str;
	}
	if (*str != '.')
		return (return_func(integer * sign, valid, 0));
	++str;
	while (*str != '\0' && ft_isdigit(*str) == 1)
	{
		decimal = decimal * 10 + *str - '0';
		++str;
		++decimal_idx;
	}
	while (--decimal_idx >= 0)
		decimal /= 10;
	*valid = *str == '\0';
	return ((integer + decimal) * sign);
}

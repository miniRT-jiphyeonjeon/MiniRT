#include "libft.h"
#include <stdlib.h>

static double	return_func(double d, t_res *valid, t_res res)
{
	*valid = res;
	return (d);
}

/*
e+10 e-10 E+10 E-10 미구현, 찾아봐야할듯
25줄 이슈 있음
*/
double	ft_atof(char *str, t_res *valid)
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
		return (return_func(integer, valid, ERR));
	while (ft_isspace(*str) == TRUE)
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		++str;
	}
	if (ft_isdigit(*str) == FALSE && *str != '.')
		return (return_func(integer, valid, NOTCLEAN));
	while (*str != '\0' && ft_isdigit(*str) == TRUE)
	{
		integer = integer * 10 + *str - '0';
		++str;
	}
	if (*str == '\0')
		return (return_func(integer * sign, valid, CLEAN));
	else if (*str != '.')
		return (return_func(integer * sign, valid, NOTCLEAN));
	++str;
	while (*str != '\0' && ft_isdigit(*str) == TRUE)
	{
		decimal = decimal * 10 + *str - '0';
		++str;
		++decimal_idx;
	}
	while (--decimal_idx >= 0)
		decimal /= 10;
	if (*str == '\0')
		*valid = CLEAN;
	else
		*valid = NOTCLEAN;
	return ((integer + decimal) * sign);
}

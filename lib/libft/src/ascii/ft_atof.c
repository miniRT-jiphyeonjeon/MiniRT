/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:07:31 by cjang             #+#    #+#             */
/*   Updated: 2022/04/17 22:26:32 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "ft_ascii.h"

static double	return_func(double d, t_res *valid, t_res res)
{
	*valid = res;
	return (d);
}

static int	space_sign_check(char **str)
{
	int		sign;

	sign = 1;
	while (ft_isspace(**str) == TRUE)
		*str += 1;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign *= -1;
		*str += 1;
	}
	return (sign);
}

static double	str_to_integer(char **str)
{
	double	integer;

	integer = 0.0;
	while (**str != '\0' && ft_isdigit(**str) == TRUE)
	{
		integer = integer * 10 + **str - '0';
		*str += 1;
	}
	return (integer);
}

static double	str_to_decimal(char **str)
{
	double	decimal;
	double	deciaml_tmp;
	int		idx;

	decimal = 0.0;
	idx = 0;
	while (**str != '\0' && ft_isdigit(**str) == TRUE)
	{
		deciaml_tmp = decimal * 10 + **str - '0';
		if (deciaml_tmp == INFINITY)
			break ;
		decimal = deciaml_tmp;
		*str += 1;
		++idx;
	}
	while (**str != '\0' && ft_isdigit(**str) == TRUE)
		*str += 1;
	while (--idx >= 0)
		decimal /= 10;
	return (decimal);
}

double	ft_atof(char *str, t_res *valid)
{
	int			sign;
	double		integer;
	double		decimal;

	if (str == NULL)
		return (return_func(0.0, valid, ERR));
	sign = space_sign_check(&str);
	if (ft_isdigit(*str) == FALSE && *str != '.')
		return (return_func(0.0, valid, NOTCLEAN));
	integer = str_to_integer(&str);
	if (*str == '\0')
		return (return_func(integer * sign, valid, CLEAN));
	else if (*str != '.')
		return (return_func(integer * sign, valid, NOTCLEAN));
	++str;
	decimal = str_to_decimal(&str);
	if (*str == '\0')
		*valid = CLEAN;
	else
		*valid = NOTCLEAN;
	return ((integer + decimal) * sign);
}

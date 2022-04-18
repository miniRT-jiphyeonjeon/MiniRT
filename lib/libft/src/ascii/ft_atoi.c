/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:07:29 by cjang             #+#    #+#             */
/*   Updated: 2022/04/17 22:37:36 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ascii.h"

static double	return_func(int i, t_res *valid, t_res res)
{
	*valid = res;
	return (i);
}

static unsigned long long	str_to_number(const char **str, int sign)
{
	unsigned long long	number;

	number = 0;
	while (**str >= '0' && **str <= '9')
	{
		if (sign == -1 && (number > 922337203685477580 || \
		(number >= 922337203685477580 && **str - '0' >= 8)))
			return (0);
		else if (sign == 1 && (number > 922337203685477580 || \
		(number >= 922337203685477580 && **str - '0' >= 7)))
			return (-1);
		number = number * 10 + **str - '0';
		*str += 1;
	}
	return (number);
}

int	ft_atoi(const char *str, t_res *valid)
{
	int					sign;
	unsigned long long	number;

	sign = 1;
	if (str == NULL)
		return (return_func(0, valid, ERR));
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	number = str_to_number(&str, sign);
	if (*str == '\0')
		*valid = CLEAN;
	else
		*valid = NOTCLEAN;
	return (number * sign);
}

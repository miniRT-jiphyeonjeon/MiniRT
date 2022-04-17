/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:19:55 by cjang             #+#    #+#             */
/*   Updated: 2022/04/17 22:37:14 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_write.h"

int	ft_writes(int fd, char *arr[])
{
	int	i;
	int	res;

	i = -1;
	res = 0;
	while (arr[++i])
		res += ft_write(fd, arr[i]);
	return (res);
}

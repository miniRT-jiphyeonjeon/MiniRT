/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:19:53 by cjang             #+#    #+#             */
/*   Updated: 2022/04/17 22:37:09 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_write.h"
#include "ft_string.h"

int	ft_write(int fd, const char *str)
{
	return (write(fd, str, ft_strlen(str)));
}

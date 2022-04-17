/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:07:58 by cjang             #+#    #+#             */
/*   Updated: 2022/04/17 22:32:46 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"
#include "ft_memory.h"

char	*ft_strdup(const char *s1)
{
	size_t		i;
	size_t		len;
	char		*cp;

	i = 0;
	len = 0;
	while (s1[len])
		len++;
	cp = ft_calloc(sizeof(char), len);
	while (i < len + 1)
	{
		cp[i] = s1[i];
		i++;
	}
	return (cp);
}

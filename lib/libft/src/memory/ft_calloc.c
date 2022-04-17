/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:19:40 by cjang             #+#    #+#             */
/*   Updated: 2022/04/17 22:30:27 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_memory.h"

void	*ft_calloc(size_t size, size_t count)
{
	char			*ptr;
	const size_t	allocated_space = size * (count + 1);

	ptr = malloc(allocated_space);
	if (!ptr)
	{
		perror("Error\nCannot allocate memory\n");
		exit(EXIT_FAILURE);
	}
	ft_bzero(ptr, allocated_space);
	return (ptr);
}

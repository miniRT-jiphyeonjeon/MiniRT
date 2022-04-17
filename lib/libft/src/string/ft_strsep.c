/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:08:03 by cjang             #+#    #+#             */
/*   Updated: 2022/04/17 22:29:13 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strsep(char **stringp, const char delim)
{
	char	*tmp;

	tmp = *stringp;
	if (tmp == NULL)
		return (NULL);
	while (**stringp)
	{
		if (**stringp == delim)
		{
			**stringp = '\0';
			(*stringp)++;
			return (tmp);
		}
		(*stringp)++;
	}
	*stringp = NULL;
	return (tmp);
}

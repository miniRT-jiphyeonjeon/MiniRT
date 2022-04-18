/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:04:45 by cjang             #+#    #+#             */
/*   Updated: 2022/04/17 22:53:08 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "parse_bonus.h"

t_parse	*new_parse(void)
{
	t_parse		*lst;

	lst = ft_calloc(sizeof(t_parse), 0);
	return (lst);
}

void	del_parse(t_parse *parse)
{
	if (parse->ident != NULL)
		free(parse->ident);
	if (parse->bri_ratio != NULL)
		free(parse->bri_ratio);
	if (parse->point != NULL)
		free(parse->point);
	if (parse->nor_vec != NULL)
		free(parse->nor_vec);
	if (parse->diameter != NULL)
		free(parse->diameter);
	if (parse->height != NULL)
		free(parse->height);
	if (parse->fov != NULL)
		free(parse->fov);
	if (parse->rgb != NULL)
		free(parse->rgb);
	if (parse->kd != NULL)
		free(parse->kd);
	if (parse->ks != NULL)
		free(parse->ks);
	if (parse->ksn != NULL)
		free(parse->ksn);
}

void	del_parse_texture(t_parse *parse)
{
	if (parse->t_ident != NULL)
		free(parse->t_ident);
	if (parse->check_color != NULL)
		free(parse->check_color);
	if (parse->check_width != NULL)
		free(parse->check_width);
	if (parse->check_height != NULL)
		free(parse->check_height);
	if (parse->texture_file != NULL)
		free(parse->texture_file);
	if (parse->bump_file != NULL)
		free(parse->bump_file);
}

t_parse	*del_split(char **str)
{
	int		idx;

	idx = 0;
	while (str[idx] != NULL)
		free(str[idx++]);
	free(str);
	return (NULL);
}

int	split_len(char **str)
{
	int		i;

	i = 0;
	while (str[i] != NULL)
		++i;
	return (i);
}

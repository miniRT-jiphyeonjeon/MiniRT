/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str_set_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:04:12 by cjang             #+#    #+#             */
/*   Updated: 2022/04/17 21:32:51 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "parse_bonus.h"
#include "error_bonus.h"

int	parse_set(t_parse *lst, char **str)
{
	int		idx;

	idx = 1;
	lst->ident = str[0];
	lst->id = element_type_get(str[0]);
	if (lst->id == NOTTYPE)
		error_user("Invalid element name.\n");
	if (is_element_valid(lst->id, str) == FALSE)
		error_user("Elements came in less than standard.\n");
	if (is_info_valid(lst->id, POINT))
		lst->point = str[idx++];
	if (is_info_valid(lst->id, BRI_RATIO))
		lst->bri_ratio = str[idx++];
	if (is_info_valid(lst->id, NOR_VEC))
		lst->nor_vec = str[idx++];
	if (is_info_valid(lst->id, DIAMETER))
		lst->diameter = str[idx++];
	if (is_info_valid(lst->id, HEIGHT))
		lst->height = str[idx++];
	if (is_info_valid(lst->id, FOV))
		lst->fov = str[idx++];
	return (idx);
}

static void	parse_obj_set(t_parse *lst, char **str, int idx)
{
	lst->t_ident = str[idx++];
	if (lst->texture_id == COLOR)
		lst->rgb = str[idx++];
	else if (lst->texture_id == CHECKBOARD)
	{
		lst->rgb = str[idx++];
		lst->check_color = str[idx++];
		lst->check_width = str[idx++];
		lst->check_height = str[idx++];
	}
	if (lst->texture_id == BUMPMAP)
		lst->texture_file = str[idx++];
	if (lst->texture_id == BUMPMAP && str[idx + 3] != NULL)
		lst->bump_file = str[idx++];
	lst->kd = str[idx++];
	lst->ks = str[idx++];
	lst->ksn = str[idx++];
}

void	parse_color_obj_set(t_parse *lst, char **str, int idx)
{
	lst->texture_id = color_obj_valid_get(lst->id, str, idx);
	if (lst->texture_id == ERROR_LESS)
		error_user("Elements came in less than standard.\n");
	else if (lst->texture_id == ERROR_MORE)
		error_user("Elements came in more than standard.\n");
	else if (lst->texture_id == NOTCOLOR)
		error_user("Color type for that location is not standard.\n");
	if (lst->id == AMBIENT || lst->id == POINT_LIGHT)
		lst->rgb = str[idx++];
	else if (lst->id == SPHERE || lst->id == PLANE || \
	lst->id == CYLINDER || lst->id == CONE)
		parse_obj_set(lst, str, idx);
}

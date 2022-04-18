/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_del_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:03:56 by cjang             #+#    #+#             */
/*   Updated: 2022/04/17 21:30:02 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list_bonus.h"
#include "parse_bonus.h"

void	del_color(t_color_info color)
{
	if (color.checkboard != NULL)
		free(color.checkboard);
	if (color.bumpmap != NULL)
	{
		if (color.bumpmap->texture != NULL)
		{
			if (color.bumpmap->texture->data.img != NULL)
				free(color.bumpmap->texture->data.img);
			free(color.bumpmap->texture);
		}
		if (color.bumpmap->bump != NULL)
		{
			if (color.bumpmap->bump->data.img != NULL)
				free(color.bumpmap->bump->data.img);
			free(color.bumpmap->bump);
		}
		free(color.bumpmap);
	}
}

void	del_obj_list(t_obj_list **lst)
{
	t_obj_list	*first_lst;
	t_obj_list	*second_lst;

	second_lst = *lst;
	*lst = NULL;
	while (second_lst)
	{
		first_lst = second_lst;
		second_lst = second_lst->next;
		del_color(first_lst->color);
		free(first_lst->object);
		free(first_lst);
	}
}

void	del_obj_lst_parse(t_obj_list **lst)
{
	t_obj_list	*first_lst;
	t_obj_list	*second_lst;

	second_lst = *lst;
	*lst = NULL;
	while (second_lst)
	{
		first_lst = second_lst;
		second_lst = second_lst->next;
		del_color(first_lst->color);
		del_parse(first_lst->object);
		del_parse_texture(first_lst->object);
		free(first_lst->object);
		free(first_lst);
	}
}

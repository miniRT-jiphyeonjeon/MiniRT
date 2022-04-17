/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_to_element_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:04:20 by cjang             #+#    #+#             */
/*   Updated: 2022/04/17 21:33:27 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "scene_bonus.h"
#include "parse_bonus.h"
#include "event_bonus.h"

t_scene	*parse_to_element(t_parse_list *lst, void *mlx_ptr)
{
	t_scene		*scene;
	t_parse		*lst_parse;

	scene = new_scene(WIN_WIDTH, WIN_HEIGHT);
	while (lst)
	{
		lst_parse = lst->object;
		if (lst_parse->id == AMBIENT)
			scene->ambient = ambient_set(lst);
		else if (lst_parse->id == CAMERA)
			scene->camera = camera_prev_set(scene, lst);
		else if (lst_parse->id == POINT_LIGHT)
			light_set(scene, lst);
		else if (lst_parse->id == SPHERE || lst_parse->id == PLANE || \
		lst_parse->id == CYLINDER || lst_parse->id == CONE)
			object_set(scene, lst, mlx_ptr);
		lst = lst->next;
	}
	return (scene);
}

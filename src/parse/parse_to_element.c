/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_to_element.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:06:24 by cjang             #+#    #+#             */
/*   Updated: 2022/04/17 21:06:29 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "scene.h"
#include "parse.h"
#include "event.h"

t_scene	*parse_to_element(t_parse_list *lst)
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
		else if (lst_parse->id == SPHERE)
			sphere_set(scene, lst);
		else if (lst_parse->id == PLANE)
			plane_set(scene, lst);
		else if (lst_parse->id == CYLINDER)
			cylinder_set(scene, lst);
		lst = lst->next;
	}
	return (scene);
}

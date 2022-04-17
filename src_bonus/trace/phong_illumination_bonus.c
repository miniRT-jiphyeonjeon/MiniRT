/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_illumination_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojekim <hyojekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:46:47 by hyojekim          #+#    #+#             */
/*   Updated: 2022/04/17 21:46:47 by hyojekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace_bonus.h"
#include "vector3_bonus.h"

t_color3	phong_illumination_model(t_scene *scene)
{
	t_color3	ambient_color;
	t_color3	result_color;
	t_obj_list	*light;

	result_color = color3(0, 0, 0);
	light = scene->lights;
	while (light)
	{
		if (light->type == POINT_LIGHT)
			result_color = vec3_plus(
					result_color, point_light_get(scene, light));
		light = light->next;
	}
	ambient_color = vec3_mult_scalar(scene->ambient.light_color,
			scene->ambient.light_ratio);
	result_color = vec3_plus(result_color, ambient_color);
	return (vec3_min(color3(1, 1, 1),
			vec3_mult(result_color, scene->record.color)));
}

t_color3	point_light_get(t_scene *scene, t_obj_list *light)
{
	t_light	*light_data;
	t_vec3	light_dir;
	t_vec3	phong_color;
	double	light_len;

	light_data = (t_light *)light->object;
	light_dir = vec3_minus(light_data->origin, scene->record.p);
	light_len = vec3_length(light_dir);
	light_dir = vec3_unit(light_dir);
	if (is_in_shadow(scene, light_dir, light_len))
		return (color3(0, 0, 0));
	phong_color = vec3_plus(phong_diffuse(scene, light, light_dir),
			phong_specular(scene, light, light_dir));
	return (vec3_mult_scalar(phong_color, light_data->bright_ratio));
}

void	hit_color_set(t_hit_record *rec, t_obj_list objects[])
{
	if (is_checkerboard(objects->color))
		rec->color = checker_color(rec->u, rec->v, objects->color);
	else if (is_bumptexture(objects->color))
	{
		rec->color
			= image_mapping(rec->u, rec->v, objects->color.bumpmap->texture);
		if (is_bumpmap(objects->color))
			rec->normal = normal_mapping(rec, objects->color.bumpmap->bump);
	}
	else
		rec->color = objects->color.color;
}

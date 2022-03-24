#include "trace.h"
#include "vector3.h"

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

	light_data = (t_light *)light->object;
	light_dir = vec3_minus(light_data->origin, scene->record.p);
	if (is_in_shadow(scene, light_dir))
		return (color3(0, 0, 0));
	light_dir = vec3_unit(light_dir);
	phong_color = vec3_plus(phong_diffuse(scene, light, light_dir),
			phong_specular(scene, light, light_dir));
	return (vec3_mult_scalar(phong_color, light_data->bright_ratio));
}

#include "trace.h"

t_color3	phong_lighting(t_scene *scene)
{
	t_color3	light_color;
	t_object	*lights;

	light_color = color3(0, 0, 0);
	lights = scene->lights;
	while (lights)
	{
		if (lights->type == LIGHT_POINT)
			light_color = vplus_(light_color, point_light_get(scene, lights->data));
		lights = lights->next;
	}
	// light_color = vplus_(light_color, scene->ambient);
	return (vmin(color3(1, 1, 1), vmult_(light_color, scene->rec.albedo)));
}

static t_vec3	reflect(t_vec3 l, t_vec3 n)
{
	return (vminus_(vmult(n, vdot(n, l) * 2), l));
}

t_color3	point_light_get(t_scene *scene, t_light *light)
{
	double		brightness;

	t_color3	diffuse;
	t_vec3		light_dir;
	double		kd;

	t_color3	specular;
	t_vec3		view_dir;
	t_vec3		reflect_dir;
	double		spec;
	double		ksn;
	double		ks;

	t_ray		shadow_ray;
	double		light_len;

	light_dir = vminus_(light->origin, scene->rec.p);
	light_len = vlength(light_dir);
	light_dir = vunit(light_dir);

	shadow_ray = ray(vplus_(scene->rec.p, vmult(light_dir, EPSILON)), light_dir);
	if (in_shadow(scene->objects, shadow_ray, light_len))
		return (color3(0, 0, 0));
	
	kd = fmax(0.0, vdot(scene->rec.normal, light_dir));
	diffuse = vmult(light->light_color, kd);


	view_dir = vunit(vmult(scene->ray.direct, -1));
	reflect_dir = reflect(light_dir, scene->rec.normal);
	ksn = 64;
	ks = 0.5;
	spec = pow(fmax(0.0, vdot(reflect_dir, view_dir)), ksn);
	specular = vmult(vmult(light->light_color, ks), spec);

	brightness = light->bright_ratio * LUMEN;
	return (vmult(vplus_(vplus_(diffuse, specular), scene->ambient), brightness));
}

t_bool	in_shadow(t_object objects[], t_ray shadow_ray, double light_len)
{
	t_hit_record	rec;

	rec.tmin = 0;
	rec.tmax = light_len;
	if (hit(objects, &shadow_ray, &rec))
		return (TRUE);
	return (FALSE);
}

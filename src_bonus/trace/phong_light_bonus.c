#include <math.h>
#include "trace_bonus.h"
#include "vector3_bonus.h"

/*	Id = Ld * kd * (n·l)
	ex) kd = 1
*/
t_color3	phong_diffuse(t_scene *scene, t_obj_list *light, t_vec3 light_dir)
{
	double		kd;

	kd = fmax(0.0, vec3_dot(scene->record.normal, light_dir));
	return (vec3_mult_scalar(light->color.color, kd));
}

//	r = 2(n·l)n - l
static t_vec3	reflect(t_vec3 l, t_vec3 n)
{
	return (vec3_minus(vec3_mult_scalar(n, vec3_dot(n, l) * 2), l));
}

/*	Is = Ls * ks * (r·v)^ksn
	ex) ks = 0.5, ksn = 64
*/
t_color3	phong_specular(t_scene *scene, t_obj_list *light, t_vec3 light_dir)
{
	t_vec3			view_dir;
	t_vec3			reflect_dir;
	double			spec;
	const double	ksn = 5;
	const double	ks = 0.2;

	view_dir = vec3_unit(vec3_mult_scalar(scene->ray.direction, -1));
	reflect_dir = reflect(light_dir, scene->record.normal);
	spec = pow(fmax(0.0, vec3_dot(reflect_dir, view_dir)), ksn);
	return (vec3_mult_scalar(vec3_mult_scalar(light->color.color, ks), spec));
}

t_bool	is_in_shadow(t_scene *scene, t_vec3 light_dir, double light_len)
{
	t_ray			shadow_ray;
	t_hit_record	record;

	shadow_ray = ray_set(vec3_plus(scene->record.p,
				vec3_mult_scalar(light_dir, EPSILON)), light_dir);
	record.tmin = 0;
	record.tmax = light_len;
	if (hit(scene->objects, &shadow_ray, &record))
		return (TRUE);
	return (FALSE);
}

#include <math.h>
#include "trace_bonus.h"
#include "vector3_bonus.h"

t_ray	ray_set(t_point3 origin, t_vec3 direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}

// d = LB + ⍺ * u + β * v + e
t_ray	ray_primary(t_camera *cam, double alpha, double beta)
{
	t_ray	ray;

	ray.origin = cam->origin;
	ray.direction = vec3_unit(vec3_minus(vec3_plus(vec3_plus(cam->left_bottom,
						vec3_mult_scalar(cam->horizontal, alpha)),
					vec3_mult_scalar(cam->vertical, beta)), cam->origin));
	return (ray);
}

//	p = e + td
t_point3	ray_at(t_ray *ray, double t)
{
	t_point3	at;

	at = vec3_plus(ray->origin, vec3_mult_scalar(ray->direction, t));
	return (at);
}

static t_hit_record	record_init(void)
{
	t_hit_record	record;

	record.tmin = EPSILON;
	record.tmax = INFINITY;
	return (record);
}

t_color3	ray_tracing(t_scene *scene)
{
	double	t;

	scene->record = record_init();
	if (hit(scene->objects, &scene->ray, &scene->record))
		return (phong_illumination_model(scene));
	else
		// return (color3(-1, -1, -1));
	{	
		t = 0.5 * (scene->ray.direction.y + 1.0);
		return (vec3_plus(vec3_mult_scalar(color3(1, 1, 1), 1.0 - t),
				vec3_mult_scalar(color3(0.5, 0.7, 1.0), t)));
	}
}

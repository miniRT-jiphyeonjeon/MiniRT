#include "trace.h"
#include "vector3.h"

t_ray	ray_set(t_point3 origin, t_vec3 direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}

t_ray	ray_primary(t_camera *cam, double alpha, double beta)
{
	t_ray	ray;

	ray.origin = cam->origin;
	ray.direction = vec3_unit(vec3_minus(vec3_plus(vec3_plus(cam->left_bottom,
						vec3_mult_scalar(cam->horizontal, alpha)),
					vec3_mult_scalar(cam->vertical, beta)), cam->origin));
	return (ray);
}

t_color3	ray_color(t_scene *scene)
{
	double	t;

	t = 0.5 * (scene->ray.direction.y + 1.0);
	return (vec3_plus(vec3_mult_scalar(color3(1, 1, 1), 1.0 - t),
			vec3_mult_scalar(color3(0.5, 0.7, 1.0), t)));
}

#include "trace.h"

t_ray	ray(t_point3 origin, t_vec3 direct)
{
	t_ray	ray;

	ray.origin	= origin;
	ray.direct = vunit(direct);
	return (ray);
}

t_point3	ray_at(t_ray *ray, double t)
{
	t_point3	at;

	at = vplus_(ray->origin, vmult(ray->direct, t));
	return (at);
}

t_ray	ray_primary(t_camera *cam, double u, double v)
{
	t_ray	ray;

	ray.origin = cam->origin;
	ray.direct = vunit(vminus_(
		vplus_(vplus_(cam->left_bottom, vmult(cam->horizontal, u)),
			vmult(cam->vertical, v)), cam->origin));
	return (ray);
}

t_hit_record	record_init(void)
{
	t_hit_record	record;

	record.tmin = EPSILON;
	record.tmax = INFINITY;
	return (record);
}

t_color3	ray_color(t_scene *scene)
{
	double			t;
	t_vec3			n;

	scene->rec = record_init();
	if (hit(scene->objects, &scene->ray, &scene->rec))
		return (phong_lighting(scene));
	else
	{
		t = 0.5 * (scene->ray.direct.y + 1.0);
		return (vplus_(vmult(color3(1, 1, 1), 1.0 - t),
				vmult(color3(0.5, 0.7, 1.0), t)));
	}
}

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

t_color3	ray_color(t_ray *ray, t_object objects[])
{
	double			t;
	t_vec3			n;
	t_hit_record	rec;

	rec.tmin = 0;
	rec.tmax = INFINITY;
	if (hit(objects, ray, &rec))
		return (vmult(vplus(rec.normal, 1, 1, 1), 0.5));
	else
	{
		t = 0.5 * (ray->direct.y + 1.0);
		return (vplus_(vmult(color3(1, 1, 1), 1.0 - t),
				vmult(color3(0.5, 0.7, 1.0), t)));
	}
}

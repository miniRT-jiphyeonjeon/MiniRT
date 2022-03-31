#include <math.h>
#include "structures.h"
#include "utils.h"
#include "trace.h"

static void	get_sphere_uv(t_vec3 normal, double *u, double *v)
{
	double	theta;
	double	phi;

	theta = acos(-1 * normal.y);
	phi = atan2(-1 * normal.z, normal.x) + M_PI;
	*u = phi * M_1_PI * 0.5;
	*v = theta * M_1_PI;
}

t_bool	hit_sphere(t_object objects[], t_ray *ray, t_hit_record *rec)
{
	t_vec3		oc;
	double		a;
	double		half_b;
	double		c;
	double		discriminant;
	double		sqrt_d;
	double		root;
	t_sphere	*sp;

	sp = (t_sphere *)objects->data;

	oc = vminus_(ray->origin, sp->center);
	a = vlength2(ray->direct);
	half_b = vdot(ray->direct, oc);
	c = vlength2(oc) - sp->radius2;
	discriminant = half_b * half_b - a * c;

	if (discriminant < 0)
		return (FALSE);
	sqrt_d = sqrt(discriminant);
	root = (half_b * (-1) - sqrt_d) / a;
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (half_b * (-1) + sqrt_d) / a;
		if (root < rec->tmin || rec->tmax < root)
			return (FALSE);
	}
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->normal = vunit(vminus_(rec->p, sp->center));
	get_sphere_uv(rec->normal, &rec->u, &rec->v);
	if (objects->checker.on == FALSE)
		rec->albedo = objects->albedo;
	else
		rec->albedo = checker_color(rec->u, rec->v, rec->p, objects->checker);
	set_face_normal(ray, rec);
	return (TRUE);
}

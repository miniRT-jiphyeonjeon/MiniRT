#include "structures.h"
#include "utils.h"
#include "trace.h"

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
	rec->albedo = objects->albedo;
	set_face_normal(ray, rec);
	return (TRUE);
}

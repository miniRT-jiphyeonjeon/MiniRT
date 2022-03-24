#include <math.h>
#include "trace.h"
#include "vector3.h"

t_bool	hit_sphere(t_obj_list objects[], t_ray *ray, t_hit_record *rec)
{
	t_vec3		oc;
	double		a;
	double		half_b;
	double		c;
	double		discriminant;
	double		sqrt_d;
	double		root;
	t_sphere	*sp;

	sp = (t_sphere *)objects->object;

	oc = vec3_minus(ray->origin, sp->center);
	a = vec3_length_square(ray->direction);
	half_b = vec3_dot(ray->direction, oc);
	c = vec3_length_square(oc) - sp->radius2;
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
	rec->normal = vec3_unit(vec3_minus(rec->p, sp->center));
	rec->color = objects->color;
	// set_face_normal(ray, rec);
	return (TRUE);
}

#include <math.h>
#include "trace_bonus.h"
#include "vector3_bonus.h"

static t_bool	check_sphere(
		t_obj_list objects[], t_ray *ray, t_hit_record *rec, double root)
{
	t_sphere	*sp;

	sp = (t_sphere *)objects->object;
	if (isnan(root) || root < rec->tmin || rec->tmax < root)
		return (FALSE);
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->normal = vec3_unit(vec3_minus(rec->p, sp->center));
	rec->color = objects->color;
	set_face_normal(ray, rec);
	return (TRUE);
}

static t_eq	sphere_equation(t_obj_list objects[], t_ray *ray)
{
	t_sphere	*sp;
	t_eq		eq;
	t_vec3		oc;

	sp = (t_sphere *)objects->object;
	oc = vec3_minus(ray->origin, sp->center);
	eq.a = vec3_length_square(ray->direction);
	eq.half_b = vec3_dot(ray->direction, oc);
	eq.c = vec3_length_square(oc) - sp->radius2;
	return (eq);
}

t_bool	hit_sphere(t_obj_list objects[], t_ray *ray, t_hit_record *rec)
{
	t_eq	eq;

	eq = sphere_equation(objects, ray);
	if (check_sphere(objects, ray, rec, root(eq, ALPHA)))
		return (TRUE);
	if (check_sphere(objects, ray, rec, root(eq, BETA)))
		return (TRUE);
	return (FALSE);
}

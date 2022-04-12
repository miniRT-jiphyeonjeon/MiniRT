#include <math.h>
#include "trace_bonus.h"
#include "vector3_bonus.h"
#include "event_bonus.h"

static void	sphere_uv(t_hit_record *rec)
{
	double	theta;
	double	phi;

	theta = acos(-1 * rec->normal.y);
	phi = atan2(-1 * rec->normal.z, rec->normal.x) + M_PI;
	rec->u = phi * M_1_PI * 0.5;
	rec->v = theta * M_1_PI;
	rec->u_dir = vec3_unit(vec3_cross(vec3_up(rec->normal), rec->normal));
	rec->v_dir = vec3_unit(vec3_cross(rec->normal, rec->u_dir));
}

static t_bool	sphere_check(
		t_obj_list objects[], t_ray *ray, t_hit_record *rec, double root)
{
	t_object	*sp;

	sp = (t_object *)objects->object;
	if (isnan(root) || root < rec->tmin || rec->tmax < root)
		return (FALSE);
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->normal = vec3_unit(vec3_minus(rec->p, sp->center));
	set_face_normal(ray, rec);
	sphere_uv(rec);
	if (is_checkerboard(objects->color))
		rec->color = checker_color(rec->u, rec->v, objects->color);
	else if (is_bumpmap(objects->color))
	{
		rec->color = image_mapping(rec->u, rec->v, objects->color.bumpmap->texture);
		// rec->normal = normal_mapping(rec, objects->color.bumpmap->bump);
	}
	else
		rec->color = objects->color.color;
	return (TRUE);
}

static t_eq	sphere_equation(t_obj_list objects[], t_ray *ray)
{
	t_object	*sp;
	t_eq		eq;
	t_vec3		oc;

	sp = (t_object *)objects->object;
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
	if (sphere_check(objects, ray, rec, root(eq, ALPHA)))
		return (TRUE);
	if (sphere_check(objects, ray, rec, root(eq, BETA)))
		return (TRUE);
	return (FALSE);
}

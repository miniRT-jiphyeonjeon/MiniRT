#include <math.h>
#include "trace_bonus.h"
#include "vector3_bonus.h"

static void	cylinder_uv(t_hit_record *rec, t_cylinder *cy, double *u, double *v)
{
	double	theta;
	double	height;
	t_vec3	u_dir;
	t_vec3	v_dir;
	t_vec3	pc;

	v_dir = vec3_cross(vec3(1, 0, 0), cy->normal);
	if (vec3_length_square(v_dir) == 0)
		v_dir = vec3_cross(vec3(0, 0, 1), cy->normal);
	v_dir = vec3_unit(v_dir);
	u_dir = vec3_unit(vec3_cross(v_dir, cy->normal));
	pc = vec3_minus(rec->p, cy->center);
	theta = atan2(-1 * vec3_dot(pc, v_dir), vec3_dot(pc, u_dir)) + M_PI;
	height = vec3_dot(pc, cy->normal);
	*u = theta * M_1_PI * 0.5;
	*v = fmod(height, 1);
}

static t_bool	check_cylinder(
	t_obj_list objects[], t_ray *ray, t_hit_record *rec, double root)
{
	t_cylinder	*cy;
	double		p_height;

	cy = (t_cylinder *)objects->object;
	if (isnan(root) || root < rec->tmin || rec->tmax < root)
		return (FALSE);
	rec->t = root;
	rec->p = ray_at(ray, root);
	p_height = vec3_dot(vec3_minus(rec->p, cy->center), cy->normal);
	if (p_height < 0 || p_height > cy->height)
		return (FALSE);
	rec->normal = vec3_unit(vec3_minus(rec->p, vec3_plus(cy->center,
					vec3_mult_scalar(cy->normal, vec3_dot(
							vec3_minus(rec->p, cy->center), cy->normal)))));
	cylinder_uv(rec, cy, &rec->u, &rec->v);
	if (is_checkerboard(objects->color))
		rec->color = checker_color(rec->u, rec->v, objects->color);
	else
		rec->color = objects->color.color;
	set_face_normal(ray, rec);
	return (TRUE);
}

static t_eq	cylinder_equation(t_obj_list objects[], t_ray *ray)
{
	t_cylinder	*cy;
	t_eq		eq;
	t_vec3		oc;

	cy = (t_cylinder *)objects->object;
	oc = vec3_minus(ray->origin, cy->center);
	eq.a = vec3_dot(ray->direction, ray->direction)
		- vec3_dot(ray->direction, cy->normal)
		* vec3_dot(ray->direction, cy->normal);
	eq.half_b = vec3_dot(ray->direction, oc)
		- vec3_dot(oc, cy->normal) * vec3_dot(ray->direction, cy->normal);
	eq.c = vec3_dot(oc, oc)
		- vec3_dot(oc, cy->normal) * vec3_dot(oc, cy->normal) - cy->radius2;
	return (eq);
}

t_bool	hit_cylinder(t_obj_list objects[], t_ray *ray, t_hit_record *rec)
{
	t_eq	eq;

	eq = cylinder_equation(objects, ray);
	if (check_cylinder(objects, ray, rec, root(eq, ALPHA)))
		return (TRUE);
	if (check_cylinder(objects, ray, rec, root(eq, BETA)))
		return (TRUE);
	return (FALSE);
}

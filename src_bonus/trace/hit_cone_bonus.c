#include <math.h>
#include "trace_bonus.h"
#include "vector3_bonus.h"
#include "libft.h"

static void	cone_uv(t_hit_record *rec, t_object *co)
{
	double	theta;
	double	height;
	t_vec3	pc;

	coordinate_system(&rec->u_dir, &rec->v_dir, co->normal);
	pc = vec3_minus(rec->p, co->center);
	theta
		= atan2(-1 * vec3_dot(pc, rec->v_dir), vec3_dot(pc, rec->u_dir)) + M_PI;
	height = vec3_dot(pc, co->normal);
	rec->u = theta * M_1_PI * 0.5;
	rec->v = ft_fmod_abs(fmod(height, 1), 1);
}

static t_bool	check_cone(
	t_obj_list objects[], t_ray *ray, t_hit_record *rec, double root)
{
	t_object	*co;
	double		p_height;

	co = (t_object *)objects->object;
	if (isnan(root) || root < rec->tmin || rec->tmax < root)
		return (FALSE);
	rec->t = root;
	rec->p = ray_at(ray, root);
	p_height = vec3_dot(vec3_minus(rec->p, co->center), co->normal);
	if (p_height < 0 || p_height > co->height)
		return (FALSE);
	rec->normal = vec3_unit(vec3_minus(rec->p, vec3_plus(co->center,
					vec3_mult_scalar(co->normal, vec3_dot(
							vec3_minus(rec->p, co->center), co->normal)))));
	set_face_normal(ray, rec);
	cone_uv(rec, co);
	hit_color_set(rec, objects);
	return (TRUE);
}

static t_eq	cone_equation(t_obj_list objects[], t_ray *ray)
{
	t_object	*co;
	t_eq		eq;
	t_vec3		oc;
	double		h_ratio;

	co = (t_object *)objects->object;
	h_ratio = co->radius2 / (co->height * co->height);
	oc = vec3_minus(ray->origin, co->center);
	eq.a = vec3_dot(ray->direction, ray->direction)
		- vec3_dot(ray->direction, co->normal)
		* vec3_dot(ray->direction, co->normal) * (1 + h_ratio);
	eq.half_b = vec3_dot(ray->direction, oc)
		- vec3_dot(oc, co->normal) * vec3_dot(ray->direction, co->normal)
		* (1 + h_ratio) + h_ratio * co->height
		* vec3_dot(ray->direction, co->normal);
	eq.c = vec3_dot(oc, oc)
		- vec3_dot(oc, co->normal) * vec3_dot(oc, co->normal)
		* (1 + h_ratio) - co->radius2 + 2 * h_ratio * co->height
		* vec3_dot(oc, co->normal);
	return (eq);
}

t_bool	hit_cone(t_obj_list objects[], t_ray *ray, t_hit_record *rec)
{
	t_eq	eq;

	eq = cone_equation(objects, ray);
	if (check_cone(objects, ray, rec, root(eq, ALPHA)))
		return (TRUE);
	if (check_cone(objects, ray, rec, root(eq, BETA)))
		return (TRUE);
	return (FALSE);
}

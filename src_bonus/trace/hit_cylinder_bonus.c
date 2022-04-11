#include <math.h>
#include "trace_bonus.h"
#include "vector3_bonus.h"
#include "libft.h"

static void	cylinder_uv(t_hit_record *rec, t_object *cy)
{
	double	theta;
	double	height;
	t_vec3	pc;

	rec->u_dir = vec3_unit(vec3_cross(vec3_up(cy->normal), cy->normal));
	rec->v_dir = vec3_unit(vec3_cross(cy->normal, rec->u_dir));
	pc = vec3_minus(rec->p, cy->center);
	theta = atan2(-1 * vec3_dot(pc, rec->v_dir), vec3_dot(pc, rec->u_dir)) + M_PI;
	height = vec3_dot(pc, cy->normal);
	rec->u = theta * M_1_PI * 0.5;
	rec->v = ft_fmod_abs(fmod(height, 1), 1);
}

static t_bool	check_cylinder(
	t_obj_list objects[], t_ray *ray, t_hit_record *rec, double root)
{
	t_object	*cy;
	double		p_height;

	cy = (t_object *)objects->object;
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
	cylinder_uv(rec, cy);
	if (is_checkerboard(objects->color))
		rec->color = checker_color(rec->u, rec->v, objects->color);
	else if (is_bumpmap(objects->color))
	{
		rec->color = image_mapping(rec->u, rec->v, objects->color.bumpmap->texture);
		// rec->normal = normal_mapping(rec, objects->color.bumpmap->bump);
	}
	else
		rec->color = objects->color.color;
	set_face_normal(ray, rec);
	return (TRUE);
}

static t_eq	cylinder_equation(t_obj_list objects[], t_ray *ray)
{
	t_object	*cy;
	t_eq		eq;
	t_vec3		oc;

	cy = (t_object *)objects->object;
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

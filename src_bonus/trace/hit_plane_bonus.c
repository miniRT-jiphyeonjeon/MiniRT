#include <math.h>
#include "trace_bonus.h"
#include "vector3_bonus.h"

static double	mod_abs(double x)
{
	if (x < 0)
		return (x + 1);
	return (x);
}

static void	plane_uv(t_hit_record *rec)
{
	rec->v_dir = vec3_cross(rec->normal, vec3(1, 0, 0));
	if (vec3_length_square(rec->v_dir) == 0)
		rec->v_dir = vec3_cross(rec->normal, vec3(0, 0, 1));
	rec->v_dir = vec3_unit(rec->v_dir);
	rec->u_dir = vec3_unit(vec3_cross(rec->v_dir, rec->normal));
	rec->u = mod_abs(fmod(vec3_dot(rec->p, rec->u_dir), 1));
	rec->v = mod_abs(fmod(vec3_dot(rec->p, rec->v_dir), 1));
}

t_bool	hit_plane(t_obj_list objects[], t_ray *ray, t_hit_record *rec)
{
	double		numerator;
	double		denominator;
	double		root;
	t_object	*pl;

	pl = (t_object *)objects->object;
	denominator = vec3_dot(ray->direction, pl->normal);
	if (denominator == 0)
		return (FALSE);
	numerator = -1 * vec3_dot(vec3_minus(ray->origin, pl->center), pl->normal);
	root = numerator / denominator;
	if (root < rec->tmin || rec->tmax < root)
		return (FALSE);
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->normal = pl->normal;
	plane_uv(rec);
	if (is_checkerboard(objects->color))
		rec->color = checker_color(rec->u, rec->v, objects->color);
	else if (is_bumpmap(objects->color))
	{
		rec->color = image_mapping(rec->u, rec->v, objects->color.bumpmap->texture);
		rec->normal = normal_mapping(rec, objects->color.bumpmap->bump);
	}
	else
		rec->color = objects->color.color;
	
	set_face_normal(ray, rec);
	return (TRUE);
}

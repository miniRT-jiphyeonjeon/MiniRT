#include <math.h>
#include "trace_bonus.h"
#include "vector3_bonus.h"
#include "libft.h"

static void	plane_uv(t_hit_record *rec)
{
	rec->u_dir = vec3_unit(vec3_cross(vec3_up(rec->normal), rec->normal));
	rec->v_dir = vec3_unit(vec3_cross(rec->normal, rec->u_dir));
	rec->u = ft_fmod_abs(fmod(vec3_dot(rec->p, rec->u_dir), 1), 1);
	rec->v = ft_fmod_abs(fmod(vec3_dot(rec->p, rec->v_dir), 1), 1);
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

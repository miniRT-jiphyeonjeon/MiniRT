#include <math.h>
#include "trace_bonus.h"
#include "vector3_bonus.h"

static void	plane_uv(t_point3 p, t_vec3 normal, double *u, double *v)
{
	t_vec3	u_dir;
	t_vec3	v_dir;

	v_dir = vec3_cross(normal, vec3(1, 0, 0));
	if (vec3_length_square(v_dir) == 0)
		v_dir = vec3_cross(normal, vec3(0, 0, 1));
	v_dir = vec3_unit(v_dir);
	u_dir = vec3_unit(vec3_cross(v_dir, normal));
	*u = fmod(vec3_dot(p, u_dir), 1);
	*v = fmod(vec3_dot(p, v_dir), 1);
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
	plane_uv(rec->p, rec->normal, &rec->u, &rec->v);
	if (is_checkerboard(objects->color))
		rec->color = checker_color(rec->u, rec->v, objects->color);
	else
		rec->color = objects->color.color;
	set_face_normal(ray, rec);
	return (TRUE);
}

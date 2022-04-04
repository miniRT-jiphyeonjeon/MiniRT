#include <math.h>
#include "structures.h"
#include "utils.h"
#include "trace.h"

static void	get_plane_uv(t_point3 p, t_vec3 normal, double *u, double *v)
{
	t_vec3	u_dir;
	t_vec3	v_dir;

	v_dir = vcross(normal, vec3(1, 0, 0));
	if (vlength2(v_dir) == 0)
		v_dir = vcross(normal, vec3(0, 0, 1));
	v_dir = vunit(v_dir);
	u_dir = vunit(vcross(v_dir, normal));
	*u = fmod(vdot(p, u_dir), 1);
	*v = fmod(vdot(p, v_dir), 1);
}

t_bool	hit_plane(t_object objects[], t_ray *ray, t_hit_record *rec)
{
	double	numerator;
	double	denominator;
	double	root;
	t_plane	*pl;

	pl = (t_plane *)objects->data;
	
	numerator = -1 * vdot(vminus_(ray->origin, pl->point), pl->normal);
	denominator = vdot(ray->direct, pl->normal);
	root = numerator / denominator;
	if (root < rec->tmin || rec->tmax < root)
		return (FALSE);
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->normal = pl->normal;
	get_plane_uv(rec->p, rec->normal, &rec->u, &rec->v);
	if (objects->checker.on == FALSE)
		rec->albedo = objects->albedo;
	else
		rec->albedo = checker_color(rec->u, rec->v, rec->p, objects->checker);
	set_face_normal(ray, rec);
	return (TRUE);
}

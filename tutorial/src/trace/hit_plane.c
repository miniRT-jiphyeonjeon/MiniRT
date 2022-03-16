#include "structures.h"
#include "utils.h"
#include "trace.h"

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
	rec->albedo = objects->albedo;
	return (TRUE);
}

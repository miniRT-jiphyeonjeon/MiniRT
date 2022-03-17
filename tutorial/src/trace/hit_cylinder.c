#include "structures.h"
#include "utils.h"
#include "trace.h"

t_bool	hit_cylinder(t_object objects[], t_ray *ray, t_hit_record *rec)
{
	t_cylinder	*cy;
	double		oc_x;
	double		oc_z;
	double		a;
	double		half_b;
	double		c;
	double		discriminant;
	double		sqrt_d;
	double		root;

	cy = (t_cylinder *)objects->data;

	oc_x = ray->origin.x - cy->center.x;
	oc_z = ray->origin.z - cy->center.z;
	a = ray->direct.x * ray->direct.x + ray->direct.z * ray->direct.z;
	half_b = ray->direct.x * oc_x + ray->direct.z * oc_z;
	c = oc_x * oc_x + oc_z * oc_z - cy->radius2;
	discriminant = half_b * half_b - a * c;

	if (discriminant < 0)
		return (FALSE);
	sqrt_d = sqrt(discriminant);
	root = (half_b * (-1) - sqrt_d) / a;
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (half_b * (-1) + sqrt_d) / a;
		if (root < rec->tmin || rec->tmax < root)
			return (FALSE);
	}
	rec->t = root;
	rec->p = ray_at(ray, root);
	// if ((rec->p.y < (cy->center.y - cy->height / 2)) || (rec->p.y > (cy->center.y + cy->height / 2)))
	// 	return (FALSE);
	// if ((rec->p.y == (cy->center.y - cy->height / 2)) || (rec->p.y == (cy->center.y + cy->height / 2)))
	// {
	// 	// 이 경우는 새로운 해를 구해야한다.
	// 	if (rec->p.x * rec->p.x + rec->p.z * rec->p.z > 1)
	// 		return (FALSE);
	// }
	rec->normal = vunit(vec3(rec->p.x - cy->center.x, 0, rec->p.z - cy->center.z));
	rec->albedo = objects->albedo;
	set_face_normal(ray, rec);
	return (TRUE);
}

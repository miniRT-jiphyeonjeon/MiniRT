#include "structures.h"
#include "utils.h"
#include "trace.h"

typedef struct s_eq
{
	double	a;
	double	half_b;
	double	c;
}	t_eq;

static double	get_root(t_eq eq,int type)
{
	double	discriminant;
	double	sqrt_d;
	double	root;

	discriminant = eq.half_b * eq.half_b - eq.a * eq.c;
	sqrt_d = sqrt(discriminant);
	if (type == 0)
		root = (eq.half_b * (-1) - sqrt_d) / eq.a;
	if (type == 1)
		root = (eq.half_b * (-1) + sqrt_d) / eq.a;
	return (root);
}

static t_eq	get_equation(t_object objects[], t_ray *ray)
{
	t_cylinder	*cy;
	t_eq		eq;
	t_vec3		oc;

	cy = (t_cylinder *)objects->data;

	oc = vminus_(ray->origin, cy->center);
	eq.a = vdot(ray->direct, ray->direct) - vdot(ray->direct, cy->normal) * vdot(ray->direct, cy->normal);
	eq.half_b = vdot(ray->direct, oc) - vdot(oc, cy->normal) * vdot(ray->direct, cy->normal);
	eq.c = vdot(oc, oc) - vdot(oc, cy->normal) * vdot(oc, cy->normal) - cy->radius2;
	return (eq);
}

t_bool	check_cylinder(t_object objects[], t_ray *ray, t_hit_record *rec, double root)
{
	t_cylinder	*cy;
	double		p_height;

	cy = (t_cylinder *)objects->data;

	if (root < rec->tmin || rec->tmax < root)
		return (FALSE);
	rec->t = root;
	rec->p = ray_at(ray, root);
	p_height = vdot(vminus_(rec->p, cy->center), cy->normal);
	if (p_height < 0 || p_height > cy->height)
		return (FALSE);
	rec->normal = vunit(vminus_(rec->p, vplus_(cy->center, vmult(cy->normal, 
					vdot(vminus_(rec->p, cy->center), cy->normal)))));
	rec->albedo = objects->albedo;
	// set_face_normal(ray, rec);
	return (TRUE);
}

t_bool	hit_cylinder(t_object objects[], t_ray *ray, t_hit_record *rec)
{
	t_cylinder	*cy;
	t_vec3		oc;
	t_eq		eq;
	double		discriminant;

	cy = (t_cylinder *)objects->data;

	eq = get_equation(objects, ray);
	discriminant = eq.half_b * eq.half_b - eq.a * eq.c;
	if (discriminant < 0)
		return (FALSE);
	if (check_cylinder(objects, ray, rec, get_root(eq, 0)))
		return (TRUE);
	if (check_cylinder(objects, ray, rec, get_root(eq, 1)))
		return (TRUE);
	return (FALSE);
}

// t_bool	hit_cylinder(t_object objects[], t_ray *ray, t_hit_record *rec)
// {
// 	t_cylinder	*cy;
// 	double		oc_x;
// 	double		oc_z;
// 	double		a;
// 	double		half_b;
// 	double		c;
// 	double		discriminant;
// 	double		sqrt_d;
// 	double		root;

// 	cy = (t_cylinder *)objects->data;

// 	oc_x = ray->origin.x - cy->center.x;
// 	oc_z = ray->origin.z - cy->center.z;
// 	a = ray->direct.x * ray->direct.x + ray->direct.z * ray->direct.z;
// 	half_b = ray->direct.x * oc_x + ray->direct.z * oc_z;
// 	c = oc_x * oc_x + oc_z * oc_z - cy->radius2;
// 	discriminant = half_b * half_b - a * c;

// 	if (discriminant < 0)
// 		return (FALSE);
// 	sqrt_d = sqrt(discriminant);
// 	root = (half_b * (-1) - sqrt_d) / a;
// 	if (root < rec->tmin || rec->tmax < root)
// 	{
// 		root = (half_b * (-1) + sqrt_d) / a;
// 		if (root < rec->tmin || rec->tmax < root)
// 			return (FALSE);
// 	}
// 	rec->t = root;
// 	rec->p = ray_at(ray, root);
// 	rec->normal = vunit(vec3(rec->p.x - cy->center.x, 0, rec->p.z - cy->center.z));
// 	rec->albedo = objects->albedo;
// 	set_face_normal(ray, rec);
// 	return (TRUE);
// }

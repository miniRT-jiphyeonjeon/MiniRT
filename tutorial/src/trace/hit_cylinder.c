#include <math.h>
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

static void get_cylinder_uv(t_hit_record *rec, t_cylinder *cy, double *u, double *v)
{
	double	theta;
	double	height;
	t_vec3	u_dir;
	t_vec3	v_dir;
	t_vec3	pc;

	v_dir = vcross(vec3(1, 0, 0), cy->normal);
	if (vlength2(v_dir) == 0)
		v_dir = vcross(vec3(0, 0, 1), cy->normal);
	v_dir = vunit(v_dir);
	u_dir = vunit(vcross(v_dir, cy->normal));
	pc = vminus_(rec->p, cy->center);

	theta = atan2(-1 * vdot(pc, v_dir), vdot(pc, u_dir)) + M_PI;
	// height = sqrt(vlength2(pc) - cy->radius2);
	height = vdot(pc, cy->normal);
	*u = theta * M_1_PI * 0.5;
	*v = fmod(height, 1);
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
	get_cylinder_uv(rec, cy, &rec->u, &rec->v);
	if (objects->checker.on == FALSE)
		rec->albedo = objects->albedo;
	else
		rec->albedo = checker_color(rec->u, rec->v, rec->p, objects->checker);
	set_face_normal(ray, rec);
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

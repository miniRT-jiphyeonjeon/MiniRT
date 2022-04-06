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
	t_cone	*cn;
	t_eq		eq;
	t_vec3		oc;
	double		h_ratio;

	cn = (t_cone *)objects->data;
	
	h_ratio = cn->radius2 / (cn->height * cn->height);

	oc = vminus_(ray->origin, cn->center);
	eq.a = vdot(ray->direct, ray->direct) - vdot(ray->direct, cn->normal) * vdot(ray->direct, cn->normal) * (1 + h_ratio);
	eq.half_b = vdot(ray->direct, oc) - vdot(oc, cn->normal) * vdot(ray->direct, cn->normal) * (1 + h_ratio) + h_ratio * cn->height * vdot(ray->direct, cn->normal);
	eq.c = vdot(oc, oc) - vdot(oc, cn->normal) * vdot(oc, cn->normal) * (1 + h_ratio) - cn->radius2 + 2 * h_ratio * cn->height * vdot(oc, cn->normal);
	return (eq);
}

static void	get_cone_uv(t_hit_record *rec, t_cone *cn, double *u, double *v)
{
	double	theta;
	double	height;
	t_vec3	u_dir;
	t_vec3	v_dir;
	t_vec3	pc;

	v_dir = vcross(vec3(1, 0, 0), cn->normal);
	if (vlength2(v_dir) == 0)
		v_dir = vcross(vec3(0, 0, 1), cn->normal);
	v_dir = vunit(v_dir);
	u_dir = vunit(vcross(v_dir, cn->normal));
	pc = vminus_(rec->p, cn->center);

	theta = atan2(-1 * vdot(pc, v_dir), vdot(pc, u_dir)) + M_PI;
	height = vdot(pc, cn->normal);
	*u = theta * M_1_PI * 0.5;
	*v = fmod(height, 1);
}

static t_bool	check_cone(t_object objects[], t_ray *ray, t_hit_record *rec, double root)
{
	t_cone	*cn;
	double	p_height;

	cn = (t_cone *)objects->data;

	if (root < rec->tmin || rec->tmax < root)
		return (FALSE);
	rec->t = root;
	rec->p = ray_at(ray, root);
	p_height = vdot(vminus_(rec->p, cn->center), cn->normal);
	if (p_height < 0 || p_height > cn->height)
		return (FALSE);
	rec->normal = vunit(vminus_(rec->p, vplus_(cn->center, vmult(cn->normal, 
					vdot(vminus_(rec->p, cn->center), cn->normal)))));
	get_cone_uv(rec, cn, &rec->u, &rec->v);
	if (objects->checker.on == FALSE)
		rec->albedo = objects->albedo;
	else
		rec->albedo = checker_color(rec->u, rec->v, rec->p, objects->checker);
	set_face_normal(ray, rec);
	return (TRUE);
}

t_bool	hit_cone(t_object objects[], t_ray *ray, t_hit_record *rec)
{
	t_cone	*cn;
	t_vec3		oc;
	t_eq		eq;
	double		discriminant;

	cn = (t_cone *)objects->data;

	eq = get_equation(objects, ray);
	discriminant = eq.half_b * eq.half_b - eq.a * eq.c;
	if (discriminant < 0)
		return (FALSE);
	if (check_cone(objects, ray, rec, get_root(eq, 0)))
		return (TRUE);
	if (check_cone(objects, ray, rec, get_root(eq, 1)))
		return (TRUE);
	return (FALSE);
}

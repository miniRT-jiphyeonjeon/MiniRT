#include <math.h>
#include "trace_bonus.h"
#include "vector3_bonus.h"
#include "event_bonus.h"

static int	rgb_extract(int mlx_color, t_color_mask type)
{
	return ((mlx_color >> type) & 0xFF);
}

static t_color3	pixel_to_color3(int mlx_color)
{
	double	r;
	double	g;
	double	b;

	r = (double)rgb_extract(mlx_color, RED) / 256;
	g = (double)rgb_extract(mlx_color, GREEN) / 256;
	b = (double)rgb_extract(mlx_color, BLUE) / 256;
	return (color3(r, g, b));
}

static t_color3	image_mapping(double u, double v, t_xpm_image img)
{
	int		u_int;
	int		v_int;
	int		mlx_color;

	u_int = (int)(u * img.width);
	v_int = (int)((1.0 - v) * img.height);
	mlx_color = xpm_pixel_get(&img, u_int, v_int);
	return (pixel_to_color3(mlx_color));
}

static void	sphere_uv(t_vec3 normal, double *u, double *v)
{
	double	theta;
	double	phi;

	theta = acos(-1 * normal.y);
	phi = atan2(-1 * normal.z, normal.x) + M_PI;
	*u = phi * M_1_PI * 0.5;
	*v = theta * M_1_PI;
}

static t_bool	sphere_check(
		t_obj_list objects[], t_ray *ray, t_hit_record *rec, double root)
{
	t_object	*sp;

	sp = (t_object *)objects->object;
	if (isnan(root) || root < rec->tmin || rec->tmax < root)
		return (FALSE);
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->normal = vec3_unit(vec3_minus(rec->p, sp->center));
	sphere_uv(rec->normal, &rec->u, &rec->v);
	if (is_checkerboard(objects->color))
		rec->color = checker_color(rec->u, rec->v, objects->color);
	else
		rec->color = image_mapping(rec->u, rec->v, rec->texture);
		// rec->color = objects->color.color;
	set_face_normal(ray, rec);
	return (TRUE);
}

static t_eq	sphere_equation(t_obj_list objects[], t_ray *ray)
{
	t_object	*sp;
	t_eq		eq;
	t_vec3		oc;

	sp = (t_object *)objects->object;
	oc = vec3_minus(ray->origin, sp->center);
	eq.a = vec3_length_square(ray->direction);
	eq.half_b = vec3_dot(ray->direction, oc);
	eq.c = vec3_length_square(oc) - sp->radius2;
	return (eq);
}

t_bool	hit_sphere(t_obj_list objects[], t_ray *ray, t_hit_record *rec)
{
	t_eq	eq;

	eq = sphere_equation(objects, ray);
	if (sphere_check(objects, ray, rec, root(eq, ALPHA)))
		return (TRUE);
	if (sphere_check(objects, ray, rec, root(eq, BETA)))
		return (TRUE);
	return (FALSE);
}

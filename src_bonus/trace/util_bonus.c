#include <math.h>
#include "trace_bonus.h"
#include "vector3_bonus.h"

double	root(t_eq eq, t_root_type type)
{
	double	discriminant;
	double	sqrt_d;

	discriminant = eq.half_b * eq.half_b - eq.a * eq.c;
	if (discriminant < 0)
		return (NAN);
	sqrt_d = sqrt(discriminant);
	if (type == ALPHA)
		return ((eq.half_b * (-1) - sqrt_d) / eq.a);
	if (type == BETA)
		return ((eq.half_b * (-1) + sqrt_d) / eq.a);
	return (NAN);
}

void	set_face_normal(t_ray *ray, t_hit_record *rec)
{
	rec->front_face = vec3_dot(ray->direction, rec->normal) < 0;
	if (!rec->front_face)
		rec->normal = vec3_mult_scalar(rec->normal, -1);
}

t_bool	is_checkerboard(t_color_info texture)
{
	if (!texture.checkboard)
		return (FALSE);
	return (TRUE);
}

t_color3	checker_color(double u, double v, t_color_info color)
{
	int	u_int;
	int	v_int;

	u_int = floor(u * color.checkboard->width);
	v_int = floor(v * color.checkboard->height);
	if ((u_int + v_int) % 2)
		return (color.color);
	else
		return (color.checkboard->check_color);
}

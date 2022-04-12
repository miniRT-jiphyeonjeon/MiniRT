#include "vector3_bonus.h"

t_vec3	vec3(double x, double y, double z)
{
	t_vec3	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_point3	point3(double x, double y, double z)
{
	t_point3	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

t_color3	color3(double r, double g, double b)
{
	t_color3	color;

	color.x = r;
	color.y = g;
	color.z = b;
	return (color);
}

void	vec3_set(t_vec3 *vec, double x, double y, double z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

void	coordinate_system(t_vec3 *u, t_vec3 *v, t_vec3 w)
{
	*u = vec3_unit(vec3_cross(vec3_up(w), w));
	*v = vec3_unit(vec3_cross(w, *u));
}

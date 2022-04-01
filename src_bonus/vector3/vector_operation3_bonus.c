#include <math.h>
#include "vector3_bonus.h"

double	vec3_length_square(t_vec3 vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

double	vec3_length(t_vec3 vec)
{
	return (sqrt(vec3_length_square(vec)));
}

t_vec3	vec3_unit(t_vec3 vec)
{
	return (vec3_divide_scalar(vec, vec3_length(vec)));
}

//	Minimum value for each vectors
t_vec3	vec3_min(t_vec3 vec1, t_vec3 vec2)
{
	if (vec1.x > vec2.x)
		vec1.x = vec2.x;
	if (vec1.y > vec2.y)
		vec1.y = vec2.y;
	if (vec1.z > vec2.z)
		vec1.z = vec2.z;
	return (vec1);
}

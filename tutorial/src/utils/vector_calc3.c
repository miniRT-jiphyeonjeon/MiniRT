#include "utils.h"

double		vlength2(t_vec3 vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

double		vlength(t_vec3 vec)
{
	return (sqrt(vlength2(vec)));
}

t_vec3		vunit(t_vec3 vec)
{
	return (vdivide(vec, vlength(vec)));
}

//	축별로 min 값 반환
t_vec3		vmin(t_vec3 vec, t_vec3 vec2)
{
	if (vec.x > vec2.x)
		vec.x = vec2.x;
	if (vec.y > vec2.y)
		vec.y = vec2.y;
	if (vec.z > vec2.z)
		vec.z = vec2.z;
	return (vec);
}

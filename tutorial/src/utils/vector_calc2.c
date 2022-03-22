#include "utils.h"

t_vec3		vmult(t_vec3 vec, double t)
{
	vec.x *= t;
	vec.y *= t;
	vec.z *= t;
	return (vec);
}

t_vec3		vmult_(t_vec3 vec, t_vec3 vec2)
{
	vec.x *= vec2.x;
	vec.y *= vec2.y;
	vec.z *= vec2.z;
	return (vec);
}

t_vec3		vdivide(t_vec3 vec, double t)
{
	if (!t)
	{
		printf("Error\n:Devider is 0");
		exit(1);
	}
	return (vmult(vec, 1 / t));
}

/*	vector inner product
	A・B = |A||B|cos⍬
*/
double		vdot(t_vec3 vec, t_vec3 vec2)
{
	return (vec.x * vec2.x + vec.y * vec2.y + vec.z * vec2.z);
}

/*	vecotr outer product
	A✕B = \vec{n}|A||B|sin⍬
*/
t_vec3		vcross(t_vec3 vec, t_vec3 vec2)
{
	t_vec3	new;

	new.x = vec.y * vec2.z - vec.z * vec2.y;
	new.y = vec.z * vec2.x - vec.x * vec2.z;
	new.z = vec.x * vec2.y - vec.y * vec2.x;
	return (new);
}

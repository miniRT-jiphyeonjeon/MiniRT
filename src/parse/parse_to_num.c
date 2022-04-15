#include "parse.h"
#include "libft.h"
#include "vector3.h"
#include "error.h"
#include <math.h>
#include <stdlib.h>

double	double_get(char *s, double min, double max)
{
	double	d;
	t_res	res;

	d = ft_atof(s, &res);
	if (res != CLEAN)
		error_user("Elements must came in standard.\n");
	if (min == 0 && max == 0)
		return (d);
	else if (min == 0 && max == INFINITY && d < 0)
		error_user("The properties of the shape must be positive.\n");
	else if (min == 0 && max == 180 && d >= 180)
		error_user("FOV range should be under 180.\n");
	else if (min == 0 && max == 180 && d < 0)
		error_user("FOV range should be over 0.\n");
	if (d < min || d > max)
		error_user("Elements must came in standard range.\n");
	return (d);
}

struct s_vec3	vec_get(char *s, double min, double max)
{
	struct s_vec3	vec;
	char			*s_tmp;
	char			*s_tmp_ptr;

	s_tmp = ft_strdup(s);
	s_tmp_ptr = s_tmp;
	vec.x = double_get(ft_strsep(&s_tmp, ','), min, max);
	vec.y = double_get(ft_strsep(&s_tmp, ','), min, max);
	vec.z = double_get(ft_strsep(&s_tmp, ','), min, max);
	if (ft_strsep(&s_tmp, ',') != NULL)
		error_user("[x,y,z] elements must came in standard.\n");
	if (min == -1 && max == 1)
	{
		if (vec3_length(vec) == 0.0)
			error_user("Normalized vector must came in standard.\n");
		vec = vec3_unit(vec);
	}
	else if (min == 0 && max == 255)
		vec = vec3_divide_scalar(vec, 255);
	free(s_tmp_ptr);
	return (vec);
}

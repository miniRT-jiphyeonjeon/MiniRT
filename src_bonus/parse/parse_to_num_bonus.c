#include "parse_bonus.h"
#include "libft.h"
#include "vector3_bonus.h"
#include "error_bonus.h"
#include <math.h>

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
	if (d < min || d > max)
		error_user("Elements must came in standard.\n");
	return (d);
}

struct s_vec3	vec_get(char *s, double min, double max)
{
	struct s_vec3	vec;
	char			**str_splited;
	int				i;

	i = 0;
	str_splited = ft_split(s, ",");
	if (str_splited == NULL)
		error_user("color_get - dynamic allocation problem.\n");
	while (str_splited[i] != NULL)
		i++;
	if (i != 3)
		error_user("Elements must came in standard.\n");
	vec.x = double_get(str_splited[0], min, max);
	vec.y = double_get(str_splited[1], min, max);
	vec.z = double_get(str_splited[2], min, max);
	if (min == -1 && max == 1)
	{
		if (vec3_length(vec) == 0.0)
			error_user("Elements must came in standard.\n");
		vec = vec3_unit(vec);
	}
	else if (min == 0 && max == 255)
		vec = vec3_divide_scalar(vec, 255);
	del_split(str_splited);
	return (vec);
}

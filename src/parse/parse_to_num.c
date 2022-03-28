#include "parse.h"
#include "libft.h"
#include "vector3.h"
#include "error.h"

//printf 주석 존재
double	double_get(char *s, double min, double max)
{
	double	d;
	t_res	res;

	d = ft_atof(s, &res);
	// printf("%f, %d\n", d, res);
	if (res != CLEAN)
		error_user("Elements must came in standard.\n");
	if (min == 0 && max == 0)
		return (d);
	if (d < min || d > max)
		error_user("Elements must came in standard.\n");
	return (d);
}

// split->3개의 값을 struct s_vec3로 리턴
// 인자값 범위 지정
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
#include "libft.h"
#include "parse_bonus.h"
#include <stdlib.h>

t_obj_type	element_type_get(char *s)
{
	if (!ft_strcmp(s, "A"))
		return (AMBIENT);
	else if (!ft_strcmp(s, "C"))
		return (CAMERA);
	else if (!ft_strcmp(s, "L"))
		return (POINT_LIGHT);
	else if (!ft_strcmp(s, "sp"))
		return (SPHERE);
	else if (!ft_strcmp(s, "pl"))
		return (PLANE);
	else if (!ft_strcmp(s, "cy"))
		return (CYLINDER);
	else if (!ft_strcmp(s, "co"))
		return (CONE);
	return (NOTTYPE);
}

static t_color_type	obj_info_get(char **str, int len, int idx)
{
	if (len <= idx)
		return (ERROR_LESS);
	if (ft_strcmp(str[idx], "rgb") == 0)
	{
		if (len - idx == 5)
			return (COLOR);
		idx += 5;
	}
	else if (ft_strcmp(str[idx], "ck") == 0)
	{
		if (len - idx == 8)
			return (CHECKBOARD);
		idx += 8;
	}
	else if (ft_strcmp(str[idx], "bm") == 0)
	{
		if (len - idx == 5 || len - idx == 6)
			return (BUMPMAP);
		idx += 5;
	}
	else
		return (NOTCOLOR);
	if (len < idx)
		return (ERROR_LESS);
	return (ERROR_MORE);
}

t_color_type	color_obj_valid_get(t_obj_type id, char **str, int idx)
{
	int		i;

	i = 0;
	while (str[i] != NULL)
		++i;
	if (id == AMBIENT || id == POINT_LIGHT)
	{
		++idx;
		if (i < idx)
			return (ERROR_LESS);
		else if (i > idx)
			return (ERROR_MORE);
		return (COLOR);
	}
	else if (id == SPHERE || id == PLANE || id == CYLINDER || id == CONE)
		return (obj_info_get(str, i, idx));
	return (COLOR);
}

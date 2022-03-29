#include "libft.h"
#include "structure.h"

t_bool	is_objnum_valid(t_obj_list *lst)
{
	int		ambient_num;
	int		light_num;
	int		camera_num;
	t_parse	*parse;

	ambient_num = 0;
	light_num = 0;
	camera_num = 0;
	while (lst)
	{
		parse = lst->object;
		if (!ft_strcmp(parse->ident, "A"))
			++ambient_num;
		else if (!ft_strcmp(parse->ident, "L"))
			++light_num;
		else if (!ft_strcmp(parse->ident, "C"))
			++camera_num;
		lst = lst->next;
	}
	if (ambient_num == 1 && light_num == 1 && camera_num == 1)
		return (TRUE);
	return (FALSE);
}

t_bool	is_object(char *s)
{
	if (ft_strcmp(s, "A") && ft_strcmp(s, "C") && ft_strcmp(s, "L") \
	&& ft_strcmp(s, "sp") && ft_strcmp(s, "pl") && ft_strcmp(s, "cy"))
		return (FALSE);
	return (TRUE);
}

t_bool	is_element_valid(char **str, int idx)
{
	int		i;

	i = 0;
	while (str[i] != NULL)
		++i;
	if (i != idx)
		return (FALSE);
	return (TRUE);
}

t_bool	is_type_valid(char *id, char *type)
{
	if (!ft_strcmp(type, "point") && \
	(!ft_strcmp(id, "C") || !ft_strcmp(id, "L") || !ft_strcmp(id, "sp") || \
	!ft_strcmp(id, "pl") || !ft_strcmp(id, "cy")))
		return (TRUE);
	else if (!ft_strcmp(type, "bri_ratio") && \
	(!ft_strcmp(id, "A") || !ft_strcmp(id, "L")))
		return (TRUE);
	else if (!ft_strcmp(type, "nor_vec") && \
	(!ft_strcmp(id, "C") || !ft_strcmp(id, "pl") || !ft_strcmp(id, "cy")))
		return (TRUE);
	else if (!ft_strcmp(type, "diameter") && \
	(!ft_strcmp(id, "sp") || !ft_strcmp(id, "cy")))
		return (TRUE);
	else if (!ft_strcmp(type, "height") && \
	(!ft_strcmp(id, "cy")))
		return (TRUE);
	else if (!ft_strcmp(type, "fov") && \
	(!ft_strcmp(id, "C")))
		return (TRUE);
	else if (!ft_strcmp(type, "rgb") && \
	(!ft_strcmp(id, "A") || !(ft_strcmp(id, "L")) || !ft_strcmp(id, "sp") || \
	!ft_strcmp(id, "pl") || !ft_strcmp(id, "cy")))
		return (TRUE);
	return (FALSE);
}

#include "libft.h"
#include "structure_bonus.h"

t_bool	is_scene_env_valid(t_parse_list *lst)
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
	if (ambient_num == 1 && light_num >= 1 && camera_num == 1)
		return (TRUE);
	return (FALSE);
}

t_bool	is_info_valid(t_obj_type id, t_info info)
{
	if (info == POINT && \
	(id == CAMERA || id == POINT_LIGHT || id == SPHERE || id == PLANE || \
	id == CYLINDER || id == CONE))
		return (TRUE);
	else if (info == BRI_RATIO && (id == AMBIENT || id == POINT_LIGHT))
		return (TRUE);
	else if (info == NOR_VEC && \
	(id == CAMERA || id == PLANE || id == CYLINDER || id == CONE))
		return (TRUE);
	else if (info == DIAMETER && (id == SPHERE || id == CYLINDER || id == CONE))
		return (TRUE);
	else if (info == HEIGHT && (id == CYLINDER || id == CONE))
		return (TRUE);
	else if (info == FOV && (id == CAMERA))
		return (TRUE);
	else if (info == RGB && \
	(id == AMBIENT || id == POINT_LIGHT || id == SPHERE || id == PLANE || \
	id == CYLINDER || id == CONE))
		return (TRUE);
	return (FALSE);
}

t_bool	is_element_valid(t_obj_type id, char **str)
{
	int		i;
	int		idx;

	i = 0;
	idx = 1;
	if (is_info_valid(id, POINT))
		++idx;
	if (is_info_valid(id, BRI_RATIO))
		++idx;
	if (is_info_valid(id, NOR_VEC))
		++idx;
	if (is_info_valid(id, DIAMETER))
		++idx;
	if (is_info_valid(id, HEIGHT))
		++idx;
	if (is_info_valid(id, FOV))
		++idx;
	if (is_info_valid(id, RGB))
		++idx;
	while (str[i] != NULL)
		++i;
	if (i < idx)
		return (FALSE);
	return (TRUE);
}

t_bool	is_texture_valid(t_color_type id, char **str, int idx)
{
	int		i;

	i = 0;
	while (str[i] != NULL)
		++i;
	if (i <= idx)
		return (FALSE);
	if (id == CHECKBOARD && i - idx == 4)
		return (TRUE);
	else if (id == BUMPMAP && i - idx == 3)
		return (TRUE);
	return (FALSE);
}

#include "libft.h"
#include "parse_bonus.h"
#include "error_bonus.h"
#include <stdlib.h>

static t_obj_type	element_type_get(char *s)
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

static t_color_type	color_type_get(char *s)
{
	if (!ft_strcmp(s, "rgb"))
		return (COLOR);
	else if (!ft_strcmp(s, "ck"))
		return (CHECKBOARD);
	else if (!ft_strcmp(s, "bm"))
		return (BUMPMAP);
	return (NOTCOLOR);
}

int	parse_set(t_parse *lst, char **str)
{
	int		idx;

	idx = 1;
	lst->ident = str[0];
	lst->id = element_type_get(str[0]);
	if (lst->id == NOTTYPE)
		error_user("invalid element name.\n");
	if (is_element_valid(lst->id, str) == FALSE)
		error_user("Elements came in more than standard.\n");
	if (is_info_valid(lst->id, POINT))
		lst->point = str[idx++];
	if (is_info_valid(lst->id, BRI_RATIO))
		lst->bri_ratio = str[idx++];
	if (is_info_valid(lst->id, NOR_VEC))
		lst->nor_vec = str[idx++];
	if (is_info_valid(lst->id, DIAMETER))
		lst->diameter = str[idx++];
	if (is_info_valid(lst->id, HEIGHT))
		lst->height = str[idx++];
	if (is_info_valid(lst->id, FOV))
		lst->fov = str[idx++];
	return (idx);
}

static void	parse_obj_set(t_parse *lst, char **str, int idx)
{
	lst->t_ident = str[idx++];
	lst->texture_id = color_type_get(lst->t_ident);
	if (lst->texture_id == NOTCOLOR)
		error_user("invalid color name.\n");
	if (lst->texture_id == COLOR)
		lst->rgb = str[idx++];
	else if (lst->texture_id == CHECKBOARD)
	{
		lst->rgb = str[idx++];
		lst->check_color = str[idx++];
		lst->check_width = str[idx++];
		lst->check_height = str[idx++];
	}
	if (lst->texture_id == BUMPMAP)
		lst->texture_file = str[idx++];
	if (lst->texture_id == BUMPMAP && str[idx + 3] != NULL)
		lst->bump_file = str[idx++];
	lst->kd = str[idx++];
	lst->ks = str[idx++];
	lst->ksn = str[idx++];
}

void	parse_color_obj_set(t_parse *lst, char **str, int idx)
{
	if (is_color_obj_valid(lst->id, str, idx) == FALSE)
		error_user("Color info or object spec - Not standard.");
	if (lst->id == AMBIENT || lst->id == POINT_LIGHT)
		lst->rgb = str[idx++];
	else if (lst->id == SPHERE || lst->id == PLANE || \
	lst->id == CYLINDER || lst->id == CONE)
		parse_obj_set(lst, str, idx);
}

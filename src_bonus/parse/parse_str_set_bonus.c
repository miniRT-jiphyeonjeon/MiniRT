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
	if (is_info_valid(lst->id, RGB))
		lst->rgb = str[idx++];
	return (idx);
}

int	parse_obj_spec_set(t_parse *lst, char **str, int idx)
{
	if (is_obj_spec_valid(lst->id, str, idx) == FALSE)
		error_user("objecet spec came in wrong.\n");
	if (is_info_valid(lst->id, KD))
		lst->kd = str[idx++];
	if (is_info_valid(lst->id, KS))
		lst->ks = str[idx++];
	if (is_info_valid(lst->id, KSN))
		lst->ksn = str[idx++];
	return (idx);
}

void	parse_texture_set(t_parse *lst, char **str, int idx)
{
	if (idx == split_len(str))
	{
		lst->texture_id = COLOR;
		return ;
	}
	lst->t_ident = str[idx];
	if (ft_strcmp(lst->t_ident, "ck") == 0)
		lst->texture_id = CHECKBOARD;
	else if (ft_strcmp(lst->t_ident, "bm") == 0)
		lst->texture_id = BUMPMAP;
	else
		error_user("invalid texture name.\n");
	if (is_texture_valid(lst->texture_id, str, idx) == FALSE)
		error_user("texture info came in wrong.\n");
	if (lst->texture_id == CHECKBOARD)
	{
		lst->check_color = str[++idx];
		lst->check_width = str[++idx];
		lst->check_height = str[++idx];
	}
	if (lst->texture_id == BUMPMAP)
		lst->texture_file = str[++idx];
	if (lst->texture_id == BUMPMAP && str[++idx] != NULL)
		lst->bump_file = str[idx];
}

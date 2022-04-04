#include "libft.h"
#include "parse.h"
#include "vector3.h"
#include "list.h"
#include "error.h"
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
	return (NOTTYPE);
}

static void	parse_set(t_parse *lst, char **str)
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
}

static t_parse	*element_set(char *line)
{
	char		**str_splited;
	t_parse		*lst;

	lst = new_parse();
	str_splited = ft_split(line, " \t\v\f\r");
	if (str_splited == NULL)
		error_user("element_set - dynamic allocation problem.\n");
	else if (str_splited[0] == NULL)
	{
		free(lst);
		return (del_split(str_splited));
	}
	parse_set(lst, str_splited);
	free(str_splited);
	return (lst);
}

t_obj_list	*parse_to_str(int fd)
{
	char		*line;
	int			gnl_ret;
	t_obj_list	*lst_head;
	t_parse		*lst_parse;
	t_color3	color;

	color = color3(0, 0, 0);
	gnl_ret = 1;
	lst_head = NULL;
	while (gnl_ret == 1)
	{
		gnl_ret = get_next_line(fd, &line);
		if (gnl_ret == -1)
			error_user("get_next_line - dynamic allocation problem.\n");
		lst_parse = element_set(line);
		if (lst_parse != NULL)
			obj_list_add_back(&lst_head, new_obj_list(lst_parse, 0, color));
		if (line != NULL)
			free(line);
	}
	if (is_scene_env_valid(lst_head) == FALSE)
		error_user("Each Ambient, Light and Camera must be one.");
	return (lst_head);
}

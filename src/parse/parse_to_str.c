#include "libft.h"
#include "parse.h"
#include "vector3.h"
#include "list.h"
#include "error.h"
#include <stdlib.h>

void	parse_set(t_parse *lst, char **str)
{
	int		idx;

	if (is_object(str[0]) == FALSE)
		error_user("invalid object name.\n");
	lst->ident = str[0];
	idx = 1;
	if (is_type_valid(lst->ident, "point"))
		lst->point = str[idx++];
	if (is_type_valid(lst->ident, "bri_ratio"))
		lst->bri_ratio = str[idx++];
	if (is_type_valid(lst->ident, "nor_vec"))
		lst->nor_vec = str[idx++];
	if (is_type_valid(lst->ident, "diameter"))
		lst->diameter = str[idx++];
	if (is_type_valid(lst->ident, "height"))
		lst->height = str[idx++];
	if (is_type_valid(lst->ident, "fov"))
		lst->fov = str[idx++];
	if (is_type_valid(lst->ident, "rgb"))
		lst->rgb = str[idx++];
	if (is_element_valid(str, idx) == 0)
		error_user("Elements came in more than standard.\n");
}

t_parse	*info_set(char *line)
{
	char		**str_splited;
	t_parse		*lst;

	lst = new_parse();
	str_splited = ft_split(line, " \t\v\f\r");
	if (str_splited == NULL)
		error_user("info_set - dynamic allocation problem.\n");
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
		lst_parse = info_set(line);
		if (lst_parse != NULL)
			obj_list_add_back(&lst_head, new_obj_list(lst_parse, 0, color));
		if (line != NULL)
			free(line);
	}
	if (is_objnum_valid(lst_head) == FALSE)
		error_user("Each Ambient, Light and Camera must be one.");
	return (lst_head);
}

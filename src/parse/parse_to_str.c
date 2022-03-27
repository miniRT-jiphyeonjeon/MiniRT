#include "libft.h"
#include "parse.h"
#include "vector3.h"
#include "list.h"
#include "error.h"
#include <stdlib.h>


// 25줄 수정요망
void	parse_set(t_parse *lst, char **str)
{
	char	*id;
	int		idx;

	if (is_object(str[0]) == 0)
		error_user("invalid object name.\n");
	else
		lst->ident = str[0];
	id = lst->ident;
	idx = 1;
	if (!ft_strcmp(id, "C") || !ft_strcmp(id, "L") || \
	!ft_strcmp(id, "sp") || !ft_strcmp(id, "pl") || !ft_strcmp(id, "cy"))
		lst->point = str[idx++];
	if (!ft_strcmp(id, "A") || !ft_strcmp(id, "L"))
		lst->bri_ratio = str[idx++];
	if (!ft_strcmp(id, "C") || !ft_strcmp(id, "pl") || !ft_strcmp(id, "cy"))
		lst->nor_vec = str[idx++];
	if (!ft_strcmp(id, "sp") || !ft_strcmp(id, "cy"))
		lst->diameter = str[idx++];
	if (!ft_strcmp(id, "cy"))
		lst->height = str[idx++];
	if (!ft_strcmp(id, "C"))
		lst->fov = str[idx++];
	if (!ft_strcmp(id, "A") || !(ft_strcmp(id, "L")) || \
	!ft_strcmp(id, "sp") || !ft_strcmp(id, "pl") || !ft_strcmp(id, "cy"))
		lst->rgb = str[idx++];
	if (is_element_valid(str, idx) == 0)
		error_user("Elements came in more than standard.\n");
	return ;
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

// (x,y,z)가 오는 경우 쉼표 사이에 띄어쓰기 가능??
// 대문자가 하나도 없거나 여러개에 대한 대비
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
	// parse_print(lst_head);

	return (lst_head);
}

#include "libft.h"
#include "parse_bonus.h"
#include "vector3_bonus.h"
#include "list_bonus.h"
#include "error_bonus.h"
#include <stdlib.h>

static t_parse	*element_set(char *line)
{
	char		**str_splited;
	t_parse		*lst;
	int			idx;

	lst = new_parse();
	str_splited = ft_split(line, " \t\v\f\r");
	if (str_splited == NULL)
		error_user("element_set - dynamic allocation problem.\n");
	else if (str_splited[0] == NULL)
	{
		free(lst);
		return (del_split(str_splited));
	}
	idx = parse_set(lst, str_splited);
	parse_color_obj_set(lst, str_splited, idx);
	free(str_splited);
	return (lst);
}

t_obj_list	*parse_to_str(int fd)
{
	char		*line;
	t_gnl_res	gnl_ret;
	t_obj_list	*lst_head;
	t_parse		*lst_parse;

	gnl_ret = SUCCESS;
	lst_head = NULL;
	while (gnl_ret == SUCCESS)
	{
		gnl_ret = get_next_line(fd, &line);
		if (gnl_ret == ERROR)
			error_user("get_next_line error.\n");
		else if (gnl_ret == READFAIL)
			error_user("File format dose not match.\n");
		lst_parse = element_set(line);
		if (lst_parse != NULL)
			obj_list_add_back(&lst_head, \
			new_obj_list(lst_parse, 0, color3(0, 0, 0)));
		if (line != NULL)
			free(line);
	}
	if (is_scene_env_valid(lst_head) == FALSE)
		error_user("Each Ambient and Camera must be one, \
Light must be more than one.");
	return (lst_head);
}

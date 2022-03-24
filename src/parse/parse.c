#include "libft.h"
#include "parse.h"
#include "list.h"

static void	error_user(char *s)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(s, 2);
	exit(0);
}

int	is_range(int value_min, int value_max, int value_cur)
{
	if (value_cur < value_min || value_cur > value_max)
		return (0);
	return (1);
}

// enum에 맞게 고쳐야할 지도 모름
// is_???? 로 바꾸기
int	obj_cmp(char *s)
{
	if (ft_strcmp(s, "A") && ft_strcmp(s, "C") && ft_strcmp(s, "L") \
	&& ft_strcmp(s, "sp") && ft_strcmp(s, "pl") && ft_strcmp(s, "cy"))
		return (0);
	return (1);
}

t_parse	*new_parse(void)
{
	t_parse		*lst;

	lst = ft_calloc(sizeof(t_parse), 0);
	return (lst);
}

/*
t_bool로 처리하는게 좋을듯.
참조했던 정보들의 갯수 != 들어온 정보의 개수 -> 인자가 잘못 들어온 경우임
*/
int		is_element_valid(char **str, int idx)
{
	int		i;

	i = 0;
	while (str[i] != NULL)
		++i;
	if (i != idx)
		return (0);
	return (1);
}

// 25줄 수정요망
void	parse_set(t_parse *lst, char **str)
{
	char	*id;
	int		idx;

	if (obj_cmp(str[0]) == 0)
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
	if (!ft_strcmp(id, "A") || !ft_strcmp(id, "sp") || \
	!ft_strcmp(id, "pl") || !ft_strcmp(id, "cy"))
		lst->rgb = str[idx++];
	if (is_element_valid(str, idx) == 0)
		error_user("Elements came in more than standard.\n");
	return ;
}

static t_parse	*split_free(char **str)
{
	int		idx;

	idx = 0;
	while (str[idx] != NULL)
		free(str[idx++]);
	free(str);
	return (NULL);
}

void	parse_print(t_obj_list *lst)
{
	t_parse		*ps;
	char		*id;

	if (lst == NULL)
		return ;
	while (lst)
	{
		ps = lst->object;
		id = ps->ident;
		printf("%s\t", id);
		if (!ft_strcmp(id, "C") || !ft_strcmp(id, "L") || \
		!ft_strcmp(id, "sp") || !ft_strcmp(id, "pl") || !ft_strcmp(id, "cy"))
			printf("%s\t", ps->point);
		if (!ft_strcmp(id, "A") || !ft_strcmp(id, "L"))
			printf("%s\t", ps->bri_ratio);
		if (!ft_strcmp(id, "C") || !ft_strcmp(id, "pl") || !ft_strcmp(id, "cy"))
			printf("%s\t", ps->nor_vec);
		if (!ft_strcmp(id, "sp") || !ft_strcmp(id, "cy"))
			printf("%s\t", ps->diameter);
		if (!ft_strcmp(id, "cy"))
			printf("%s\t", ps->height);
		if (!ft_strcmp(id, "C"))
			printf("%s\t", ps->fov);
		if (!ft_strcmp(id, "A") || !ft_strcmp(id, "sp") || \
		!ft_strcmp(id, "pl") || !ft_strcmp(id, "cy"))
			printf("%s\t", ps->rgb);
		printf("\n");
		lst = lst->next;
	}
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
		return (split_free(str_splited));
	parse_set(lst, str_splited);
	free(str_splited);
	return (lst);
}

// (x,y,z)가 오는 경우 쉼표 사이에 띄어쓰기 가능??
int	info_get(int fd)
{
	char		*line;
	int			gnl_ret;
	t_obj_list	*lst_head;
	t_parse		*lst_parse;

	gnl_ret = 1;
	lst_head = NULL;

	while (gnl_ret == 1)
	{
		gnl_ret = get_next_line(fd, &line);
		if (gnl_ret == -1)
			error_user("get_next_line - dynamic allocation problem.\n");
		lst_parse = info_set(line);
		if (lst_parse != NULL)
			obj_list_add_back(&lst_head, new_obj_list(lst_parse, 0));
		if (line != NULL)
			free(line);
	}
	parse_print(lst_head);
	// 1차 파싱 -> 해당 구조체로 변환해주기
	return (0);
}

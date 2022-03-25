#include "libft.h"
#include "parse.h"
#include <stdlib.h>

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
		if (!ft_strcmp(id, "A") || !(ft_strcmp(id, "L")) || \
		!ft_strcmp(id, "sp") || !ft_strcmp(id, "pl") || !ft_strcmp(id, "cy"))
			printf("%s\t", ps->rgb);
		printf("\n");
		lst = lst->next;
	}
}

t_parse	*new_parse(void)
{
	t_parse		*lst;

	lst = ft_calloc(sizeof(t_parse), 0);
	return (lst);
}

void	del_parse(t_parse *parse)
{
	if (parse->ident != NULL)
		free(parse->ident);
	if (parse->bri_ratio != NULL)
		free(parse->bri_ratio);
	if (parse->point != NULL)
		free(parse->point);
	if (parse->nor_vec != NULL)
		free(parse->nor_vec);
	if (parse->diameter != NULL)
		free(parse->diameter);
	if (parse->height != NULL)
		free(parse->height);
	if (parse->fov != NULL)
		free(parse->fov);
	if (parse->rgb != NULL)
		free(parse->rgb);
}

t_parse	*del_split(char **str)
{
	int		idx;

	idx = 0;
	while (str[idx] != NULL)
		free(str[idx++]);
	free(str);
	return (NULL);
}

t_bool	is_object(char *s)
{
	if (ft_strcmp(s, "A") && ft_strcmp(s, "C") && ft_strcmp(s, "L") \
	&& ft_strcmp(s, "sp") && ft_strcmp(s, "pl") && ft_strcmp(s, "cy"))
		return (FALSE);
	return (TRUE);
}

/*
t_bool로 처리하는게 좋을듯.
참조했던 정보들의 갯수 != 들어온 정보의 개수 -> 인자가 잘못 들어온 경우임
*/
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

#include "libft.h"
#include "list_bonus.h"
#include "parse_bonus.h"
#include <stdlib.h>

t_obj_list	*new_obj_list(void *object, int type, t_color3 color)
{
	t_obj_list	*new_lst;

	new_lst = ft_calloc(sizeof(t_obj_list), 0);
	new_lst->type = type;
	new_lst->object = object;
	new_lst->color = color;
	new_lst->next = NULL;
	return (new_lst);
}

void	obj_list_add_back(t_obj_list **lst, t_obj_list *new_lst)
{
	t_obj_list	*tmp;

	if (!(*lst))
		*lst = new_lst;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_lst;
	}
	new_lst->next = NULL;
	return ;
}

void	del_obj_list(t_obj_list **lst)
{
	t_obj_list	*first_lst;
	t_obj_list	*second_lst;

	second_lst = *lst;
	*lst = NULL;
	while (second_lst)
	{
		first_lst = second_lst;
		second_lst = second_lst->next;
		free(first_lst->object);
		free(first_lst);
	}
}

// 함수포인터 이용해서 리펙토링 필요할 듯
void	del_obj_lst_parse(t_obj_list **lst)
{
	t_obj_list	*first_lst;
	t_obj_list	*second_lst;

	second_lst = *lst;
	*lst = NULL;
	while (second_lst)
	{
		first_lst = second_lst;
		second_lst = second_lst->next;
		del_parse(first_lst->object);
		free(first_lst->object);
		free(first_lst);
	}
}

int	obj_list_size(t_obj_list *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

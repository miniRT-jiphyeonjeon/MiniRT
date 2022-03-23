#include "libft.h"
#include "list.h"
#include <stdlib.h>

t_obj_list	*new_obj_list(void *object, int type)
{
	t_obj_list	*new_lst;

	new_lst = ft_calloc(sizeof(t_obj_list), 0);
	new_lst->type = type;
	new_lst->object = object;
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

void	obj_list_clear(t_obj_list **lst)
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

int	ft_lstsize(t_obj_list *lst)
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
#include "list_bonus.h"
#include "parse_bonus.h"
#include <stdlib.h>

void	del_color(t_color_info color)
{
	if (color.checkboard != NULL)
		free(color.checkboard);
	if (color.bumpmap != NULL)
	{
		if (color.bumpmap->texture.data.img != NULL)
			free(color.bumpmap->texture.data.img);
		if (color.bumpmap->bump.data.img != NULL)
			free(color.bumpmap->bump.data.img);
		free(color.bumpmap);
	}
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
		del_color(first_lst->color);
		free(first_lst->object);
		free(first_lst);
	}
}

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
		del_color(first_lst->color);
		del_parse(first_lst->object);
		del_parse_texture(first_lst->object);
		free(first_lst->object);
		free(first_lst);
	}
}

#ifndef LIST_H
# define LIST_H

# include "structure.h"

t_obj_list	*new_obj_list(void *object, int type, t_color3 color);
void		obj_list_add_back(t_obj_list **lst, t_obj_list *new_lst);
void		obj_list_clear(t_obj_list **lst);
int			obj_list_size(t_obj_list *lst);

#endif

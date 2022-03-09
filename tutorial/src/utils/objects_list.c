#include "utils.h"

void	object_add(t_object *objects[], t_object *new)
{
	t_object	*current;

	if (!*objects)
	{
		*objects = new;
		return ;
	}
	current = *objects;
	while (current->next)
		current = current->next;
	current->next = new;
}

t_object	*object_last(t_object objects[])
{
	if (!objects)
		return (NULL);
	while (objects->next)
		objects = objects->next;
	return (objects);
}

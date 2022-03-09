#include "scene.h"

t_object	*object(t_object_type type, void *data)
{
	t_object	*new;

	if (!(new = malloc(sizeof(t_object))))
		return (NULL);
	new->type = type;
	new->data = data;
	new->next = NULL;
	return (new);
}

t_sphere	*sphere(t_point3 center, double radius)
{
	t_sphere *sp;

	if(!(sp = malloc(sizeof(t_sphere))))
		return (NULL);
	sp->center = center;
	sp->radius = radius;
	sp->radius2 = radius * radius;
	return (sp);
}

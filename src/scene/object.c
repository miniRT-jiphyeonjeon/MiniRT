#include "scene.h"
#include "libft.h"

t_obj_list	*new_object(t_obj_type type, void *object, t_color3 color)
{
	t_obj_list	*new;

	new = ft_calloc(sizeof(t_obj_list), 0);
	new->type = type;
	new->color = color;
	new->object = object;
	return (new);
}

t_light	*new_point_light(t_point3 light_origin, double bright_ratio)
{
	t_light	*light;

	light = ft_calloc(sizeof(t_light), 0);
	light->origin = light_origin;
	light->bright_ratio = bright_ratio;
	return (light);
}

t_sphere	*new_sphere(t_point3 center, double radius)
{
	t_sphere	*sp;

	sp = ft_calloc(sizeof(t_sphere), 0);
	sp->center = center;
	sp->radius = radius;
	sp->radius2 = radius * radius;
	return (sp);
}

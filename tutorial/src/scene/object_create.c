#include "scene.h"

t_object	*object(t_object_type type, void *data, t_color3 albedo, t_checker checker)
{
	t_object	*new;

	if (!(new = malloc(sizeof(t_object))))
		return (NULL);
	new->type = type;
	new->data = data;
	new->albedo = albedo;
	new->checker = checker;
	new->next = NULL;
	return (new);
}

t_light	*light_point(t_point3 light_origin, t_color3 light_color, double bright_ratio)
{
	t_light	*light;

	if (!(light = malloc(sizeof(t_light))))
		return (NULL);
	light->origin = light_origin;
	light->light_color = light_color;
	light->bright_ratio = bright_ratio;
	return (light);
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

t_plane	*plane(t_point3 point, t_vec3 normal)
{
	t_plane	*pl;

	if(!(pl = malloc(sizeof(t_plane))))
		return (NULL);
	pl->point = point;
	pl->normal = normal;
	return (pl);
}

t_cylinder	*cylinder(t_point3 center, double radius, double height, t_vec3 normal)
{
	t_cylinder	*cy;

	if(!(cy = malloc(sizeof(t_cylinder))))
		return (NULL);
	cy->center = center;
	cy->radius = radius;
	cy->radius2 = radius * radius;
	cy->height = height;
	cy->normal = normal;
	return (cy);
}

t_cone	*cone(t_point3 center, double radius, double height, t_vec3 normal)
{
	t_cone	*cn;

	if(!(cn = malloc(sizeof(t_cone))))
		return (NULL);
	cn->center = center;
	cn->radius = radius;
	cn->radius2 = radius * radius;
	cn->height = height;
	cn->normal = normal;
	return (cn);
}

#include "trace.h"

t_bool	hit(t_object objects[], t_ray *ray, t_hit_record *rec)
{
	t_bool			hit_anything;
	t_hit_record	temp_rec;

	temp_rec = *rec;
	hit_anything = FALSE;
	while (objects)
	{
		if (hit_object(objects, ray, &temp_rec))
		{
			hit_anything = TRUE;
			temp_rec.tmax = temp_rec.t;
			*rec = temp_rec;
		}
		objects = objects->next;
	}
	return (hit_anything);
}

t_bool	hit_object(t_object objects[], t_ray *ray, t_hit_record *rec)
{
	t_bool	hit_result;

	hit_result = FALSE;
	if (objects->type == SPHERE)
		hit_result = hit_sphere(objects, ray, rec);
	if (objects->type == PLANE)
		hit_result = hit_plane(objects, ray, rec);
	if (objects->type == CYLINDER)
		hit_result = hit_cylinder(objects, ray, rec);
	if (objects->type == CONE)
		hit_result = hit_cone(objects, ray, rec);
	return (hit_result);
}
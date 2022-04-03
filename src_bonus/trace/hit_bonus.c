#include "trace_bonus.h"

t_bool	hit(t_obj_list objects[], t_ray *ray, t_hit_record *record)
{
	t_bool			hit_anything;
	t_hit_record	temp_record;

	temp_record = *record;
	hit_anything = FALSE;
	while (objects)
	{
		if (object_hit(objects, ray, &temp_record))
		{
			hit_anything = TRUE;
			temp_record.tmax = temp_record.t;
			*record = temp_record;
		}
		objects = objects->next;
	}
	return (hit_anything);
}

static t_obj_hit_f	object_type_check(t_obj_list object)
{
	if (object.type == SPHERE)
		return (hit_sphere);
	if (object.type == PLANE)
		return (hit_plane);
	if (object.type == CYLINDER)
		return (hit_cylinder);
	return (0);
}

t_bool	object_hit(t_obj_list objects[], t_ray *ray, t_hit_record *record)
{
	t_bool				hit_result;
	const t_obj_hit_f	object_hit = object_type_check(*objects);

	hit_result = FALSE | object_hit(objects, ray, record);
	return (hit_result);
}

#include "parse.h"
#include "scene.h"

t_camera	camera_prev_set(t_scene *scene, t_obj_list *lst)
{
	t_parse		*lst_parse;
	t_camera	camera;
	t_point3	origin;
	t_vec3		direct;
	double		h_fov;

	lst_parse = lst->object;
	origin = vec_get(lst_parse->point, 0, 0);
	direct = vec_get(lst_parse->nor_vec, -1, 1);
	h_fov = double_get(lst_parse->fov, 0, 180);
	camera = camera_set(&scene->canvas, origin, direct, h_fov);
	return (camera);
}

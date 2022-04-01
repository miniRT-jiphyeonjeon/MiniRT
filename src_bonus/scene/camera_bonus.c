#include <math.h>
#include "parse_bonus.h"
#include "scene_bonus.h"
#include "vector3_bonus.h"

t_camera	camera_prev_set(t_scene *scene, t_parse_list *lst)
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

static double	degree_to_radian(double degree)
{
	return (degree * M_PI / 180);
}

static t_vec3	upside_set(t_vec3 w)
{
	t_vec3	default_upside;
	t_vec3	u;

	default_upside = vec3(0, 1, 0);
	u = vec3_cross(default_upside, w);
	if (vec3_length(u) == 0)
		u = vec3_cross(vec3(0, 0, 1), w);
	return (vec3_unit(u));
}

t_camera
	camera_set(t_canvas *canvas, t_point3 origin, t_vec3 direct, double h_fov)
{
	t_camera	cam;
	double		theta;
	double		field_width;

	theta = degree_to_radian(h_fov);
	field_width = tan(theta / 2) * 2.0;
	cam.w_direction = direct;
	cam.u_upside = upside_set(cam.w_direction);
	cam.v_cross = vec3_unit(vec3_cross(cam.w_direction, cam.u_upside));
	cam.origin = origin;
	cam.viewport_width = field_width;
	cam.viewport_height = field_width * canvas->aspect_ratio;
	cam.horizontal = vec3_mult_scalar(cam.u_upside, cam.viewport_width);
	cam.vertical = vec3_mult_scalar(cam.v_cross, cam.viewport_height);
	cam.left_bottom = vec3_minus(cam.origin, vec3_plus(
				vec3_divide_scalar(vec3_plus(cam.horizontal, cam.vertical), 2),
				cam.w_direction));
	return (cam);
}

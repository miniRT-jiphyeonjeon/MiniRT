#include <math.h>
#include "scene.h"
#include "vector3.h"
#include "libft.h"

t_scene	*new_scene(int width, int height)
{
	t_scene	*scene;

	scene = ft_calloc(sizeof(t_scene), 0);
	scene->canvas = canvas_set(width, height);
	scene->camera = camera_set(&scene->canvas, point3(0, 0, 0), vec3_unit(vec3(0, 0, -1)), 90);
	return (scene);
}

t_canvas	canvas_set(int width, int height)
{
	t_canvas	canvas;

	canvas.width = width;
	canvas.height = height;
	canvas.aspect_ratio = (double)height / (double)width;
	return (canvas);
}

static double	degree_to_radian(double degree)
{
	return (degree * M_PI / 180);
}

t_camera
	camera_set(t_canvas *canvas, t_point3 origin, t_vec3 direct, double h_fov)
{
	t_camera	cam;
	double		theta;
	double		field_width;
	t_vec3		default_upside;

	theta = degree_to_radian(h_fov);
	field_width = tan(theta / 2) * 2.0;
	default_upside = vec3(0, 1, 0);
	cam.w_direction = direct;
	cam.u_upside = vec3_unit(vec3_cross(default_upside, cam.w_direction));
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

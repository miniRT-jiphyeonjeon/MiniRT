#include <math.h>
#include "scene.h"
#include "libft.h"
#include "list.h"

t_scene	*new_scene(int width, int height)
{
	t_scene		*scene;

	scene = ft_calloc(sizeof(t_scene), 0);
	scene->canvas = canvas_set(width, height);
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

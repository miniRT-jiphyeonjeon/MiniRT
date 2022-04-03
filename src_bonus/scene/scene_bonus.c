#include "scene_bonus.h"
#include "libft.h"
#include "list_bonus.h"

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

#include <stdio.h>
#include "structures.h"
#include "utils.h"
#include "print.h"
#include "scene.h"
#include "trace.h"

t_scene	*scene_init(void)
{
	t_scene		*scene;
	t_object	*objects;
	t_object	*lights;
	double		ka;

	if (!(scene = malloc(sizeof(t_scene))))
		return (NULL);
	scene->canvas = canvas(1920, 1080);
	scene->camera = camera(&scene->canvas, point3(0, 0, 0));
	// objects = object(CYLINDER, cylinder(point3(0, 0, -10), 3), color3(0.2, 0.3, 1));
	objects = object(PLANE, plane(point3(0, 0, -30), vunit(vec3(0, 0, 1))), color3(0.4, 0.6, 0.4));
	// objects = object(SPHERE, sphere(point3(-2, 0, -5), 2), color3(0.5, 0, 0));
	object_add(&objects, object(CYLINDER, cylinder(point3(0, 0, -20), 10, 10), color3(0.2, 0.3, 1)));
	// object_add(&objects, object(SPHERE, sphere(point3(0, 0, -20), 5), color3(0.6, 0.6, 0)));
	// object_add(&objects, object(SPHERE, sphere(point3(-50, 10, -100), 80), color3(1, 1, 1)));
	// object_add(&objects, object(PLANE, plane(point3(5, 0, -20), vunit(vec3(1, 1, 0))), color3(0.5, 0.5, 0)));
	scene->objects = objects;
	lights = object(LIGHT_POINT, light_point(point3(0, 0, 0), color3(1, 1, 1), 0.5), color3(0, 0, 0));
	scene->lights = lights;
	ka = 0.1;
	scene->ambient = vmult(color3(1, 1, 1), ka);
	return (scene);
}

int	main(void)
{
	int			r;
	int			c;
	double		u;
	double		v;
	t_color3	pixel_color;
	t_scene		*scene;

	scene = scene_init();

	printf("P3\n%d %d\n255\n", scene->canvas.width, scene->canvas.height);
	r = scene->canvas.height - 1;
	while (r >= 0)
	{
		c = -1;
		while (++c < scene->canvas.width)
		{
			u = (double)c / (scene->canvas.width - 1);
			v = (double)r / (scene->canvas.height - 1);
			scene->ray = ray_primary(&scene->camera, u, v);
			pixel_color = ray_color(scene);
			write_color(pixel_color);
		}
		r--;
	}
	return (0);
}

#include <stdio.h>
#include "structures.h"
#include "utils.h"
#include "print.h"
#include "scene.h"
#include "trace.h"

int	main(void)
{
	int			r;
	int			c;
	double		u;
	double	v;
	t_color3	pixel_color;
	t_canvas	canv;
	t_camera	cam;
	t_ray		ray;
	t_object	*objects;

	canv = canvas(800, 600);
	cam = camera(&canv, point3(0, 0, 0));
	objects = object(SPHERE, sphere(point3(-2, 0, -5), 2));
	object_add(&objects, object(SPHERE, sphere(point3(2, 0, -5), 2)));
	object_add(&objects, object(SPHERE, sphere(point3(0, -1000, 0), 990)));

	printf("P3\n%d %d\n255\n", canv.width, canv.height);
	r = canv.height - 1;
	while (r >= 0)
	{
		c = -1;
		while (++c < canv.width)
		{
			u = (double)c / (canv.width - 1);
			v = (double)r / (canv.height - 1);
			ray = ray_primary(&cam, u, v);
			pixel_color = ray_color(&ray, objects);
			write_color(pixel_color);
		}
		r--;
	}
	return (0);
}

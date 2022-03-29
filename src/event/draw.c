#include <stdlib.h>
#include "mlx.h"
#include "event.h"
#include "scene.h"
#include "trace.h"
#include "list.h"

static int	get_color(t_color3 pixel_color)
{
	int	color;

	color = 0;
	color |= color_calc(pixel_color.x) << 16;
	color |= color_calc(pixel_color.y) << 8;
	color |= color_calc(pixel_color.z);
	return (color);
}

static void	ray_trace(t_mlx *mlx, t_scene *scene, int row, int col)
{
	double		alpha;
	double		beta;
	t_color3	pixel_color;

	alpha = (double)col / (WIN_WIDTH - 1);
	beta = (double)row / (WIN_HEIGHT - 1);
	scene->ray = ray_primary(&scene->camera, alpha, beta);
	pixel_color = ray_tracing(scene);
	my_mlx_pixel_put(
		&mlx->img, col, WIN_HEIGHT - 1 - row, get_color(pixel_color));
}

static void	scene_create(t_mlx *mlx, t_scene *scene)
{
	int		row;
	int		col;

	row = WIN_HEIGHT - 1;
	while (row >= 0)
	{
		col = -1;
		while (++col < WIN_WIDTH)
			ray_trace(mlx, scene, row, col);
		row--;
	}
	del_obj_list(&scene->objects);
	del_obj_list(&scene->lights);
	free(scene);
}

void	scene_draw(t_mlx *mlx, t_scene *scene)
{
	scene_create(mlx, scene);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
}

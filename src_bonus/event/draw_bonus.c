#include <stdlib.h>
#include "mlx.h"
#include "event_bonus.h"
#include "scene_bonus.h"
#include "trace_bonus.h"
#include "list_bonus.h"

static void	ray_trace(t_mlx *mlx, t_scene *scene, int row, int col)
{
	double		alpha;
	double		beta;
	t_color3	pixel_color;
	int			res_color;

	alpha = (double)col / (WIN_WIDTH - 1);
	beta = (double)row / (WIN_HEIGHT - 1);
	scene->ray = ray_primary(&scene->camera, alpha, beta);
	pixel_color = ray_tracing(scene);
	row = WIN_HEIGHT - 1 - row;
	if (pixel_color.x == -1 && pixel_color.y == -1 && pixel_color.z == -1)
	{
		if (mlx->background.ratio_w < 1 || mlx->background.ratio_h < 1)
			res_color = oversampling(&mlx->background, col, row);
		else
			res_color = xpm_pixel_get(&mlx->background, col, row);
	}
	else
		res_color = color3_to_pixel(pixel_color);
	my_mlx_pixel_put(&mlx->img, col, row, res_color);
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

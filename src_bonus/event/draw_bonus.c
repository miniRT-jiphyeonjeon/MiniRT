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

	alpha = (double)col / (WIN_WIDTH - 1);
	beta = (double)row / (WIN_HEIGHT - 1);
	scene->ray = ray_primary(&scene->camera, alpha, beta);
	pixel_color = ray_tracing(scene);
	// if (pixel_color.x == -1 && pixel_color.y == -1 && pixel_color.z == -1)
	// 	my_mlx_pixel_put(&mlx->img, col, WIN_HEIGHT - 1 - row,
	// 		xpm_pixel_get(&scene->texture, col, WIN_HEIGHT - 1 - row));
	// else
		my_mlx_pixel_put(
			&mlx->img, col, WIN_HEIGHT - 1 - row, color3_to_pixel(pixel_color));
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
	//////////
	scene->texture.data.img = mlx_xpm_file_to_image(mlx->mlx,
			"./input_bonus/earthmap.xpm",
			&scene->texture.width, &scene->texture.height);
	scene->texture.data.addr = mlx_get_data_addr(
		scene->texture.data.img, &scene->texture.data.bpp,
		&scene->texture.data.line, &scene->texture.data.endian);
	scene->texture.ratio_w = (double)scene->texture.width / (double)WIN_WIDTH;
	scene->texture.ratio_h = (double)scene->texture.height / (double)WIN_HEIGHT;
	//////////
	scene_create(mlx, scene);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojekim <hyojekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:41:24 by hyojekim          #+#    #+#             */
/*   Updated: 2022/04/17 21:41:25 by hyojekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	scene_create(mlx, scene);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
}

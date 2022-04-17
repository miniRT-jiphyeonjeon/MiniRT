/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:04:56 by cjang             #+#    #+#             */
/*   Updated: 2022/04/17 21:35:59 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "parse_bonus.h"
#include "scene_bonus.h"
#include "vector3_bonus.h"

static double	degree_to_radian(double degree)
{
	return (degree * M_PI / 180);
}

static t_camera
	camera_set(t_canvas *canvas, t_point3 origin, t_vec3 direct, double h_fov)
{
	t_camera	cam;
	double		theta;
	double		field_width;

	theta = degree_to_radian(h_fov);
	field_width = tan(theta / 2) * 2.0;
	cam.w_dir = direct;
	coordinate_system(&cam.u_dir, &cam.v_dir, cam.w_dir);
	cam.origin = origin;
	cam.viewport_width = field_width;
	cam.viewport_height = field_width * canvas->aspect_ratio;
	cam.horizontal = vec3_mult_scalar(cam.u_dir, cam.viewport_width);
	cam.vertical = vec3_mult_scalar(cam.v_dir, cam.viewport_height);
	cam.left_bottom = vec3_minus(cam.origin, vec3_plus(
				vec3_divide_scalar(vec3_plus(cam.horizontal, cam.vertical), 2),
				cam.w_dir));
	return (cam);
}

t_camera	camera_prev_set(t_scene *scene, t_parse_list *lst)
{
	t_parse		*lst_parse;
	t_camera	camera;
	t_point3	origin;
	t_vec3		direct;
	double		h_fov;

	lst_parse = lst->object;
	origin = vec_double_get(lst_parse->point, 0, 0);
	direct = vec_double_get(lst_parse->nor_vec, -1, 1);
	h_fov = double_get(lst_parse->fov, 0, 180);
	camera = camera_set(&scene->canvas, origin, direct, h_fov);
	return (camera);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:05:00 by cjang             #+#    #+#             */
/*   Updated: 2022/04/17 22:53:56 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_bonus.h"
#include "libft.h"
#include "scene_bonus.h"

static t_canvas	canvas_set(int width, int height)
{
	t_canvas	canvas;

	canvas.width = width;
	canvas.height = height;
	canvas.aspect_ratio = (double)height / (double)width;
	return (canvas);
}


t_scene	*new_scene(int width, int height)
{
	t_scene		*scene;

	scene = ft_calloc(sizeof(t_scene), 0);
	scene->canvas = canvas_set(width, height);
	return (scene);
}

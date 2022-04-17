/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:13:22 by cjang             #+#    #+#             */
/*   Updated: 2022/04/17 21:47:03 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_BONUS_H
# define SCENE_BONUS_H

# include "structure_bonus.h"

// scene_bonus

t_scene		*new_scene(int width, int height);

// ambient_bonus

t_ambient	ambient_set(t_obj_list *lst);

// camera_bonus

t_camera	camera_prev_set(t_scene *scene, t_obj_list *lst);

// light_bonus

void		light_set(t_scene *scene, t_obj_list *lst);

// objects_bonus

void		object_set(t_scene *scene, t_parse_list *lst, void *mlx_ptr);

#endif

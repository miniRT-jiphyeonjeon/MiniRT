/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:14:26 by cjang             #+#    #+#             */
/*   Updated: 2022/04/17 21:47:07 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "structure.h"

// scene

t_scene		*new_scene(int width, int height);

// ambient

t_ambient	ambient_set(t_obj_list *lst);

// camera

t_camera	camera_prev_set(t_scene *scene, t_obj_list *lst);

// light

void		light_set(t_scene *scene, t_obj_list *lst);

// objects

void		sphere_set(t_scene *scene, t_obj_list *lst);
void		plane_set(t_scene *scene, t_obj_list *lst);
void		cylinder_set(t_scene *scene, t_obj_list *lst);

#endif

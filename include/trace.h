/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojekim <hyojekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:20:10 by hyojekim          #+#    #+#             */
/*   Updated: 2022/04/17 21:32:00 by hyojekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H

# include "structure.h"

// ray

t_ray		ray_set(t_point3 origin, t_vec3 direction);
t_ray		ray_primary(t_camera *cam, double alpha, double beta);
t_point3	ray_at(t_ray *ray, double t);
t_color3	ray_tracing(t_scene *scene);

// hit

t_bool		hit(t_obj_list objects[], t_ray *ray, t_hit_record *record);
t_bool		object_hit(t_obj_list objects[], t_ray *ray, t_hit_record *record);

// hit_*

t_bool		hit_sphere(t_obj_list objects[], t_ray *ray, t_hit_record *rec);
t_bool		hit_plane(t_obj_list objects[], t_ray *ray, t_hit_record *rec);
t_bool		hit_cylinder(t_obj_list objects[], t_ray *ray, t_hit_record *rec);

// phong_illumination

t_color3	phong_illumination_model(t_scene *scene);
t_color3	point_light_get(t_scene *scene, t_obj_list *light);

// phong_light

t_color3	phong_diffuse(t_scene *scene, t_obj_list *light, t_vec3 light_dir);
t_color3	phong_specular(t_scene *scene, t_obj_list *light, t_vec3 light_dir);
t_bool		is_in_shadow(t_scene *scene, t_vec3 light_dir, double light_len);

// util

double		root(t_eq eq, t_root_type type);
void		face_normal_set(t_ray *ray, t_hit_record *rec);

#endif

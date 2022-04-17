/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojekim <hyojekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:42:57 by hyojekim          #+#    #+#             */
/*   Updated: 2022/04/17 21:50:33 by hyojekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_BONUS_H
# define TRACE_BONUS_H

# include "structure_bonus.h"

// ray_bonus

t_ray		ray_set(t_point3 origin, t_vec3 direction);
t_ray		ray_primary(t_camera *cam, double alpha, double beta);
t_point3	ray_at(t_ray *ray, double t);
t_color3	ray_tracing(t_scene *scene);

// hit_bonus

t_bool		hit(t_obj_list objects[], t_ray *ray, t_hit_record *record);
t_bool		object_hit(t_obj_list objects[], t_ray *ray, t_hit_record *record);

// hit_*_bonus

t_bool		hit_sphere(t_obj_list objects[], t_ray *ray, t_hit_record *rec);
t_bool		hit_plane(t_obj_list objects[], t_ray *ray, t_hit_record *rec);
t_bool		hit_cylinder(t_obj_list objects[], t_ray *ray, t_hit_record *rec);
t_bool		hit_cone(t_obj_list objects[], t_ray *ray, t_hit_record *rec);

// phong_illumination_bonus

t_color3	phong_illumination_model(t_scene *scene);
t_color3	point_light_get(t_scene *scene, t_obj_list *light);
void		hit_color_set(t_hit_record *rec, t_obj_list objects[]);

// phong_light_bonus

t_color3	phong_diffuse(t_scene *scene, t_obj_list *light, t_vec3 light_dir);
t_color3	phong_specular(t_scene *scene, t_obj_list *light, t_vec3 light_dir);
t_bool		is_in_shadow(t_scene *scene, t_vec3 light_dir, double light_len);

// util_bonus

double		root(t_eq eq, t_root_type type);
void		face_normal_set(t_ray *ray, t_hit_record *rec);

// texture_bonus

t_bool		is_checkerboard(t_color_info texture);
t_bool		is_bumptexture(t_color_info texture);
t_bool		is_bumpmap(t_color_info texture);
t_color3	checker_color(double u, double v, t_color_info color);

// image_mapping_bonus

t_color3	image_mapping(double u, double v, t_xpm_image *img);
t_vec3		normal_mapping(t_hit_record *rec, t_xpm_image *img);

#endif

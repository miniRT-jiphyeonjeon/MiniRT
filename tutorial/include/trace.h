#ifndef TRACE_H
# define TRACE_H

# include "structures.h"
# include "utils.h"

t_ray		ray(t_point3 orig, t_vec3 dir);
t_point3	ray_at(t_ray *ray, double t);
t_ray		ray_primary(t_camera *cam, double u, double v);
t_color3	ray_color(t_scene *scene);

t_bool		hit(t_object objects[], t_ray *ray, t_hit_record *rec);
t_bool		hit_object(t_object objects[], t_ray *ray, t_hit_record *rec);
t_bool		hit_sphere(t_object objectsp[], t_ray *ray, t_hit_record *rec);
t_bool		hit_plane(t_object objects[], t_ray *ray, t_hit_record *rec);
t_bool		hit_cylinder(t_object objects[], t_ray *ray, t_hit_record *rec);
t_bool		hit_cone(t_object objects[], t_ray *ray, t_hit_record *rec);

void		set_face_normal(t_ray *ray, t_hit_record *rec);

t_bool		in_shadow(t_object objects[], t_ray shadow_ray, double light_len);
t_color3	point_light_get(t_scene *scene, t_light *light);
t_color3	phong_lighting(t_scene *scene);

#endif

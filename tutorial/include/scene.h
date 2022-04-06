#ifndef SCENE_H
# define SCENE_H

# include "structures.h"
# include "utils.h"

t_canvas	canvas(int  width, int height);
t_camera	camera(t_canvas *canvas, t_point3 origin, t_vec3 direct, double h_fov);
// t_object	*object(t_object_type type, void *data, t_color3 albedo);
t_object	*object(t_object_type type, void *data, t_color3 albedo, t_checker checker);
t_light		*light_point(t_point3 light_origin, t_color3 light_color, double bright_ratio);
t_sphere	*sphere(t_point3 center, double radius);
t_plane		*plane(t_point3 point, t_vec3 normal);
t_cylinder	*cylinder(t_point3 center, double radius, double height, t_vec3 normal);
t_cone		*cone(t_point3 center, double radius, double height, t_vec3 normal);

#endif

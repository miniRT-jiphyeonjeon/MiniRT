#ifndef SCENE_H
# define SCENE_H

# include "structure.h"

// scene.c

t_canvas	canvas_set(int width, int height);
t_scene		*new_scene(int width, int height);

// ambient

t_ambient	ambient_set(t_obj_list *lst);

// camera

t_camera	camera_prev_set(t_scene *scene, t_obj_list *lst);
t_camera	camera_set(
				t_canvas *canvas, t_point3 origin, t_vec3 direct, double h_fov);
// light

void		light_set(t_scene *scene, t_obj_list *lst);

// objects

void		sphere_set(t_scene *scene, t_obj_list *lst);
void		plane_set(t_scene *scene, t_obj_list *lst);
void		cylinder_set(t_scene *scene, t_obj_list *lst);

#endif

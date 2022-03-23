#ifndef SCENE_H
# define SCENE_H

# include "structure.h"

t_canvas	canvas_set(int width, int height);
t_camera	camera_set(
				t_canvas *canvas, t_point3 origin, t_vec3 direct, double h_fov);
t_scene		*new_scene(int width, int height);

#endif

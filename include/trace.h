#ifndef TRACE_H
# define TRACE_H

# include "structure.h"

t_ray		ray_set(t_point3 origin, t_vec3 direction);
t_ray		ray_primary(t_camera *cam, double alpha, double beta);
t_color3	ray_color(t_scene *scene);

#endif

#ifndef UTILS_H
# define UTILS_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include "structures.h"

// vector_set.c
t_vec3		vec3(double x, double y, double z);
t_point3	point3(double x, double y, double z);
t_point3	color3(double r, double g, double b);
void		vset(t_vec3 *vec, double x, double y, double z);

// vector_calc1.c
t_vec3		vplus(t_vec3 vec, double x, double y, double z);
t_vec3		vplus_(t_vec3 vec, t_vec3 vec2);
t_vec3		vminus(t_vec3 vec, double x, double y, double z);
t_vec3		vminus_(t_vec3 vec, t_vec3 vec2);

// vector_calc2.c
t_vec3		vmult(t_vec3 vec, double t);
t_vec3		vmult_(t_vec3 vec, t_vec3 vec2);
t_vec3		vdivide(t_vec3 vec, double t);
double		vdot(t_vec3 vec, t_vec3 vec2);
t_vec3		vcross(t_vec3 vec, t_vec3 vec2);

// vector_calc3.c
double		vlength2(t_vec3 vec);
double		vlength(t_vec3 vec);
t_vec3		vunit(t_vec3 vec);
t_vec3		vmin(t_vec3 vec1, t_vec3 vec2);

void		object_add(t_object *objects[], t_object *new);
t_object	*object_last(t_object objects[]);

#endif

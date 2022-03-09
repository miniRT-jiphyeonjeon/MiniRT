#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1,
}	t_bool;

typedef enum e_object_type
{
	SPHERE = 0,
}	t_object_type;

typedef struct s_vec3 t_vec3;
typedef struct s_vec3 t_point3;
typedef struct s_vec3 t_color3;

struct s_vec3
{
	double x;
	double y;
	double z;
};

typedef struct s_ray
{
	t_point3	origin;
	t_vec3		direct;
}	t_ray;

typedef struct s_hit_record
{
	t_point3	p;
	t_vec3		normal;
	double		tmin;
	double		tmax;
	double		t;
	t_bool		front_face;
}	t_hit_record;

typedef struct s_camera
{
	t_point3	origin;
	double		viewport_h;
	double		viewport_w;
	t_vec3		horizontal;
	t_vec3		vertical;
	double		focal_len;
	t_point3	left_bottom;
}	t_camera;

typedef struct s_canvas
{
	int		width;
	int		height;
	double	aspect_ratio;
}	t_canvas;

typedef struct s_object
{
	t_object_type	type;
	void			*data;
	void			*next;
}	t_object;

typedef struct s_sphere
{
	t_point3	center;
	double		radius;
	double		radius2;
}	t_sphere;

#endif

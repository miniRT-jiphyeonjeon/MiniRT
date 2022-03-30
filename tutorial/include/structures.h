#ifndef STRUCTURES_H
# define STRUCTURES_H

# define EPSILON 1e-6
# define LUMEN 3
# define CHECKER_WIDTH 16
# define CHECKER_HEIGHT 8

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1,
}	t_bool;

typedef enum e_object_type
{
	LIGHT_POINT = 0,
	SPHERE = 1,
	PLANE = 2,
	CYLINDER = 3,
	CONE = 4,
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

typedef struct s_checker
{
	t_bool		on;
	t_color3	even;
	t_color3	odd;
}	t_checker;

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
	double		u;
	double		v;
	t_bool		front_face;
	t_color3	albedo;
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
	t_color3		albedo;
	t_checker		checker;
	void			*next;
}	t_object;

typedef struct s_light
{
	t_point3	origin;
	t_color3	light_color;
	double		bright_ratio;
}	t_light;

typedef struct s_sphere
{
	t_point3	center;
	double		radius;
	double		radius2;
}	t_sphere;

typedef struct s_plane
{
	t_point3	point;
	t_vec3		normal;
}	t_plane;

typedef struct s_cylinder
{
	t_point3	center;
	t_vec3		normal;
	double		radius;
	double		radius2;
	double		height;
}	t_cylinder;

typedef t_cylinder	t_cone;

typedef struct s_scene
{
	t_canvas		canvas;
	t_camera		camera;
	t_object		*objects;
	t_object		*lights;
	t_color3		ambient;
	t_ray			ray;
	t_hit_record	rec;
}	t_scene;

#endif

#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct s_vec3	t_vec3;
typedef struct s_vec3	t_point3;
typedef struct s_vec3	t_color3;

struct s_vec3
{
	double	x;
	double	y;
	double	z;
};

typedef struct s_parse
{
	char	*ident;
	char	*bri_ratio;
	char	*point;
	char	*nor_vec;
	char	*diameter;
	char	*height;
	char	*fov;
	char	*rgb;
}	t_parse;

typedef enum e_obj_type
{
	LIGHT = 0,
	SPHERE = 1,
	PLANE = 2,
	CYLINDER = 3,
}	t_obj_type;

typedef struct s_obj_list
{
	t_obj_type	type;
	t_color3	color;
	void		*object;
	void		*next;
}	t_obj_list;

typedef struct s_canvas
{
	int		width;
	int		height;
	double	aspect_ratio;
}	t_canvas;

typedef struct s_camera
{
	t_point3	origin;
	double		viewport_height;
	double		viewport_width;
	t_vec3		w_direction;
	t_vec3		u_upside;
	t_vec3		v_cross;
	t_vec3		horizontal;
	t_vec3		vertical;
	t_point3	left_bottom;
}	t_camera;

typedef struct s_ray
{
	t_point3	origin;
	t_vec3		direction;
}	t_ray;

typedef struct s_ambient
{
	double		light_ratio;
	t_color3	light_color;
}	t_ambient;

typedef struct s_light
{
	t_point3	origin;
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

typedef struct s_scene
{
	t_canvas	canvas;
	t_camera	camera;
	t_obj_list	*object;
	t_obj_list	*light;
	t_ambient	ambient;
	t_ray		ray;
}	t_scene;

#endif

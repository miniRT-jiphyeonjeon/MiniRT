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
}t_parse;

// enum 추가되면 int type -> enum으로 변경해야 할 듯
typedef struct s_obj_list
{
	int		type;
	void	*object;
	void	*next;
}t_obj_list;

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

typedef struct s_scene
{
	t_canvas	canvas;
	t_camera	camera;
	t_ray		ray;
}	t_scene;

#endif

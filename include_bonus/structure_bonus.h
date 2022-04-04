#ifndef STRUCTURE_BONUS_H
# define STRUCTURE_BONUS_H

# include "libft_type.h"

# define EPSILON 1e-6

typedef struct s_vec3		t_vec3;
typedef struct s_vec3		t_point3;
typedef struct s_vec3		t_color3;
typedef struct s_obj_list	t_parse_list;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line;
	int		endian;
}	t_image;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_image	img;
}	t_mlx;

struct s_vec3
{
	double	x;
	double	y;
	double	z;
};

typedef enum e_root_type
{
	ALPHA = 0,
	BETA = 1,
}	t_root_type;

typedef struct s_eq
{
	double	a;
	double	half_b;
	double	c;
}	t_eq;

typedef enum e_color_type
{
	COLOR = 0,
	CHECKBOARD = 1,
	BUMPMAP = 2,
}	t_color_type;

typedef enum e_obj_type
{
	NOTTYPE = -1,
	AMBIENT = 0,
	CAMERA = 1,
	POINT_LIGHT = 2,
	SPHERE = 3,
	PLANE = 4,
	CYLINDER = 5,
	CONE = 6,
}	t_obj_type;

typedef enum e_info
{
	POINT = 0,
	BRI_RATIO = 1,
	NOR_VEC = 2,
	DIAMETER = 3,
	HEIGHT = 4,
	FOV = 5,
	RGB = 6,
}	t_info;

typedef struct s_parse
{
	t_obj_type		id;
	char			*ident;
	char			*bri_ratio;
	char			*point;
	char			*nor_vec;
	char			*diameter;
	char			*height;
	char			*fov;
	char			*rgb;
	t_color_type	texture_id;
	char			*t_ident;
	char			*check_color;
	char			*check_width;
	char			*check_height;
	char			*texture_file;
	char			*bump_file;
}	t_parse;

typedef struct s_checkboard
{
	t_color3	check_color;
	int			width;
	int			height;
}	t_checkboard;

typedef struct s_bumpmap
{
	t_image		texture;
	t_image		bump;
}	t_bumpmap;

typedef struct s_color_info
{
	t_color3		color;
	t_checkboard	*checkboard;
	t_bumpmap		*bumpmap;
}	t_color_info;

typedef struct s_obj_list
{
	t_obj_type		type;
	t_color_info	color;
	void			*object;
	void			*next;
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

typedef struct s_hit_record
{
	t_point3	p;
	t_vec3		normal;
	double		tmin;
	double		tmax;
	double		t;
	t_bool		front_face;
	t_color3	color;
}	t_hit_record;

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
	t_canvas		canvas;
	t_camera		camera;
	t_obj_list		*objects;
	t_obj_list		*lights;
	t_ambient		ambient;
	t_ray			ray;
	t_hit_record	record;
}	t_scene;

typedef t_bool				(*t_obj_hit_f)(
		t_obj_list *objects, t_ray *ray, t_hit_record *rec);

#endif

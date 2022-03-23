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
	char	*point[3];
	char	*nor_vec;
	char	*diameter;
	char	*height;
	char	*fov;
	char	*rgb[3];
}t_parse;

// enum 추가되면 int type -> enum으로 변경해야 할 듯
typedef struct s_obj_list
{
	int		type;
	void	*object;
	void	*next;
}t_obj_list;

#endif

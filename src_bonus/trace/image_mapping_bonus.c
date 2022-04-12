#include "trace_bonus.h"
#include "vector3_bonus.h"
#include "event_bonus.h"

static int	rgb_extract(int mlx_color, t_color_mask type)
{
	return ((mlx_color >> type) & 0xFF);
}

static t_color3	pixel_to_color3(int mlx_color)
{
	double	r;
	double	g;
	double	b;

	r = (double)rgb_extract(mlx_color, RED) / 256;
	g = (double)rgb_extract(mlx_color, GREEN) / 256;
	b = (double)rgb_extract(mlx_color, BLUE) / 256;
	return (color3(r, g, b));
}

t_color3	image_mapping(double u, double v, t_xpm_image *img)
{
	int		u_int;
	int		v_int;
	int		mlx_color;

	u_int = (int)(u * img->width);
	v_int = (int)((1.0 - v) * img->height);
	mlx_color = xpm_pixel_get(img, u_int, v_int);
	return (pixel_to_color3(mlx_color));
}

t_vec3	normal_mapping(t_hit_record *rec, t_xpm_image *img)
{
	int		u_int;
	int		v_int;
	int		mlx_color;
	t_vec3	normal_color;

	u_int = (int)(rec->u * img->width);
	v_int = (int)((1.0 - rec->v) * img->height);
	mlx_color = xpm_pixel_get(img, u_int, v_int);
	normal_color = pixel_to_color3(mlx_color);
	normal_color = vec3_minus(vec3_mult_scalar(normal_color, 2), vec3(1, 1, 1));
	return (vec3_unit(vec3(vec3_dot(rec->u_dir, normal_color),
				vec3_dot(rec->v_dir, normal_color),
				vec3_dot(rec->normal, normal_color))));
}

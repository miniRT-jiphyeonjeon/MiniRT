#include "libft.h"
#include "mlx.h"
#include "error_bonus.h"
#include "parse_bonus.h"
#include "scene_bonus.h"
#include "list_bonus.h"
#include <math.h>

static t_xpm_image	*image_get(char *filename, void *mlx_ptr)
{
	t_xpm_image	*image;
	char		*extension_name;
	int			filename_len;
	int			cmp_num;

	image = ft_calloc(sizeof(t_xpm_image), 0);
	extension_name = ".xpm";
	filename_len = ft_strlen(filename);
	if (filename_len < 4)
		error_user("The image file extension must be [.xpm].\n");
	cmp_num = ft_strcmp(&filename[filename_len - 4], extension_name);
	if (cmp_num != 0)
		error_user("The image file extension must be [.xpm].\n");
	image->data.img = mlx_xpm_file_to_image(mlx_ptr, \
	filename, &image->width, &image->height);
	if (image->data.img == NULL)
		error_user("image file is not correct.\n");
	image->data.addr = mlx_get_data_addr(image->data.img, \
	&image->data.bpp, &image->data.line, &image->data.endian);
	return (image);
}

static void	texture_get(t_obj_list *l, t_parse *p, void *mlx_ptr)
{
	if (p->texture_id == COLOR)
		l->color.color = vec_int_get(p->rgb, 0, 255);
	else if (p->texture_id == CHECKBOARD)
	{
		l->color.color = vec_int_get(p->rgb, 0, 255);
		l->color.checkboard = ft_calloc(sizeof(t_checkboard), 0);
		l->color.checkboard->check_color = vec_int_get(p->check_color, 0, 255);
		l->color.checkboard->width = double_get(p->check_width, 0, INFINITY);
		l->color.checkboard->height = double_get(p->check_height, 0, INFINITY);
	}
	else if (p->texture_id == BUMPMAP)
	{
		l->color.bumpmap = ft_calloc(sizeof(t_bumpmap), 0);
		l->color.bumpmap->texture = image_get(p->texture_file, mlx_ptr);
		if (p->bump_file != NULL)
			l->color.bumpmap->bump = image_get(p->bump_file, mlx_ptr);
	}
}

void	object_set(t_scene *scene, t_parse_list *lst, void *mlx_ptr)
{
	t_obj_list	*lst_new;
	t_parse		*lst_parse;
	t_object	*object;

	lst_parse = lst->object;
	lst_new = ft_calloc(sizeof(t_obj_list), 0);
	object = ft_calloc(sizeof(t_object), 0);
	obj_list_add_back(&scene->objects, lst_new);
	object->center = vec_double_get(lst_parse->point, 0, 0);
	if (lst_parse->id != SPHERE)
		object->normal = vec_double_get(lst_parse->nor_vec, -1, 1);
	if (lst_parse->id != PLANE)
	{
		object->radius = double_get(lst_parse->diameter, 0, INFINITY) / 2;
		object->radius2 = object->radius * object->radius;
	}
	if (lst_parse->id == CYLINDER || lst_parse->id == CONE)
		object->height = double_get(lst_parse->height, 0, INFINITY);
	object->kd = double_get(lst_parse->kd, 0, 1);
	object->ks = double_get(lst_parse->ks, 0, 1);
	object->ksn = double_get(lst_parse->ksn, 0, INFINITY);
	lst_new->type = lst_parse->id;
	texture_get(lst_new, lst_parse, mlx_ptr);
	lst_new->object = object;
}

#include "libft.h"
#include "parse.h"
#include "scene.h"
#include "list.h"

void	sphere_set(t_scene *scene, t_obj_list *lst)
{
	t_obj_list	*lst_new;
	t_parse		*lst_parse;
	t_sphere	*sphere;

	lst_parse = lst->object;
	lst_new = ft_calloc(sizeof(t_obj_list), 0);
	sphere = ft_calloc(sizeof(t_sphere), 0);
	obj_list_add_back(&scene->objects, lst_new);
	sphere->center = vec_get(lst_parse->point, 0, 0);
	sphere->radius = double_get(lst_parse->diameter, 0, 0) / 2;
	sphere->radius2 = sphere->radius * sphere->radius;
	lst_new->type = SPHERE;
	lst_new->color = vec_get(lst_parse->rgb, 0, 255);
	lst_new->object = sphere;
}

void	plane_set(t_scene *scene, t_obj_list *lst)
{
	t_obj_list	*lst_new;
	t_parse		*lst_parse;
	t_plane		*plane;

	lst_parse = lst->object;
	lst_new = ft_calloc(sizeof(t_obj_list), 0);
	plane = ft_calloc(sizeof(t_plane), 0);
	obj_list_add_back(&scene->objects, lst_new);
	plane->point = vec_get(lst_parse->point, 0, 0);
	plane->normal = vec_get(lst_parse->nor_vec, -1, 1);
	lst_new->type = PLANE;
	lst_new->color = vec_get(lst_parse->rgb, 0, 255);
	lst_new->object = plane;
}

void	cylinder_set(t_scene *scene, t_obj_list *lst)
{
	t_obj_list	*lst_new;
	t_parse		*lst_parse;
	t_cylinder	*cylinder;

	lst_parse = lst->object;
	lst_new = ft_calloc(sizeof(t_obj_list), 0);
	cylinder = ft_calloc(sizeof(t_cylinder), 0);
	obj_list_add_back(&scene->objects, lst_new);
	cylinder->center = vec_get(lst_parse->point, 0, 0);
	cylinder->normal = vec_get(lst_parse->nor_vec, -1, 1);
	cylinder->radius = double_get(lst_parse->diameter, 0, 0) / 2;
	cylinder->radius2 = cylinder->radius * cylinder->radius;
	cylinder->height = double_get(lst_parse->height, 0, 0);
	lst_new->type = CYLINDER;
	lst_new->color = vec_get(lst_parse->rgb, 0, 255);
	lst_new->object = cylinder;
}

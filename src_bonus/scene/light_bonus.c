#include "libft.h"
#include "parse_bonus.h"
#include "scene_bonus.h"
#include "list_bonus.h"

void	light_set(t_scene *scene, t_parse_list *lst)
{
	t_obj_list	*lst_new;
	t_parse		*lst_parse;
	t_light		*light;

	lst_parse = lst->object;
	lst_new = ft_calloc(sizeof(t_obj_list), 0);
	light = ft_calloc(sizeof(t_light), 0);
	obj_list_add_back(&scene->lights, lst_new);
	light->origin = vec_get(lst_parse->point, 0, 0);
	light->bright_ratio = double_get(lst_parse->bri_ratio, 0.0, 1.0);
	lst_new->type = POINT_LIGHT;
	lst_new->color = vec_get(lst_parse->rgb, 0, 255);
	lst_new->object = light;
}

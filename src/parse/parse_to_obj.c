#include "libft.h"
#include "scene.h"
#include "parse.h"
#include "event.h"

//printf 주석 존재
t_scene	*parse_to_obj(t_obj_list *lst)
{
	t_scene		*scene;
	t_parse		*lst_parse;

	scene = new_scene(WIN_WIDTH, WIN_HEIGHT);
	while (lst)
	{
		lst_parse = lst->object;
		if (!(ft_strcmp(lst_parse->ident, "A")))
			scene->ambient = ambient_set(lst);
		else if (!(ft_strcmp(lst_parse->ident, "C")))
			scene->camera = camera_prev_set(scene, lst);
		else if (!(ft_strcmp(lst_parse->ident, "L")))
			light_set(scene, lst);
		else if (!(ft_strcmp(lst_parse->ident, "sp")))
			sphere_set(scene, lst);
		else if (!(ft_strcmp(lst_parse->ident, "pl")))
			plane_set(scene, lst);
		else if (!(ft_strcmp(lst_parse->ident, "cy")))
			cylinder_set(scene, lst);
		lst = lst->next;
	}
	return (scene);
}

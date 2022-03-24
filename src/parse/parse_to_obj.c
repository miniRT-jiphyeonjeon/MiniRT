#include "libft.h"
#include "list.h"
#include "scene.h"
#include "parse.h"
#include "error.h"
#include "event.h"

double	double_get(char *s, double min, double max)
{
	double	d;
	t_res	res;

	d = ft_atof(s, &res);
	printf("%f, %d\n", d, res);
	if (res != CLEAN)
		error_user("Elements must came in standard.\n");
	if (min == 0 && max == 0)
		return (d);
	if (d < min || d > max)
		error_user("Elements must came in standard.\n");
	return (d);
}

// split->3개의 값을 struct s_vec3로 리턴
// 인자값 범위 지정
struct s_vec3	vec_get(char *s, double min, double max)
{
	struct s_vec3	vec;
	char			**str_splited;
	int				i;

	i = 0;
	str_splited = ft_split(s, ",");
	if (str_splited == NULL)
		error_user("color_get - dynamic allocation problem.\n");
	while (str_splited[i] != NULL)
		i++;
	if (i != 3)
		error_user("Elements must came in standard.\n");
	vec.x = double_get(str_splited[0], min, max);
	vec.y = double_get(str_splited[1], min, max);
	vec.z = double_get(str_splited[2], min, max);
	return (vec);
}

// rgb가 실수로 들어올때에 대해 고민해봐야함
t_ambient	ambient_set(t_obj_list *lst)
{
	t_parse		*lst_parse;
	t_ambient	ambient;

	lst_parse = lst->object;
	ambient.light_ratio = double_get(lst_parse->bri_ratio, 0.0, 1.0);
	ambient.light_color = vec_get(lst_parse->rgb, 0, 255);
	return (ambient);
}

t_camera	camera_prev_set(t_scene *scene, t_obj_list *lst)
{
	t_parse		*lst_parse;
	t_camera	camera;
	t_point3	origin;
	t_vec3		direct;
	double		h_fov;

	lst_parse = lst->object;
	origin = vec_get(lst_parse->point, 0, 0);
	direct = vec_get(lst_parse->nor_vec, -1, 1);
	h_fov = double_get(lst_parse->fov, 0, 180);
	camera = camera_set(&scene->canvas, origin, direct, h_fov);
	return (camera);
}

void	light_set(t_scene *scene, t_obj_list *lst)
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
	sphere->radius = double_get(lst_parse->diameter, 0, 0);
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
	cylinder->radius = double_get(lst_parse->diameter, 0, 0);
	cylinder->radius2 = cylinder->radius * cylinder->radius;
	cylinder->height = double_get(lst_parse->height, 0, 0);
	lst_new->type = CYLINDER;
	lst_new->color = vec_get(lst_parse->rgb, 0, 255);
	lst_new->object = cylinder;
}

t_scene	*parse_to_obj(t_obj_list *lst)
{
	t_scene		*scene;
	t_parse		*lst_parse;

	scene = new_scene(WIN_WIDTH, WIN_HEIGHT);
	while (lst)
	{
		lst_parse = lst->object;
		printf("<%s>\n", lst_parse->ident);
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
// 노말벡터 0이면 큰일남, 0나누기 됨

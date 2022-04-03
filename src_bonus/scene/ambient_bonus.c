#include "parse_bonus.h"

// rgb가 실수로 들어올때에 대해 고민해봐야함
t_ambient	ambient_set(t_parse_list *lst)
{
	t_parse		*lst_parse;
	t_ambient	ambient;

	lst_parse = lst->object;
	ambient.light_ratio = double_get(lst_parse->bri_ratio, 0.0, 1.0);
	ambient.light_color = vec_get(lst_parse->rgb, 0, 255);
	return (ambient);
}

#ifndef PARSE_H
# define PARSE_H

# include "structure_bonus.h"

// parse_read

int				fd_get(int argv, char **argc);

// parse_to_str

t_obj_list		*parse_to_str(int fd);

// parse_to_element

t_scene			*parse_to_element(t_parse_list *lst);

// parse_to_num

double			double_get(char *s, double min, double max);
struct s_vec3	vec_get(char *s, double min, double max);

// parse_utils

t_parse			*new_parse(void);
void			del_parse(t_parse *parse);
t_parse			*del_split(char **str);

// parse_bool

t_bool			is_scene_env_valid(t_parse_list *lst);
t_bool			is_element_valid(char **str, int idx);
t_bool			is_info_valid(t_obj_type id, t_info info);

#endif

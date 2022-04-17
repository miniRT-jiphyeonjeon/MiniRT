#ifndef PARSE_H
# define PARSE_H

# include "structure.h"

// parse_read

int				fd_get(int argv, char **argc);

// parse_to_str

t_obj_list		*parse_to_str(int fd);

// parse_to_element

t_scene			*parse_to_element(t_parse_list *lst);

// parse_to_num

int				int_get(char *s, int min, int max);
double			double_get(char *s, double min, double max);
struct s_vec3	vec_int_get(char *s, int min, int max);
struct s_vec3	vec_double_get(char *s, double min, double max);

// parse_utils

t_parse			*new_parse(void);
void			del_parse(t_parse *parse);
t_parse			*del_split(char **str);

// parse_bool

t_bool			is_scene_env_valid(t_parse_list *lst);
t_bool			is_info_valid(t_obj_type id, t_info info);
t_bool			is_element_valid(t_obj_type id, char **str);

#endif

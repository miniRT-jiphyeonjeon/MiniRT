#ifndef PARSE_H
# define PARSE_H

# include "structure.h"

// parse_read

int				fd_get(int argv, char **argc);

// parse_to_str

t_obj_list		*parse_to_str(int fd);

// parse_to_obj

t_scene			*parse_to_obj(t_obj_list *lst);

// parse_to_num

double			double_get(char *s, double min, double max);
struct s_vec3	vec_get(char *s, double min, double max);

// parse_utils

void			parse_print(t_obj_list *lst);
t_parse			*new_parse(void);
void			del_parse(t_parse *parse);
t_parse			*del_split(char **str);
t_bool			is_object(char *s);
t_bool			is_element_valid(char **str, int idx);

#endif

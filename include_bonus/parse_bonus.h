#ifndef PARSE_BONUS_H
# define PARSE_BONUS_H

# include "structure_bonus.h"

// parse_read

int				fd_get(int argv, char **argc);

// parse_to_str

t_obj_list		*parse_to_str(int fd);

// parse_str_set_bonus

int				parse_set(t_parse *lst, char **str);
int				parse_obj_spec_set(t_parse *lst, char **str, int idx);
void			parse_texture_set(t_parse *lst, char **str, int idx);

// parse_to_element

t_scene			*parse_to_element(t_parse_list *lst, void *mlx_ptr);

// parse_to_num

double			double_get(char *s, double min, double max);
struct s_vec3	vec_get(char *s, double min, double max);

// parse_utils

t_parse			*new_parse(void);
void			del_parse(t_parse *parse);
void			del_parse_texture(t_parse *parse);
t_parse			*del_split(char **str);
int				split_len(char **str);

// parse_bool

t_bool			is_scene_env_valid(t_parse_list *lst);
t_bool			is_info_valid(t_obj_type id, t_info info);
t_bool			is_element_valid(t_obj_type id, char **str);
t_bool			is_obj_spec_valid(t_obj_type id, char **str, int idx);
t_bool			is_texture_valid(t_color_type id, char **str, int idx);

#endif

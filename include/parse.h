#ifndef PARSE_H
# define PARSE_H

// 인크루드 c 언어에 넣어줘야함
# include "structure.h"
# include <stdio.h>

// parse_read
int				fd_get(int argv, char **argc);

// parse_to_str
t_obj_list		*parse_to_str(int fd);

// parse_to_obj
t_scene			*parse_to_obj(t_obj_list *lst);

// parse_to_num
double			double_get(char *s, double min, double max);
struct s_vec3	vec_get(char *s, double min, double max);

// ambient_set
t_ambient		ambient_set(t_obj_list *lst);

// camera_set
t_camera		camera_prev_set(t_scene *scene, t_obj_list *lst);

// light_set
void			light_set(t_scene *scene, t_obj_list *lst);

// objects_set
void			sphere_set(t_scene *scene, t_obj_list *lst);
void			plane_set(t_scene *scene, t_obj_list *lst);
void			cylinder_set(t_scene *scene, t_obj_list *lst);

// parse_utils
void			parse_print(t_obj_list *lst);
t_parse			*new_parse(void);
void			del_parse(t_parse *parse);
t_parse			*del_split(char **str);
t_bool			is_object(char *s);
t_bool			is_element_valid(char **str, int idx);

#endif

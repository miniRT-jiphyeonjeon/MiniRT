#ifndef PARSE_H
# define PARSE_H

// 인크루드 c 언어에 넣어줘야함
# include "structure.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int			fd_get(int argv, char **argc);
t_obj_list	*info_get(int fd);
t_scene		*parse_to_obj(t_obj_list *lst);

#endif

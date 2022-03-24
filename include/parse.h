#ifndef PARSE_H
# define PARSE_H

// 인크루드 c 언어에 넣어줘야함
# include "structure.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		fd_get(int argv, char **argc);
int		info_get(int fd);

#endif

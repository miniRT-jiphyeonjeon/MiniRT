#ifndef FT_READ_H
# define FT_READ_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif
# ifndef FD_MAX
#  define FD_MAX 256
# endif

t_gnl_res		get_next_line(int fd, char **line);

#endif

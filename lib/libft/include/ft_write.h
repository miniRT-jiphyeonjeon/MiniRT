#ifndef FT_WRITE_H
# define FT_WRITE_H

int		ft_write(int fd, const char *str);
int		ft_writes(int fd, char *arr[]);
void	ft_putstr_fd(char *s, int fd);

#endif

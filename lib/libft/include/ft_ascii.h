#ifndef FT_ASCII_H
# define FT_ASCII_H

# include "libft_type.h"

double	ft_atof(char *str, int *valid);
int		ft_atoi(const char *str, t_res *valid);
t_bool	ft_isdigit(int c);
t_bool	ft_isspace(int c);

#endif

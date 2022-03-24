#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	error_user(char *s)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(s, 2);
	exit(0);
}

void	error_system(void)
{
	perror("Error\n");
	exit(0);
}

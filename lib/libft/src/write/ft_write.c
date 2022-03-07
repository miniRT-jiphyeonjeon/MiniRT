#include "libft.h"
#include <unistd.h>

int	ft_write(int fd, const char *str)
{
	return (write(fd, str, ft_strlen(str)));
}

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t size, size_t count)
{
	char			*ptr;
	const size_t	allocated_space = size * (count + 1);

	ptr = malloc(allocated_space);
	if (!ptr)
	{
		perror("Error\nCannot allocate memory\n");
		exit(EXIT_FAILURE);
	}
	ft_bzero(ptr, allocated_space);
	return (ptr);
}

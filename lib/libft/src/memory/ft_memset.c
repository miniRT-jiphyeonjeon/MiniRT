#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	by_c;

	ptr = (unsigned char *)b;
	by_c = (unsigned char)c;
	i = 0;
	while (i < len)
		ptr[i++] = by_c;
	return (b);
}

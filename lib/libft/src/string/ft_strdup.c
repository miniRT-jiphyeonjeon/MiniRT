#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t		i;
	size_t		len;
	char		*cp;

	i = 0;
	len = 0;
	while (s1[len])
		len++;
	cp = ft_calloc(sizeof(char), len);
	while (i < len + 1)
	{
		cp[i] = s1[i];
		i++;
	}
	return (cp);
}

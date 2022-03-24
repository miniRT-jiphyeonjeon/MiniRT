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
	cp = (char *)malloc(len + 1);
	if (!cp)
		return (NULL);
	while (i < len + 1)
	{
		cp[i] = s1[i];
		i++;
	}
	return (cp);
}

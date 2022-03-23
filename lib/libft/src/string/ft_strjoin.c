#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s1s2;
	size_t	len[2];
	size_t	i;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	len[0] = ft_strlen(s1);
	len[1] = ft_strlen(s2);
	s1s2 = (char *)malloc(len[0] + len[1] + 1);
	if (!s1s2)
		return (NULL);
	while (*s1)
		s1s2[i++] = *s1++;
	while (*s2)
		s1s2[i++] = *s2++;
	s1s2[i] = 0;
	return (s1s2);
}

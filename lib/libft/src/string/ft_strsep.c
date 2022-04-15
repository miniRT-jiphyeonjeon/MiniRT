#include "libft.h"

char	*ft_strsep(char **stringp, const char delim)
{
	char	*tmp;

	tmp = *stringp;
	if (tmp == NULL)
		return (NULL);
	while (**stringp)
	{
		if (**stringp == delim)
		{
			**stringp = '\0';
			(*stringp)++;
			return (tmp);
		}
		(*stringp)++;
	}
	*stringp = NULL;
	return (tmp);
}

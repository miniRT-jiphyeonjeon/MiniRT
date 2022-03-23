#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	str_len;

	str_len = 0;
	if (!dst || !src)
		return (0);
	while (src[str_len])
		str_len++;
	while (dstsize > 1 && *src)
	{
		*dst++ = *src++;
		dstsize--;
	}
	if (dstsize > 0)
		*dst = '\0';
	return (str_len);
}

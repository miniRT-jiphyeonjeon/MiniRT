#include "ft_ascii.h"

t_bool	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (TRUE);
	else
		return (FALSE);
}

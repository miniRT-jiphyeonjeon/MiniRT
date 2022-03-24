#include "ft_ascii.h"

t_bool	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (TRUE);
	else
		return (FALSE);
}

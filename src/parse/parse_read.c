#include "libft.h"
#include "parse.h"

static void	error_user(char *s)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(s, 2);
	exit(0);
}

static void	error_system(void)
{
	perror("Error\n");
	exit(0);
}

int	fd_get(int argv, char **argc)
{
	int		fd;
	int		filename_len;
	int		cmp_num;
	char	*extension_name;

	extension_name = ".rt";
	if (argv != 2)
		error_user("The number of arguments must be one.\n");
	filename_len = ft_strlen(argc[1]);
	if (filename_len < 3)
		error_user("The file extension must include [.rt].\n");
	cmp_num = ft_strncmp(&argc[1][filename_len - 3], extension_name, 3);
	if (cmp_num != 0)
		error_user("The file extension must include [.rt].\n");
	fd = open(argc[1], O_RDONLY);
	if (fd < 0)
		error_system();
	return (fd);
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <unistd.h>
#include <string.h>
#include "vector3.h"

#define THETA 0
#define PHI 1

static bool	is_validate_degree(double degree, int type)
{
	if (degree < 0 || (type == THETA && degree >= 90) || (type == PHI && degree >= 180))
		return (false);
	return (true);
}

static double	degree_to_radian(int degree)
{
	return ((double)degree * M_PI / 180);
}

int	main(int argc, char *argv[])
{
	if (argc != 5)
	{
		const char	*error_msg = "Error: Usage: ./miniearth <latitude> <S/N> <longitude> <W/E>\n";
		write(2, error_msg, strlen(error_msg));
		return (1);
	}
	
	// spherical coordinate
	const int	r = 10;
	double		theta;
	double		phi;

	theta = atof(argv[1]);
	phi = atof(argv[3]);
	if (!is_validate_degree(theta, THETA) || !is_validate_degree(phi, PHI))
	{
		printf("Error: latitude should be [0, 90) and longitude should be [0, 180)\n");
		return (1);
	}
	if (argv[2][0] == 'S')
		theta *= -1;
	if (argv[4][0] == 'W')
		phi *= -1;
	theta = degree_to_radian(theta + 90);
	phi = degree_to_radian(phi + 180);

	// orthogonal coordinate
	double	x;
	double	y;
	double	z;

	x = -cos(phi) * sin(theta) * r;
	y = -cos(theta) * r;
	z = sin(phi)* sin(theta) * r;

	// vector
	const t_vec3	normal = vec3_unit(vec3(x, y, z));
	const t_point3	camera_origin = vec3_mult_scalar(normal, 15);
	t_vec3			camera_u;
	t_vec3			camera_v;
	t_point3		light;

	camera_u = vec3_cross(vec3(0, 1, 0), normal);
	if (vec3_length_square(camera_u) == 0)
		camera_u = vec3_cross(vec3(0, 0, 1), normal);
	camera_u = vec3_unit(camera_u);
	camera_v = vec3_cross(normal, camera_u);
	light = vec3_plus(camera_origin,
		vec3_plus(vec3_mult_scalar(camera_u, -5), vec3_mult_scalar(camera_v, 5)));

	printf("A 0.2 255,255,255\n");
	printf("C %f,%f,%f %f,%f,%f 45\n",
		camera_origin.x, camera_origin.y, camera_origin.z,
		normal.x * -1, normal.y * -1, normal.z * -1);
	printf("L %f,%f,%f 0.8 255,255,255\n",
		light.x, light.y, light.z);
	printf("sp 0,0,0 10 bm ./input_bonus/earthmap.xpm ./input_bonus/earthmap_normal.xpm 1 0.5 2\n");
	printf("sp 0,0,0 50 bm ./input_bonus/milkyway.xpm 1 0.5 2\n");
}

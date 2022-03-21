#include "scene.h"

double	degree_to_radian(double degree)
{
	return (degree * M_PI / 180);
}

t_camera	camera(t_canvas *canvas, t_point3 origin, t_vec3 direct, double h_fov)
{
	t_camera	cam;
	double		focal_len = 1.0; // 설정값
	
	// FOV 관련
	double		viewport_width;
	double		theta;
	double		width;

	theta = degree_to_radian(h_fov);
	width = tan(theta/2);
	viewport_width = 2.0 * width;

	// 방향 관련
	t_vec3	vup = vec3(0, 1, 0); // 설정값
	t_vec3	w;
	t_vec3	u;
	t_vec3	v;

	w = direct;
	u = vunit(vcross(vup, w));
	v = vunit(vcross(w, u));

	cam.origin = origin;
	cam.viewport_w = viewport_width;
	cam.viewport_h = viewport_width * canvas->aspect_ratio;
	cam.focal_len = focal_len;
	// cam.horizontal = vec3(cam.viewport_w, 0, 0);
	// cam.vertical = vec3(0, cam.viewport_h, 0);
	cam.horizontal = vmult(u, cam.viewport_w);
	cam.vertical = vmult(v, cam.viewport_h);
	cam.left_bottom = vminus_(cam.origin, vplus_(vdivide(vplus_(cam.horizontal, cam.vertical), 2), w));
	return (cam);
}

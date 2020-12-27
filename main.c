/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selibrah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 18:17:58 by selibrah          #+#    #+#             */
/*   Updated: 2020/02/11 10:50:31 by selibrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp.h"
#include <math.h>
#include <stdio.h>

void putimg(int x, int y, int color,double alfa,double alfa2, t_win *wi)
{
	int i;

	i = 4 * x + y * wi->size_line;
	wi->line[i] = 0;
	wi->line[i++] = ((color >> 16) * alfa + 255 * alfa2) >=  255 ? 255 : (color >> 16) * alfa + 255 * alfa2 ;
	wi->line[i++] =   (((color >> 8) - (color >> 16) * 256) * alfa + 255 * alfa2) >=  255 ? 255 : ((color >> 8) - (color >> 16) * 256) * alfa + 255 * alfa2;
	wi->line[i++] =  ((color - (color >> 8) * 256) * alfa + 255 * alfa2) >=  255 ? 255 : (color - (color >> 8) * 256) * alfa + 255 * alfa2;
}
void cord(t_vec *sphere, double x, double y, double z)
{
	sphere->x = x;
	sphere->y = y;
	sphere->z = z;
}

/*double pow(double x){
	return x * x;
}*/
double intersiction(t_sphere sphere,t_vec direction,t_vec origine,t_vec light,t_win *wi,int color,double z2) {
	double a;
	double b;
	double c;
	double tplus;
	double tsub;
	double delta;
	t_vec v1;
	t_vec v2;
	double v1mag;
	t_vec v1norm;
	double v2mag;
	t_vec v2norm;
	double res;
	double angle;
	t_vec inter;
	double  alfa;
	double v1v2;
	t_vec h;
	t_vec ref;
	t_vec cam;
	double sr;
	double alfa2;
	a = (direction.x - origine.x) * (direction.x - origine.x) + (direction.y - origine.y) * (direction.y - origine.y) + (direction.z - origine.z) * (direction.z - origine.z);
	b =  2 * ((direction.x - origine.x) * (origine.x - sphere.cord.x) + (direction.y - origine.y) * (origine.y - sphere.cord.y) + \
		      (direction.z - origine.z) * (origine.z - sphere.cord.z));
	c = (sphere.cord.x) * (sphere.cord.x) + (sphere.cord.y) * (sphere.cord.y) + (sphere.cord.z) * (sphere.cord.z) + \
	    (origine.x) * (origine.x) + (origine.y) * (origine.y) + (origine.z) * (origine.z) - \
		2 * (sphere.cord.x * origine.x + sphere.cord.y * origine.y + sphere.cord.z * origine.z) - \
		(sphere.r) * (sphere.r);
	delta = b * b - 4 * a * c;
	if(delta >= 0)
	{
		tplus =(double) (-b + sqrt(b*b - 4 * a * c))/(2 * a);
		tsub =(double) (-b - sqrt(b*b - 4 * a * c))/(2 * a);
	}
	cord(&inter, origine.x + (direction.x - origine.x) * tplus, origine.y + (direction.y - origine.y) * tplus, origine.z + (direction.z - origine.z) * tplus);
	if (delta >= 0)
	{
		cord(&v1,inter.x - sphere.cord.x ,inter.y - sphere.cord.y, inter.z - sphere.cord.z);
		cord(&v2,light.x - inter.x ,light.y - inter.y,light.z - inter.z);
		cord(&cam,origine.x - inter.x ,origine.y - inter.y,origine.z - inter.z);
		v1mag = sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);
		v2mag = sqrt(v2.x * v2.x + v2.y * v2.y + v2.z * v2.z);
		v1v2 = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
		//angle =  3.14159 - acos(v1v2 / (v1mag * v2mag));
		alfa = v1v2 / (v1mag * v2mag);
		sr = sqrt((v2.x + cam.x) * (v2.x + cam.x) + (v2.y + cam.y) * (v2.y + cam.y) + (v2.z + cam.z) * (v2.z + cam.z));
		cord(&h,(v2.x + cam.x)/sr  ,(v2.y + cam.y)/sr  , (v2.z + cam.z)/sr);
		v1mag = sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);
		v2mag = sqrt(h.x * h.x + h.y * h.y + h.z * h.z);
		v1v2 = v1.x * h.x + v1.y * h.y + v1.z * h.z;
		//angle =  3.14159 - acos(v1h / (v1mag * v2mag));
		alfa2 = v1v2 / (v1mag * v2mag);

		if (z2 < inter.z)
			putimg(direction.x ,direction.y,color,fabs(alfa > 0 ? 0 : alfa),powf(alfa2> 0 ? 0 :alfa2,10),wi);
	}
	else{
		return -1;
	}
	return inter.z;
}

int main()
{
	t_win wi;
	double alfa;
	t_sphere sphere;
	t_sphere sphere2;
	t_sphere sphere3;
	t_sphere sphere4;
	t_sphere sphere5;
	t_sphere sphere6;
	t_vec plan;
	t_ray f;
	t_vec light;
	t_vec v1;
	t_vec v2;
	double v1mag;
	t_vec v1norm;
	double v2mag;
	t_vec v2norm;
	double res;
	double angle;
	

	cord(&(f.orgi),500,500,0);
	/*cord(&plan,500,500,500);
	cord(&sphere.cord, 500, 500, 600);
	cord(&sphere2.cord, 700, 300, 600);
	cord(&sphere3.cord, 300, 700, 600);
	cord(&sphere4.cord, 300, 300, 600);
	cord(&sphere5.cord, 700, 700, 600);
	cord(&sphere6.cord, 500, 500, 600);
	cord(&light,500,500,0); */

	cord(&sphere.cord, 500, 500, 500);
	cord(&light,500,800,0);
	wi.winx = 1000;
	wi.winy = 1000;
	wi.mlx_ptr = mlx_init();
	wi.win_ptr = mlx_new_window(wi.mlx_ptr, 1000, 1000, "Best Rtv1 Ever");
	wi.img_ptr = mlx_new_image(wi.mlx_ptr, wi.winx, wi.winy);
	wi.line = mlx_get_data_addr(wi.img_ptr, &wi.bpp, &wi.size_line, &wi.endian);

	wi.x = 0;
	wi.y = 0;
	wi.z = 200;
	putimg(light.x,light.y, 0xFFFFFF,1,0,&wi);
	cord(&(f.dir),wi.x,wi.y,0);
	sphere.r = 250;
	sphere2.r = 150;
	sphere3.r = 150;
	sphere4.r = 150;
	sphere5.r = 150;
	sphere6.r = 150;
	printf("hello\n");
	printf("r== %f\n",sphere.r);
	while (wi.x < 1000)
	{
		wi.y = 0;
		while (wi.y < 1000)
		{
			cord(&(f.dir),wi.x,wi.y,wi.z);
			double z1 = intersiction(sphere,f.dir,f.orgi,light,&wi, 0xFF0000,-1);
			double z2 = intersiction(sphere2,f.dir,f.orgi,light,&wi, 0xFF00FF,z1);
			double z3 = intersiction(sphere3,f.dir,f.orgi,light,&wi, 0xFF00FF,z1);
			double z4 = intersiction(sphere4,f.dir,f.orgi,light,&wi, 0xFF00FF,z1);
			intersiction(sphere5,f.dir,f.orgi,light,&wi,0xFF00FF,z1);
			wi.y++;
		}
		wi.x++;
	}
	mlx_put_image_to_window(wi.mlx_ptr, wi.win_ptr, wi.img_ptr, 0, 0);
	mlx_loop(wi.mlx_ptr);
	return 0;
}

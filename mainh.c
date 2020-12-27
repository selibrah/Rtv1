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

void putimg(int x, int y, int color, t_win *wi)
{
	int i;

	i = 4 * x + y * wi->size_line;
	wi->line[i] = 0;
	wi->line[i++] = color >> 16;
	wi->line[i++] = color >> 8;
	wi->line[i++] = color;
}
void cord(t_vec *sphere, int x, int y, int z)
{
	sphere->x = x;
	sphere->y = y;
	sphere->z = z;
}

int main()
{
	t_win wi;

	t_vec sphere;
	t_vec sphere2;
	t_vec plan;
	t_ray f;
	cord(&(f.dir),500,500,500);
	cord(&(f.orgi),500,500,-500);
	cord(&plan,500,500,500);
	cord(&sphere, 400, 500, 500);
	cord(&sphere2, 500, 500, 500);
	double a;
	double b;
	double b2;
	double c;
	double c2;
	double t1 = 0;
	double t21 = 0;
	double z1 = 0;
	double z2 = 0;
	double t2 = 0;
	double t22 = 0;
	double z12 = 0;
	double z22 = 0;
	wi.winx = 1000;
	wi.winy = 1000;
	wi.mlx_ptr = mlx_init();
	wi.win_ptr = mlx_new_window(wi.mlx_ptr, 1000, 1000, "Best Rtv1 Ever");
	wi.img_ptr = mlx_new_image(wi.mlx_ptr, wi.winx, wi.winy);
	wi.line = mlx_get_data_addr(wi.img_ptr, &wi.bpp, &wi.size_line, &wi.endian);

	wi.x = 0;
	wi.y = 0;
	wi.z = 500;
	int rp = 100;
	int rp2 = 100;
	 cord(&(f.dir),wi.x,wi.y,0);
	// 	a = (f.dir.x - f.orgi.x)*(f.dir.x - f.orgi.x) + (f.dir.y - f.orgi.y)*(f.dir.y - f.orgi.y) + (f.dir.z - f.orgi.z)*(f.dir.z - f.orgi.z);
	// 	b = -2 *((f.dir.x - f.orgi.x)*(sphere.x - f.orgi.x) + (f.dir.y - f.orgi.y)*(sphere.y - f.orgi.y) + (sphere.z - f.orgi.z)*(f.dir.z - f.orgi.z));
	// 		c = (sphere.x - f.orgi.x)*(sphere.x - f.orgi.x) + (sphere.y - f.orgi.y) * (sphere.y - f.orgi.y) + (sphere.z - f.orgi.z) * (sphere.z - f.orgi.z) - rp;
	// 		t1 = (double)(-b + sqrt(b*b - 4 * a * c))/(2 * a);
	// 		t2 = (double)(-b - sqrt(b*b - 4 * a * c))/(2 * a);
	// 		printf("(%d,%d,%d) ---> t1 == %f || t2 %f\n",wi.x,wi.y,0,t1,t2);
	while (wi.x < 1000)
	{
		wi.y = 0;
		while (wi.y < 1000)
		{
			cord(&(f.dir),wi.x,wi.y,wi.z);
			//b = (wi.x - sphere.x) * (wi.x - sphere.x) + (wi.y - sphere.y) * (wi.y - sphere.y) + (wi.z - sphere.z) * (wi.z - sphere.z);
			//b2 = (wi.x - sphere2.x) * (wi.x - sphere2.x) + (wi.y - sphere2.y) * (wi.y - sphere2.y) + (wi.z - sphere2.z) * (wi.z - sphere2.z);
			a = (f.dir.x - f.orgi.x)*(f.dir.x - f.orgi.x) + (f.dir.y - f.orgi.y)*(f.dir.y - f.orgi.y) + (f.dir.z - f.orgi.z)*(f.dir.z - f.orgi.z);
			b = 2 *((f.dir.x - f.orgi.x)*(sphere.x - f.orgi.x) + (f.dir.y - f.orgi.y)*(sphere.y - f.orgi.y) + (sphere.z - f.orgi.z)*(f.dir.z - f.orgi.z));
			c = (sphere.x - f.orgi.x)*(sphere.x - f.orgi.x) + (sphere.y - f.orgi.y) * (sphere.y - f.orgi.y) + (sphere.z - f.orgi.z) * (sphere.z - f.orgi.z) - rp*rp;
			//b2 = -2 *((f.dir.x - f.orgi.x)*(sphere2.x - f.orgi.x) + (f.dir.y - f.orgi.y)*(sphere2.y - f.orgi.y) + (sphere2.z - f.orgi.z)*(f.dir.z - f.orgi.z));
			//c2 = (sphere2.x - f.orgi.x)*(sphere2.x - f.orgi.x) + (sphere2.y - f.orgi.y) * (sphere2.y - f.orgi.y) + (sphere2.z - f.orgi.z) * (sphere2.z - f.orgi.z) - rp2*rp2;
			t1 =(double) (-b + sqrt(b*b - 4 * a * c))/(2 * a);
			t2 =(double) (-b2 + sqrt(b2*b2 - 4 * a * c2))/(2 * a);
			//printf("t1 == %f || t2 == %f\n",t1,t2);
			z1 =-500 + 1000 * t1;
			z2 =-500 + 1000 * t2;
			// t2 =(double) (-b - sqrt(b*b - 4 * a * c))/(2 * a);
			//wi.r = (wi.x - 500) * (wi.x - 500)  + (wi.y - 500) *(wi.y - 500);
			if ((b * b - 4 * a * c > 0  ))
			{
				putimg(wi.x ,wi.y,0xFFFFFF ,&wi);
			}
			if ((b2 * b2 - 4 * a * c2 > 0 ) )
				putimg(wi.x ,wi.y,0xFF0000,&wi);
			wi.y++;
		}
		wi.x++;
	}
	mlx_put_image_to_window(wi.mlx_ptr, wi.win_ptr, wi.img_ptr, 0, 0);
	mlx_loop(wi.mlx_ptr);
	return 0;
}

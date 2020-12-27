/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selibrah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:15:28 by selibrah          #+#    #+#             */
/*   Updated: 2020/01/09 01:30:50 by selibrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H

# include "mlx/mlx.h"

typedef struct			s_win
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	char				*imgstr;
	char				*line;
	int					bpp;
	int					size_line;
	int					endian;
	int					x;
	int					y;
	int 				z;
	int					winx;
	int					winy;
	double					r;
}						t_win;

typedef struct			s_vec
{
	double x;
	double y;
	double z;
}						t_vec;

typedef struct			s_color
{
	char x;
	char y;
	char z;
}						t_color;

typedef struct			s_sphere
{
	t_vec cord;
	double r;
}						t_sphere;

typedef struct			s_ray
{
	t_vec dir;
	t_vec orgi;
}						t_ray;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlasrite <mlasrite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:56:22 by mlasrite          #+#    #+#             */
/*   Updated: 2020/01/19 13:19:46 by mlasrite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calcul_wall_height(float x, float y, t_data *ptr)
{
	float	ph;
	float	pv;
	float	distanceproj;

	horizontale(x, y, ptr);
	verticale(x, y, ptr);
	ph = sqrt(pow((x - ptr->hx), 2) + pow((y - ptr->hy), 2));
	pv = sqrt(pow((x - ptr->vx), 2) + pow((y - ptr->vy), 2));
	ptr->txt->textur_x = \
	(ph < pv) ? findmod(ptr->hx, ptr->tile_size)\
	: findmod(ptr->vy, ptr->tile_size);
	help_calcul_wall_h(ph, pv, ptr);
	ptr->rayon_distance = (ph < pv) ? ph : pv;
	distanceproj = (ptr->cfg->reso_x / 2) / tan(degtorad(30));
	ptr->correct_distance = ptr->rayon_distance *\
	cos(degtorad(ptr->angle_a - ptr->p_angle));
	ptr->mur = ptr->tile_size / ptr->correct_distance * distanceproj;
}

void	help_calcul_wall_h(float ph, float pv, t_data *ptr)
{
	int		i;
	float	res;

	res = findmod(ptr->angle_a, 360);
	if (ph < pv)
	{
		if (res >= 0 && res <= 180)
			ptr->txt->tab_colors = (int *)\
			mlx_get_data_addr(ptr->txt->img_2p, &i, &i, &i);
		else
			ptr->txt->tab_colors = (int *)\
			mlx_get_data_addr(ptr->txt->img_2, &i, &i, &i);
	}
	else
	{
		if (res >= 90 && res <= 270)
			ptr->txt->tab_colors = (int *)\
			mlx_get_data_addr(ptr->txt->img_1p, &i, &i, &i);
		else
			ptr->txt->tab_colors = (int *)\
			mlx_get_data_addr(ptr->txt->img_1, &i, &i, &i);
	}
}

float	degtorad(float deg)
{
	float rad;

	rad = M_PI / 180 * deg;
	return (rad);
}

float	findmod(float a, float b)
{
	float mod;

	if (a < 0)
		mod = -a;
	else
		mod = a;
	if (b < 0)
		b = -b;
	while (mod >= b)
		mod = mod - b;
	if (a < 0)
		return (-mod);
	return (mod);
}

void	shadow(t_data *ptr)
{
	int r;
	int g;
	int b;

	r = ptr->color / pow(256, 2);
	g = (ptr->color / 256) % 256;
	b = ptr->color % 256;
	if ((ptr->correct_distance / 180) > 1)
	{
		r /= (ptr->correct_distance / 180);
		g /= (ptr->correct_distance / 180);
		b /= (ptr->correct_distance / 180);
	}
	ptr->color = pow(2, 16) * r + pow(2, 8) * g + b;
}

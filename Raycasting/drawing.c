/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlasrite <mlasrite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:37:09 by mlasrite          #+#    #+#             */
/*   Updated: 2020/01/19 13:33:48 by mlasrite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_everything(float x, float y, t_data *ptr)
{
	float	y2;
	float	save;
	float	yy;
	float	factor;

	yy = 0;
	save = ptr->angle_a;
	ptr->walls = malloc(sizeof(float) * ptr->cfg->reso_x + 1);
	ptr->correct_dis = malloc(sizeof(float) * ptr->cfg->reso_x + 1);
	ptr->correct_dis[(int)ptr->cfg->reso_x] = '\0';
	ptr->angle_a = ptr->p_angle + 30;
	while (++ptr->draw_x < ptr->cfg->reso_x)
	{
		ptr->angle_a = findmod(ptr->angle_a, 360);
		calcul_wall_height(x, y, ptr);
		ptr->correct_dis[ptr->draw_x] = ptr->correct_distance;
		ptr->walls[ptr->draw_x] = ptr->mur;
		y2 = (ptr->cfg->reso_y / 2) - (ptr->mur / 2);
		factor = ptr->txt->textur_width / ptr->mur;
		help_draw_everything(y2, yy, ptr, factor);
		yy = 0;
		ptr->angle_a -= 60 / ptr->cfg->reso_x;
	}
	ptr->angle_a = save;
	next(ptr);
}

void	next(t_data *ptr)
{
	floor_draw(ptr);
	ceill_draw(ptr);
	sprite_info(ptr);
	free(ptr->walls);
	free(ptr->correct_dis);
}

void	help_draw_everything(float y2, float yy, t_data *ptr, float factor)
{
	while (ptr->mur > 0)
	{
		if (yy < ptr->txt->textur_height)
			ptr->color = ptr->txt->tab_colors[(int)yy \
			* ptr->txt->textur_width + ptr->txt->textur_x];
		shadow(ptr);
		if ((ptr->draw_x >= 0 && ptr->draw_x < ptr->cfg->reso_x)\
			&& (y2 >= 0 && y2 < ptr->cfg->reso_y))
			put_pixel(ptr->draw_x, y2, ptr->color, ptr);
		y2 += 1;
		yy += factor;
		ptr->mur -= 1;
	}
}

void	floor_draw(t_data *ptr)
{
	int		x;
	int		i;
	float	depart;

	x = 0;
	while (x < ptr->cfg->reso_x)
	{
		depart = (ptr->cfg->reso_y / 2) - (ptr->walls[x] / 2);
		i = depart + ptr->walls[x];
		while (i < ptr->cfg->reso_y)
		{
			put_pixel(x, i, ptr->txt->floor_color, ptr);
			i += 1;
		}
		x += 1;
	}
}

void	ceill_draw(t_data *ptr)
{
	int		x;
	int		i;
	float	depart;

	x = 0;
	i = 0;
	while (x < ptr->cfg->reso_x)
	{
		depart = (ptr->cfg->reso_y / 2) - (ptr->walls[x] / 2);
		while (i < depart)
		{
			put_pixel(x, i, ptr->txt->ceill_color, ptr);
			i += 1;
		}
		i = 0;
		x += 1;
	}
}

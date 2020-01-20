/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hori_verti.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlasrite <mlasrite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:45:46 by mlasrite          #+#    #+#             */
/*   Updated: 2020/01/19 13:33:53 by mlasrite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	horizontale(float x, float y, t_data *ptr)
{
	float res;
	float x_step;
	float y_step;

	res = findmod(ptr->angle_a, 360);
	if (res >= 0 && res <= 180)
	{
		ptr->hy = floor(y / ptr->tile_size) * ptr->tile_size;
		ptr->hx = x + (y - ptr->hy) / tan(degtorad(ptr->angle_a));
		y_step = -ptr->tile_size;
	}
	else
	{
		ptr->hy = floor(y / ptr->tile_size) * ptr->tile_size + ptr->tile_size;
		ptr->hx = x + (y - ptr->hy) / tan(degtorad(ptr->angle_a));
		y_step = ptr->tile_size;
	}
	x_step = ptr->tile_size / tan(degtorad(ptr->angle_a));
	x_step *= (res > 90 && res < 270 && x_step > 0) ? -1 : 1;
	x_step *= (!(res > 90 && res < 270) && x_step < 0) ? -1 : 1;
	next_horizontale(res, x_step, y_step, ptr);
}

void	next_horizontale(float res, float x_step, float y_step, t_data *ptr)
{
	int	a;
	int b;

	a = floor(ptr->hx / ptr->tile_size);
	b = (res >= 0 && res <= 180)
		? floor(ptr->hy / ptr->tile_size) - 1
		: floor(ptr->hy / ptr->tile_size);
	if (a >= 0 && a < ptr->cfg->colones && b >= 0 && b < ptr->cfg->lignes)
	{
		while (ptr->cfg->map[b][a] != '1')
		{
			ptr->hy = ptr->hy + y_step;
			ptr->hx = ptr->hx + x_step;
			a = floor(ptr->hx / ptr->tile_size);
			b = (res >= 0 && res <= 180)
				? floor(ptr->hy / ptr->tile_size) - 1
				: floor(ptr->hy / ptr->tile_size);
			if (a < 0 || a > ptr->cfg->colones || b < 0 ||\
			b >= ptr->cfg->lignes)
				break ;
		}
	}
}

void	verticale(float x, float y, t_data *ptr)
{
	float	res;
	float	x_step;
	float	y_step;

	res = findmod(ptr->angle_a, 360);
	if (res >= 90 && res <= 270)
	{
		ptr->vx = floor(x / ptr->tile_size) * ptr->tile_size;
		ptr->vy = y + (x - ptr->vx) * tan(degtorad(ptr->angle_a));
		x_step = -ptr->tile_size;
	}
	else
	{
		ptr->vx = floor(x / ptr->tile_size) * ptr->tile_size + ptr->tile_size;
		ptr->vy = y + (x - ptr->vx) * tan(degtorad(ptr->angle_a));
		x_step = ptr->tile_size;
	}
	y_step = x_step * tan(degtorad(ptr->angle_a));
	next_verticale(res, x_step, y_step, ptr);
}

void	next_verticale(float res, float x_step, float y_step, t_data *ptr)
{
	int a;
	int b;

	a = (res >= 90 && res <= 270)
		? ptr->vx / ptr->tile_size - 1
		: ptr->vx / ptr->tile_size;
	b = ptr->vy / ptr->tile_size;
	if (a >= 0 && a < ptr->cfg->colones && b >= 0 && b < ptr->cfg->lignes)
	{
		while (ptr->cfg->map[b][a] != '1')
		{
			ptr->vy = ptr->vy - y_step;
			ptr->vx = ptr->vx + x_step;
			a = (res >= 90 && res <= 270)
				? ptr->vx / ptr->tile_size - 1
				: ptr->vx / ptr->tile_size;
			b = ptr->vy / ptr->tile_size;
			if (a < 0 || a > ptr->cfg->colones || b < 0 ||\
			b >= ptr->cfg->lignes)
				break ;
		}
	}
}

void	put_pixel(int x, int y, int color, t_data *ptr)
{
	int		bpp;
	int		size_line;
	int		end;
	int		*img_data;

	img_data = (int *)mlx_get_data_addr(ptr->img_ptr, &bpp, &size_line, &end);
	if (x >= 0 && x < ptr->cfg->reso_x && y >= 0 && y < ptr->cfg->reso_y)
		img_data[x + size_line / 4 * y] = color;
}

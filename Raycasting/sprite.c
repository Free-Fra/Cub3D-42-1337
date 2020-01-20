/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlasrite <mlasrite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 15:43:38 by mlasrite          #+#    #+#             */
/*   Updated: 2020/01/18 15:10:26 by mlasrite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	sprite_info(t_data *ptr)
{
	int		i;
	int		count;
	t_spr	tmp;

	i = 0;
	count = count_objets(ptr);
	while (i < count)
	{
		ptr->list[i].di = sqrt(pow((ptr->list[i].s_x - ptr->player_x),\
		2) + pow((ptr->list[i].s_y - ptr->player_y), 2));
		i += 1;
	}
	i = 1;
	while (i < count)
	{
		if (ptr->list[i].di > ptr->list[i - 1].di)
		{
			tmp = ptr->list[i];
			ptr->list[i] = ptr->list[i - 1];
			ptr->list[i - 1] = tmp;
			i = 0;
		}
		i += 1;
	}
	spriting(count, ptr);
}

void	spriting(int count, t_data *ptr)
{
	int i;

	i = 0;
	while (i < count)
	{
		ptr->obj->dis_p_s = ptr->list[i].di;
		ptr->obj->sp_angle = -1 * atan2(ptr->list[i].s_y - \
		ptr->player_y, ptr->list[i].s_x - ptr->player_x);
		while (ptr->obj->sp_angle - degtorad(ptr->p_angle) > M_PI)
			ptr->obj->sp_angle -= 2 * M_PI;
		while (ptr->obj->sp_angle - degtorad(ptr->p_angle) < -M_PI)
			ptr->obj->sp_angle += 2 * M_PI;
		ptr->obj->new_sp = degtorad(ptr->p_angle) - ptr->obj->sp_angle;
		if (ptr->cfg->reso_y > ptr->cfg->reso_x)
			ptr->obj->sp_size = (ptr->cfg->reso_y / \
			ptr->obj->dis_p_s) * ptr->tile_size;
		else
			ptr->obj->sp_size = (ptr->cfg->reso_x / \
			ptr->obj->dis_p_s) * ptr->tile_size;
		ptr->obj->first_y = (ptr->cfg->reso_y / 2) - (ptr->obj->sp_size / 2);
		ptr->obj->first_x = (ptr->obj->new_sp * ptr->cfg->reso_x / \
		degtorad(60)) + ((ptr->cfg->reso_x / 2) - (ptr->obj->sp_size / 2));
		draw_sprite(ptr);
		i += 1;
	}
}

void	draw_sprite(t_data *ptr)
{
	int i;
	int j;
	int	*tab;
	int	r;

	i = -1;
	tab = (int *)mlx_get_data_addr(ptr->txt->img_s, &r, &r, &r);
	while (++i < ptr->obj->sp_size - 1)
	{
		if (ptr->obj->first_x + i < 0 || \
		ptr->obj->first_x + i > ptr->cfg->reso_x)
			continue;
		if (diff_dis(i, ptr))
			continue;
		j = -1;
		while (++j < ptr->obj->sp_size - 1)
		{
			if (ptr->obj->first_y + j < 0 ||\
			ptr->obj->first_y + j > ptr->cfg->reso_y)
				continue;
			helper(i, j, ptr, tab);
		}
	}
}

void	helper(int i, int j, t_data *ptr, int *tab)
{
	ptr->obj->sp_color = tab[((int)ptr->obj->s_width *\
	(j * (int)ptr->obj->s_height / (int)ptr->obj->sp_size))\
	+ (i * (int)ptr->obj->s_width / (int)ptr->obj->sp_size)];
	if (ptr->obj->sp_color != 0)
		put_pixel(ptr->obj->first_x + i, ptr->obj->first_y\
		+ j, ptr->obj->sp_color, ptr);
}

int		diff_dis(int i, t_data *ptr)
{
	float dist_wall;
	float sprite_dis;

	dist_wall = ptr->correct_dis[(int)ptr->obj->first_x + i];
	sprite_dis = ptr->obj->dis_p_s;
	if ((dist_wall < sprite_dis) && (sprite_dis - dist_wall > 40))
		return (1);
	return (0);
}

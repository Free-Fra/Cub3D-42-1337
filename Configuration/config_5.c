/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlasrite <mlasrite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 13:41:40 by mlasrite          #+#    #+#             */
/*   Updated: 2020/01/20 00:09:07 by mlasrite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	help_help_reso(t_data *ptr)
{
	if (ptr->cfg->reso_x <= 0)
	{
		perror("Error\nRESOLUTION : X RESOLUTION IS NEGATIVE");
		exit(0);
	}
	if (ptr->cfg->reso_y <= 0)
	{
		perror("Error\nRESOLUTION : Y RESOLUTION IS NEGATIVE");
		exit(0);
	}
	if (ptr->cfg->reso_y >= 1440)
		ptr->cfg->reso_y = 1440;
	if (ptr->cfg->reso_x >= 2560)
		ptr->cfg->reso_x = 2560;
}

void	help_help_error2(int count)
{
	if (count == 0)
	{
		perror("Error\nMAP INCORRECT : THERE IS NO PLAYER");
		exit(0);
	}
}

void	help_manage_cfg(t_data *ptr, char *line)
{
	if (line[0] == 'S' && line[1] == ' ')
		manage_sprite(ptr, line);
	else if (line[0] == 'N' && line[1] == 'O')
		manage_north(ptr, line);
	else if (line[0] == 'S' && line[1] == 'O')
		manage_south(ptr, line);
	else if (line[0] == 'W' && line[1] == 'E')
		manage_west(ptr, line);
	else if (line[0] == 'E' && line[1] == 'A')
		manage_east(ptr, line);
	else if (line[0] == 'R')
		manage_reso(ptr, line);
	else if (line[0] == 'F')
	{
		ptr->sec->f += 1;
		ptr->error += 1;
		manage_floor_color(ptr, line);
	}
	else if (line[0] == 'C')
	{
		ptr->sec->c += 1;\
		ptr->error += 1;
		manage_ceill_color(ptr, line);
	}
}

void	help_manage_cfg2(t_data *ptr)
{
	if (ptr->sec->no >= 2 || ptr->sec->so >= 2 || ptr->sec->ea >= 2 ||\
		ptr->sec->we >= 2 || ptr->sec->s >= 2 || ptr->sec->c >= 2 ||\
		ptr->sec->f >= 2 || ptr->sec->r >= 2 || ptr->sec->map >= 2)
	{
		perror("Error\nDUPLICATION !!!!");
		exit(0);
	}
	if (ptr->error != 8)
	{
		perror("Error\n");
		exit(0);
	}
}

void	inis(t_data *ptr)
{
	ptr->sec->we = 0;
	ptr->sec->no = 0;
	ptr->sec->so = 0;
	ptr->sec->ea = 0;
	ptr->sec->s = 0;
	ptr->sec->c = 0;
	ptr->sec->f = 0;
	ptr->sec->map = 0;
	ptr->sec->r = 0;
}

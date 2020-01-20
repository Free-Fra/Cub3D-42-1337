/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlasrite <mlasrite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 14:14:04 by mlasrite          #+#    #+#             */
/*   Updated: 2020/01/20 00:14:12 by mlasrite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	manage_reso(t_data *ptr, char *str)
{
	char	**d;
	int		i;

	i = 0;
	ptr->sec->r += 1;
	ptr->error += 1;
	d = ft_split(str, ' ', ptr);
	while (d[i] != NULL)
		i += 1;
	if (i > 3)
	{
		perror("Error\nRESOLUTION : SOMETHING WRONG");
		exit(0);
	}
	i = -1;
	while (d[1][++i] != '\0')
	{
		if (d[1][i] < '0' || d[1][i] > '9')
		{
			perror("Error\nRESOLUTION : SOMETHING WRONG");
			freeyi(d);
			exit(0);
		}
	}
	help_reso(ptr, d);
}

void	help_reso(t_data *ptr, char **d)
{
	int i;

	i = -1;
	while (d[2][++i] != '\0')
	{
		if (d[2][i] < '0' || d[2][i] > '9')
		{
			perror("Error\nRESOLUTION : SOMETHING WRONG");
			freeyi(d);
			exit(0);
		}
	}
	ptr->cfg->reso_x = (float)ft_atoi(d[1]);
	ptr->cfg->reso_y = (float)ft_atoi(d[2]);
	freeyi(d);
	help_help_reso(ptr);
}

void	manage_ceill_color(t_data *ptr, char *line)
{
	char	**d;
	int		r;
	int		g;
	int		b;

	r = 0;
	d = ft_split(line + 2, ',', ptr);
	strange_letter(d);
	while (d[r] != NULL)
		r += 1;
	if (r > 3)
	{
		perror("Error\nCEILL COLOR : SOMETHING WRONG");
		exit(0);
	}
	r = ft_atoi(d[0]);
	g = ft_atoi(d[1]);
	b = ft_atoi(d[2]);
	freeyi(d);
	if (b < 0 || b > 255 || r < 0 || r > 255 || g < 0 || g > 255)
	{
		perror("Error\nCEILL COLOR : SOMETHING WRONG");
		exit(0);
	}
	ptr->txt->ceill_color = pow(2, 16) * r + pow(2, 8) * g + b;
}

void	manage_floor_color(t_data *ptr, char *line)
{
	char	**d;
	int		r;
	int		g;
	int		b;

	r = 0;
	d = ft_split(line + 2, ',', ptr);
	strange_letter(d);
	while (d[r] != NULL)
		r += 1;
	if (r > 3)
	{
		perror("Error\nFLOOR COLOR : SOMETHING WRONG");
		exit(0);
	}
	r = ft_atoi(d[0]);
	g = ft_atoi(d[1]);
	b = ft_atoi(d[2]);
	freeyi(d);
	if (b < 0 || b > 255 || r < 0 || r > 255 || g < 0 || g > 255)
	{
		perror("Error\nFLOOR COLOR : SOMETHING WRONG");
		exit(0);
	}
	ptr->txt->floor_color = pow(2, 16) * r + pow(2, 8) * g + b;
}

void	strange_letter(char **d)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (d[i] != NULL)
	{
		j = 0;
		while (d[i][j] != '\0')
		{
			if (d[i][j] < '0' || d[i][j] > '9')
			{
				perror("Error\nCOLOR : STRANGE LETTER");
				exit(0);
			}
			j += 1;
		}
		i += 1;
	}
}

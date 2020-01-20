/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlasrite <mlasrite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 12:01:59 by mlasrite          #+#    #+#             */
/*   Updated: 2020/01/20 00:04:22 by mlasrite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	manage_north(t_data *ptr, char *line)
{
	char	**d;
	int		i;

	i = 0;
	ptr->sec->no += 1;
	ptr->error += 1;
	d = NULL;
	d = ft_split(line, ' ', ptr);
	while (d[i] != NULL)
		i += 1;
	if (i > 2)
	{
		perror("Error\nNORTH TEXTURE : SOMETHING WRONG");
		exit(0);
	}
	ptr->txt->img_1p = mlx_xpm_file_to_image(ptr->mlx_ptr, \
	d[1], &ptr->txt->textur_width, &ptr->txt->textur_height);
	freeyi(d);
	if (ptr->txt->img_1p == NULL)
	{
		perror("Error\nNORTH TEXTURE : INVALIDE PATH");
		exit(0);
	}
}

void	manage_south(t_data *ptr, char *line)
{
	char	**d;
	int		i;

	i = 0;
	ptr->sec->so += 1;
	ptr->error += 1;
	d = NULL;
	d = ft_split(line, ' ', ptr);
	while (d[i] != NULL)
		i += 1;
	if (i > 2)
	{
		perror("Error\nSOUTH TEXTURE : SOMETHING WRONG");
		exit(0);
	}
	ptr->txt->img_1 = mlx_xpm_file_to_image(ptr->mlx_ptr, \
	d[1], &ptr->txt->textur_width, &ptr->txt->textur_height);
	freeyi(d);
	if (ptr->txt->img_1 == NULL)
	{
		perror("Error\nSOUTH TEXTURE : INVALIDE PATH");
		exit(0);
	}
}

void	manage_west(t_data *ptr, char *line)
{
	char	**d;
	int		i;

	i = 0;
	ptr->sec->we += 1;
	ptr->error += 1;
	d = NULL;
	d = ft_split(line, ' ', ptr);
	while (d[i] != NULL)
		i += 1;
	if (i > 2)
	{
		perror("Error\nWEST TEXTURE : SOMETHING WRONG");
		exit(0);
	}
	ptr->txt->img_2 = mlx_xpm_file_to_image(ptr->mlx_ptr, \
	d[1], &ptr->txt->textur_width, &ptr->txt->textur_height);
	freeyi(d);
	if (ptr->txt->img_2 == NULL)
	{
		perror("Error\nWEST TEXTURE : INVALIDE PATH");
		exit(0);
	}
}

void	manage_east(t_data *ptr, char *line)
{
	char	**d;
	int		i;

	i = 0;
	ptr->sec->ea += 1;
	ptr->error += 1;
	d = NULL;
	d = ft_split(line, ' ', ptr);
	while (d[i] != NULL)
		i += 1;
	if (i > 2)
	{
		perror("Error\nEAST TEXTURE : SOMETHING WRONG");
		exit(0);
	}
	ptr->txt->img_2p = mlx_xpm_file_to_image(ptr->mlx_ptr, \
	d[1], &ptr->txt->textur_width, &ptr->txt->textur_height);
	freeyi(d);
	if (ptr->txt->img_2p == NULL)
	{
		perror("Error\nEAST TEXTURE : INVALIDE PATH");
		exit(0);
	}
}

void	manage_sprite(t_data *ptr, char *line)
{
	char	**d;
	int		i;

	i = 0;
	ptr->sec->s += 1;
	ptr->error += 1;
	d = NULL;
	d = ft_split(line, ' ', ptr);
	while (d[i] != NULL)
		i += 1;
	if (i > 2)
	{
		perror("Error\nSPRITE : SOMETHING WRONG");
		exit(0);
	}
	ptr->txt->img_s = mlx_xpm_file_to_image(ptr->mlx_ptr, \
	d[1], &ptr->obj->s_width, &ptr->obj->s_height);
	freeyi(d);
	if (ptr->txt->img_s == NULL)
	{
		perror("Error\nSPRITE TEXTURE : INVALIDE PATH");
		exit(0);
	}
}

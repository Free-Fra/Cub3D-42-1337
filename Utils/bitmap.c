/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlasrite <mlasrite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 14:20:33 by mlasrite          #+#    #+#             */
/*   Updated: 2020/01/20 14:22:43 by mlasrite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_bitmap(t_data *ptr)
{
	unsigned char	header[54];
	int				row;
	int				col;
	int				*tab;
	int				x;

	tab = (int *)mlx_get_data_addr(ptr->img_ptr, &col, &col, &col);
	help_bitmap(ptr);
	ft_header(header);
	row = ptr->bmp->height - 1;
	col = 0;
	x = 0;
	ft_memcpy(header, "BM", 2);
	ft_memcpy(header + 2, &ptr->bmp->filesize, 4);
	ft_memcpy(header + 10, &ptr->bmp->bfoffbits, 4);
	ft_memcpy(header + 14, &ptr->bmp->bisize, 4);
	ft_memcpy(header + 18, &ptr->bmp->width, 4);
	ft_memcpy(header + 22, &ptr->bmp->height, 4);
	ft_memcpy(header + 26, &ptr->bmp->biplanes, 2);
	ft_memcpy(header + 28, &ptr->bmp->bitcount, 2);
	ft_memcpy(header + 34, &ptr->bmp->imagesize, 4);
	help_bitmap2(ptr, row, col, tab);
	create_it(header, ptr->bmp->buf, ptr->bmp->imagesize);
	free(ptr->bmp->buf);
	exit(0);
}

void	help_bitmap(t_data *ptr)
{
	ptr->bmp->width = ptr->cfg->reso_x;
	ptr->bmp->height = ptr->cfg->reso_y;
	ptr->bmp->bitcount = 24;
	ptr->bmp->width_in_bytes = ((ptr->bmp->width *\
	ptr->bmp->bitcount + 31) / 32) * 4;
	ptr->bmp->imagesize = ptr->bmp->width_in_bytes * ptr->bmp->height;
	ptr->bmp->bisize = 40;
	ptr->bmp->bfoffbits = 54;
	ptr->bmp->filesize = 54 + ptr->bmp->imagesize;
	ptr->bmp->biplanes = 1;
	ptr->bmp->buf = malloc(ptr->bmp->imagesize);
}

void	help_bitmap2(t_data *ptr, int row, int col, int *tab)
{
	int color;
	int x;

	x = 0;
	while (row > 0)
	{
		col = 0;
		while (col < ptr->bmp->width)
		{
			color = tab[col + x * (int)ptr->cfg->reso_x];
			ptr->bmp->r = color / pow(256, 2);
			ptr->bmp->g = (color / 256) % 256;
			ptr->bmp->b = color % 256;
			ptr->bmp->buf[row * ptr->bmp->width_in_bytes + col * 3 + 0] =\
			ptr->bmp->b;
			ptr->bmp->buf[row * ptr->bmp->width_in_bytes + col * 3 + 1] =\
			ptr->bmp->g;
			ptr->bmp->buf[row * ptr->bmp->width_in_bytes + col * 3 + 2] =\
			ptr->bmp->r;
			col++;
		}
		x += 1;
		row--;
	}
}

void	create_it(unsigned char *header, unsigned char *buf, size_t imagesize)
{
	int fd;

	fd = open("screen.bmp", O_CREAT | O_TRUNC | O_WRONLY | O_APPEND, 500);
	write(fd, header, 54);
	write(fd, (char *)buf, imagesize);
	close(fd);
}

void	ft_header(unsigned char *header)
{
	int	i;

	i = 55;
	while (--i >= 0)
		header[i] = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlasrite <mlasrite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 21:21:59 by mlasrite          #+#    #+#             */
/*   Updated: 2020/01/20 14:19:30 by mlasrite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define BUFFER_SIZE 1000000
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct		s_texture
{
	void			*img_1;
	void			*img_1p;
	void			*img_2;
	void			*img_2p;
	void			*img_s;
	int				*tab_colors;
	int				textur_width;
	int				textur_height;
	int				textur_x;
	int				ceill_color;
	int				floor_color;
}					t_img;

typedef struct		s_config
{
	float			reso_x;
	float			reso_y;
	char			**map;
	int				colones;
	int				lignes;
	char			*config;
}					t_cfg;

typedef struct		s_sprite
{
	float			sp_angle;
	float			new_sp;
	float			sp_size;
	float			dis_p_s;
	float			first_x;
	float			first_y;
	int				s_height;
	int				s_width;
	int				sp_color;
}					t_sp;

typedef struct		s_spr
{
	float			di;
	float			s_x;
	float			s_y;
}					t_spr;

typedef struct		s_key
{
	int				up;
	int				down;
	int				right;
	int				left;
}					t_key;

typedef	struct		s_check
{
	int				no;
	int				so;
	int				ea;
	int				we;
	int				s;
	int				c;
	int				f;
	int				r;
	int				map;
}					t_check;

typedef struct		s_bitmap
{
	int				width;
	int				height;
	int				width_in_bytes;
	size_t			bitcount;
	size_t			imagesize;
	size_t			bisize;
	size_t			bfoffbits;
	size_t			filesize;
	size_t			biplanes;
	int				r;
	int				g;
	int				b;
	unsigned char	*buf;
}					t_bmp;

typedef	struct		s_window
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	float			rayon_distance;
	float			correct_distance;
	float			player_x;
	float			player_y;
	float			p_angle;
	float			angle_a;
	float			hx;
	float			hy;
	float			vx;
	float			vy;
	float			mur;
	float			*walls;
	float			tile_size;
	char			**deux;
	int				color;
	int				draw_x;
	float			*correct_dis;
	int				error;
	t_img			*txt;
	t_cfg			*cfg;
	t_sp			*obj;
	t_spr			*list;
	t_key			*key;
	t_check			*sec;
	t_bmp			*bmp;
}					t_data;

/*
** ----------------------[CUB3D.C]---------------------->
*/

void				help_main_3(t_data *ptr, char	*argv);
void				help_main(t_data *ptr, char *argv);
int					keys_press(int key, void *param);
int					keys_release(int key, void *param);

/*
** ----------------------[CUB3D_2.C]---------------------->
*/

void				create_it(unsigned char *header,\
					unsigned char *buf, size_t imagesize);
void				ft_bitmap(t_data *ptr);
void				ft_header(unsigned char *header);
void				help_bitmap(t_data *ptr);
void				help_bitmap2(t_data *ptr, int row, int col, int *tab);

/*
** ----------------------[CUB3D_3.C]---------------------->
*/

void				*ft_memcpy(void *dest, void *src, size_t n);
int					exiter(int key, void *param);
int					check_argv(char *str);
int					mooving(t_data *ptr);
void				help_mooving(t_data *ptr);
/*
** ----------------------[/RAYCASTING]---------------------->
*/

void				draw_everything(float x, float y, t_data *ptr);
void				help_draw_everything(float y2, float yy,\
					t_data *ptr, float factor);
void				floor_draw(t_data *ptr);
void				ceill_draw(t_data *ptr);
void				next(t_data *ptr);
void				sprite_info(t_data *ptr);
void				draw_sprite(t_data *ptr);
int					diff_dis(int i, t_data *ptr);
void				spriting(int count, t_data *ptr);
void				helper(int i, int j, t_data *ptr, int *tab);
void				horizontale(float x, float y, t_data *ptr);
void				next_horizontale(float res, float x_step,\
					float y_step, t_data *ptr);
void				verticale(float x, float y, t_data *ptr);
void				next_verticale(float res, float x_step,\
					float y_step, t_data *ptr);
void				put_pixel(int x, int y, int color, t_data *ptr);
void				calcul_wall_height(float x, float y, t_data *ptr);
void				help_calcul_wall_h(float ph, float pv, t_data *ptr);
float				findmod(float a, float b);
float				degtorad(float deg);
void				shadow(t_data *ptr);

/*
** ----------------------[/CONFIGURATION]---------------------->
*/

void				manage_config(t_data *ptr);
void				manage_cfg(t_data *ptr);
void				every_lenth(t_data *ptr);
char				*fill_line(char *line);
void				fill_map(t_data *ptr, char *line, int fd);
void				manage_reso(t_data *ptr, char *str);
void				help_reso(t_data *ptr, char **d);
void				manage_floor_color(t_data *ptr, char *line);
void				manage_ceill_color(t_data *ptr, char *line);
void				strange_letter(char	**d);
void				manage_north(t_data *ptr, char *line);
void				manage_south(t_data *ptr, char *line);
void				manage_west(t_data *ptr, char *line);
void				manage_east(t_data *ptr, char *line);
void				manage_sprite(t_data *ptr, char *line);
void				freeyi(char	**d);
void				wall_error(t_data *ptr);
void				wall_error2(t_data *ptr);
void				help_error2(t_data *ptr);
void				help_wall_error(t_data *ptr);
void				help_help_reso(t_data *ptr);
void				help_help_error2(int count);
void				help_manage_cfg(t_data *ptr, char *line);
void				help_manage_cfg2(t_data *ptr);
void				inis(t_data *ptr);

/*
** ------------------------[/UTILS]-------------------------->
*/

int					get_next_line(int fd, char **line);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlen(const char *s);
void				*ft_calloc(size_t count, size_t size);
char				**ft_split(char const *s, char c, t_data *ptr);
void				get_info_sprite(t_data *ptr);
int					count_objets(t_data *ptr);
void				get_info(t_data *ptr);
int					check_wall_up(t_data *ptr);
int					check_wall_down(t_data *ptr);
void				get_info_2(int i, int j, t_data *ptr);
int					ft_atoi(char *str);
void				initialize(t_data *ptr);
void				clear(t_data *ptr);

#endif

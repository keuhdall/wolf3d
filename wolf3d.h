/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 01:19:41 by lmarques          #+#    #+#             */
/*   Updated: 2017/01/07 16:26:49 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <math.h>
# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include "./libft/get_next_line.h"

# define W_WIDTH 800
# define W_HEIGHT 600
# define MIN_TEX 0
# define MAX_TEX 7
# define DEFAULT_TEX 0
# define FLOOR_TEX 1
# define CEILING_TEX 2
# define SPEED 20

typedef struct			s_point
{
	int					x;
	int					y;
	int					id;
}						t_point;

typedef struct			s_dpoint
{
	double				x;
	double				y;
}						t_dpoint;

typedef struct			s_key
{
	int					keycode;
	char				state;
}						t_key;

typedef struct			s_key_list
{
	t_key				key;
	struct s_key_list	*next;
}						t_key_list;

typedef struct			s_tex
{
	void				*tex;
	int					*data;
	int					width;
	int					height;
}						t_tex;

typedef struct			s_meta
{
	void				*ptr;
	void				*win;
	void				*img;
	int					*data;
	int					bpp;
	int					size_line;
	int					endian;
	t_tex				texture[10];
}						t_meta;

typedef struct			s_camera
{
	double				pos_x;
	t_dpoint			screen;
}						t_camera;

typedef struct			s_player
{
	t_key_list			*key_list;
	t_point				*tab;
	int					tab_len;
	t_meta				mlx;
	t_camera			c;
	t_dpoint			pos;
	t_point				map_pos;
	t_dpoint			ray_pos;
	t_dpoint			ray_dir;
	t_dpoint			p_dir;
	t_point				p_dir_sign;
	t_dpoint			dist_side;
	t_dpoint			diff_side;
	t_dpoint			floor_wall;
	double				ray_len;
	char				found_wall;
	char				found_wall_side;
	int					color;
	double				wall;
}						t_player;

int						ft_get_len(t_point *tab);
void					ft_init_struct(t_player *p, t_point *tab, int tab_len);
void					ft_clear_image(t_player *p);
int						ft_draw(t_player *p);
int						ft_rotate(int x, int y, t_player *p);
void					ft_move(t_player *p);
void					ft_strafe(t_player *p);
t_point					*ft_init_tab(char *name, int *err, int *len);
t_dpoint				ft_search_id(t_point *tab, int len, int id);
int						*ft_set_tmp(t_player *p);
void					ft_apply_texture(t_player *p, int count, t_point pt,
						int *tmp);
void					ft_calc_wall_dist(t_player *p);
void					ft_parse_keys_press(t_player *p, int keycode);
void					ft_parse_keys_release(t_player *p, int keycode);
char					ft_search_key(t_player *p, int keycode);
void					ft_set_floor(t_player *p);
void					ft_set_floor_to_buffer(t_player *p, int count,
						t_point pt);
void					ft_check_textures(t_player *p);
void					ft_check_map(t_player *p, int len);
void					ft_free_list(t_list **lst);
void					ft_set_val(t_point *tab, t_point count, int id);
void					ft_free_split(char **str);
int						*ft_create_tab(char **tmp, int *err);
int						ft_count_elem(char **tab);
void					ft_split_and_push(char **ln, int *e, char ***tmp,
						int **tmp3);
void					ft_free(char ***tmp, char **ln, int **tmp2);
void					ft_init_values(t_list **map, t_point *p, int **tmp2,
						char **ln);

#endif

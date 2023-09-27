/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:09:58 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/27 16:04:25 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17
# define WIDTH 1080
# define HEIGHT 720
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

typedef struct s_cord
{
	unsigned int	start_x;
	unsigned int	start_y;
	unsigned int	end_x;
	unsigned int	end_y;
	unsigned int	lig;
	unsigned int	col;
	char			*path_texture_no;
	char			*path_texture_so;
	char			*path_texture_we;
	char			*path_texture_ea;
	int				**f_colors;
	int				**c_colors;
	int	f_rgb;
	int	c_rgb;
	char			**ff_rgb;
	char			**cc_rgb;

}					t_cord;

typedef struct s_imag
{
	void			*img;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
	int				img_width;
	int				img_height;
}					t_imag;

typedef struct s_all
{
	void			*mlx;
	void			*win;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			ray_dirx;
	double			ray_diry;
	double			plane_x;
	double			plane_y;
	double			delta_distx;
	double			delta_disty;
	double			side_distx;
	double			side_disty;
	double			perp_wall_dist;
	double			wall_x;
	double			move_speed;
	double			rot_speed;
	int				map_x;
	int				map_y;
	int				side;
	int				tex_x;
	int				tex_width;
	int				tex_height;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				**textures;
	char			**c_rgb;
	char			**f_rgb;
	int				buf[HEIGHT + 1][WIDTH + 1];
	int				re_buf;
	t_cord			*cord;
	t_imag			img;

}					t_all;

typedef struct s_mlx
{
}					t_mlx;

typedef struct s_compass
{
	int				i;
	int				w;
	int				s;
	int				n;
	int				e;
}					t_compass;

typedef struct s_memory
{
	void			*add;
	struct s_memory	*next;
}					t_memory;

typedef struct s_data
{
	void			*img;
	char			*addr;
	char			**map;
	char			**map_ray;
	char			**map_compass;
	char			**map_wall;
	char			**map_for_games;
	t_compass		t_compass;
	t_cord			cord;
	t_memory		*d_mem;
	t_all			*all;
}					t_data;

int					ft_strlen(const char *s);

char				*ft_strdup(char *src, t_data *data);

size_t				ft_verification(int start, size_t len, char *s);

char				*ft_substr(char *s, unsigned int start, size_t len,
						t_data *data);

void				ft_scotch(char *dest, char *ss1, char *ss2);

char				*ft_strjoin(char *s1, char *s2, t_data *data);

char				*get_next_line(int fd, t_data *data);

char				**ft_split(char *s, char c, t_data *data);

int					verif_bords(char **map);

int					verif_map(char **map);
int					is_char_sett(char *map);
int					verif_open(char **argv);
int					ft_strcmp(const char *s1, const char *s2);
int					verif_namearg(int argc, char **argv);
int					verifall(char **map);
// PARSING
char				**get_map(char *line, int fd, int i, char **map,
						t_data *data);

void				ft_colle(char *dest, char *ss1, char *ss2);
char				*ft_strjoin_1(char *s1, char *s2, t_data *data);
int					verif_element(char **map);
void				*ft_memset(void *s, int c, size_t n);

size_t				ft_securite(size_t nmemb, size_t size);

void				*ft_calloc(size_t nmemb, size_t size, t_data *data);

void				*ft_memcpy(void *dst, const void *src, size_t n);
///////////////////////////////////////////////////////////////
///**********************get_maps**************************///
///////////////////////////////////////////////////////////////
int					get_different_maps(t_data *data, char **argv);

char				**get_map(char *line, int fd, int i, char **map,
						t_data *data);
char				**get_wall(char **map, int i, t_data *data);
void				*realloc_map(void *ptr, size_t ptrsize, size_t newsize,
						t_data *data);
char				**get_cord_map(char **map, t_data *data);

///////////////////////////////////////////////////////////////
///**********************classique_utils*******************///
///////////////////////////////////////////////////////////////
int					ft_atoi(const char *str);
unsigned int		ft_isnum(char *str);
unsigned int		count_char(char *str, char c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

///////////////////////////////////////////////////////////////
//***********************parsing_comppass******************///
///////////////////////////////////////////////////////////////
int					check_all_compass(t_data *data);
int					check_opening(char *path);
int					check_texture(t_data *data);
int					check_orientation(t_data *data, int *i);
void				stock_path(t_data *data, char *test);
char				*get_sub(t_data *data, int *i);

int					parsing_compass(t_data *data);
int					verif_elem_compass(t_data *data);
int					check_colors(t_data *data, int *i, int *j);
int					is_valid_colors(char *map, char c);
int					check_value_colors(t_data *data, int *i);
int					check_compass(t_data *data, int *i, int *j, char *test);

int					stock_colors_c_rgb(t_data *data, int *i);
int					stock_colors_f_rgb(t_data *data, int *i);
char	*ft_verif(char *str);
void	put_rgb_data(char c, char **rgb, t_data *data);



// int					colors_f_rgb(char **src, t_data *data);
////////////////////////////////////////////////////////////////
///**********************PARSING_MAP*************************///
////////////////////////////////////////////////////////////////

int					flood_recursively_to_border(char **map, int x, int y);
int					parsing_map_wall(t_data *data);
int					map_got_void(char **map);
int					get_map_for_game(char **map, t_data *data);
unsigned int		ft_len_dot(char *str, char c);
int					ft_count_games(char **map, int count_games);
int					get_grande(char **map);

char				**ft_copie_map(char **map, t_data *data);

char				**get_final_map(int grande, int count_line, char **map,
						t_data *data);

int					verif_element_of_map(char **map);

int					verif_larg(char **map);
int					verif_bords(char **map);

////////////////////////////////////////////////////////////////
///**********************flood_fill**************************///
////////////////////////////////////////////////////////////////
int					flood_recursively_to_border(char **map, int x, int y);
int					arounded_player(char **map, t_data *data);

////////////////////////////////////////////////////////////////
///**********************UTILS*******************************///
////////////////////////////////////////////////////////////////

char				*ft_strdup_for_ray(char *src, int grande, t_data *data);
unsigned int		first_char_line(char *map);
unsigned int		ft_count_this(char *map);
int					it_is_this_char(char *str, char c);
int					ft_space(char c);
int					ft_count_space(char *line);
void				ft_putstr_fd(int fd, char *s);

///////////////////////////////////////////////////////////////
///**********************garbage_collector******************///
///////////////////////////////////////////////////////////////
void				memory_check(void *add, t_data *data);

void				*ft_malloc(size_t size, t_data *data);

void				ft_free_this(void *add, t_data *data);

void				ft_free_all_garbage(t_data *data);

///////////////////////////////////////////////////////////////
///***************************mlx***************************///
///////////////////////////////////////////////////////////////

int					start_mlx(t_data *data);
int					set_images(t_data *data);
int					set_main_img(t_data *data);
int					malloc_textures(t_data *data);
int					malloc_texture2(t_data *data);
int					load_image(t_data *data, int *texture, char *path,
						t_imag *img);
void				calcul(t_data **data);
int					set_main_img(t_data *data);
int					main_loop(t_data **data);
int					get_player_pos(char **map, t_data *data);
void				init_dda(t_data *data, int *step_x, int *step_y);
void				init_dda_2(t_data *data, int *step_y);
void				dda(t_data *data, int step_x, int step_y);
void				draw_color_texture(t_data *data, int x, int tex_num,
						double step);
void				draw_utils(t_data *data, int step_x, int step_y);
int					get_num_tex(t_data *data);
void				draw(t_data *data);
int					key_press(int key, t_data **data);
int					key_press_suite(int key, t_data **data);
int					key_press_move_camera_right(int key, t_data **data);
int					key_press_move_camera_left(int key, t_data **data);
int					data_free(t_data *data);

// static void			set_west_or_east(char c, t_all *all);
// static void			set_south_or_north(char c, t_all *all);

// Get_map
// int				is_valid_path_exit(char **map, struct cord pos);
// struct cord		get_map_ligne(char **map, struct cord cord);

// struct cord		get_map_col(char **map, struct cord cord);

// struct cord		cord_start(char **map, struct cord cord);

// struct cord		cord_exit(char **map, struct cord cord);

// struct cord		cord_all(char **map, struct cord pos);
t_cord				cord_start(char **map, t_cord cord);
t_cord				cord_exit(char **map, t_cord cord);
t_cord				get_map_col(char **map, t_cord cord);
t_cord				get_map_ligne(char **map, t_cord cord);
int					is_valid_path_exit(char **map, t_cord pos);
t_cord				cord_all(char **map, t_cord pos);

// Exit funtion
void				ft_free_all(t_data *img);
void				ft_free(char **map);
void				quit_esc(t_data *img);
void				free_images(t_data *img);
void				ft_game_over(t_data *img);

//////////////////////////////////////////////////
int					verif_co(char **map, t_cord pos);
void				put_image(t_data *img);

void				set_display(t_data *img);
int					display_window(t_data *img);
void				set_display(t_data *img);
t_data				*get_cord_player(t_data *img);

int					ft_putnbr(int n, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);
int					key_hook(int key_code, t_data *img);
void				move_image_w(t_data *img);
void				move_image_s(t_data *img);
void				move_image_a(t_data *img);
void				move_image_d(t_data *img);
void				print_mouvement(t_data *img);
int					is_valid_path_co(char **map, t_cord pos);
void				flood_fill(int x, int y, t_cord pos, char **map);
int					verif_exit(char **map);
int					flood_fill_2(int x, int y, char **map);

int					compte_co(t_data *img);

#endif
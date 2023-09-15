/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:09:58 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/15 19:55:58 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# define CUB3D_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

typedef struct s_cord
{
	unsigned int			start_x;
	unsigned int			start_y;
	unsigned int			end_x;
	unsigned int			end_y;
	unsigned int			lig;
	unsigned int			 col;
}				t_cord;

typedef struct s_player
{
	int			player_x;
	int			player_y;
}				t_player;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	char		**map;
	void		*mlx;
	void		*img_mur;
	void		*img_exit;
	void		*img_conso;
	void		*img_perso;
	void		*img_back;
	void		*win_ptr;
	int			width;
	int			height;
	int			x;
	int			y;
	int			nb_mouvement;
	int			conso;
	t_player	t_player;
	t_cord		cord;
}				t_data;

int				ft_strlen(const char *s);

char			*ft_strdup(char *src);

size_t			ft_verification(int start, size_t len, char *s);

char			*ft_substr(char *s, unsigned int start, size_t len);

void			ft_scotch(char *dest, char *ss1, char *ss2);

char			*ft_strjoin(char *s1, char *s2);

char			*get_next_line(int fd);

char			**ft_split(char *s, char c);

int				verif_bords(char **map);

int				verif_map(char **map);
int				is_char_sett(char *map);
int				verif_open(char **argv);
int				ft_strcmp(const char *s1, const char *s2);
int				verif_namearg(int argc, char **argv);
int				verifall(char **map);
// PARSING
char			**get_map(char **argv);
void			ft_colle(char *dest, char *ss1, char *ss2);
char			*ft_strjoin_1(char *s1, char *s2);
int				verif_element(char **map);
// Get_map
// int				is_valid_path_exit(char **map, struct cord pos);
// struct cord		get_map_ligne(char **map, struct cord cord);

// struct cord		get_map_col(char **map, struct cord cord);

// struct cord		cord_start(char **map, struct cord cord);

// struct cord		cord_exit(char **map, struct cord cord);

// struct cord		cord_all(char **map, struct cord pos);
t_cord			cord_start(char **map, t_cord cord);
t_cord			cord_exit(char **map, t_cord cord);
t_cord			get_map_col(char **map, t_cord cord);
t_cord			get_map_ligne(char **map, t_cord cord);
int				is_valid_path_exit(char **map, t_cord pos);
t_cord			cord_all(char **map, t_cord pos);

// Exit funtion
void			ft_free_all(t_data *img);
void			ft_free(char **map);
void			quit_esc(t_data *img);
void			free_images(t_data *img);
void			ft_game_over(t_data *img);

//////////////////////////////////////////////////
int				verif_co(char **map, t_cord pos);
void			put_image(t_data *img);

void			set_display(t_data *img);
int				display_window(t_data *img);
void			set_display(t_data *img);
t_data			*get_cord_player(t_data *img);

int				ft_putnbr(int n, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putchar_fd(char c, int fd);
int				key_hook(int key_code, t_data *img);
void			move_image_w(t_data *img);
void			move_image_s(t_data *img);
void			move_image_a(t_data *img);
void			move_image_d(t_data *img);
void			print_mouvement(t_data *img);
int				is_valid_path_co(char **map, t_cord pos);
void			flood_fill(int x, int y, t_cord pos, char **map);
int				verif_exit(char **map);
int				flood_fill_2(int x, int y, char **map);

int				compte_co(t_data *img);
#endif
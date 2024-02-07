/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:53:36 by damachad          #+#    #+#             */
/*   Updated: 2024/02/07 14:54:52 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdbool.h>

// Macros
# define SCREEN_WIDTH 960
# define SCREEN_HEIGHT 768
# define PLANE_W 320
# define PLANE_H 200
# define CUB_SIDE 64
# define PLAYER_H 32
# define FOV 1 // in radians
# define NB_SPRITES 4

# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF

# define NO "textures/ice.png"
# define SO "textures/lava.png"
# define WE "textures/bricks.png"
# define EA "textures/leaves.png"
# define FLOOR "" // How to process input color ?
# define CEILING "" // Check for valid range
# define START_ANGLE 0 // angle in radians

# define PI 3.14159265358979323846
# define PI_DOUBLE 6.28318530717958647692
# define PI_HALF 1.57079632679489661923
# define PI_THREE_HALFS 4.71238898038468985769

// Structs

//line drawing algorithm variables
typedef struct s_bresenham
{
	int	x0;
	int	y0;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
}		t_bresenham;

typedef struct s_point
{
	int	x;
	int	y;
}					t_point;

typedef struct s_map
{
	char			**bytes;
	unsigned int	rows;
}					t_map;

typedef struct s_sprite{
	void	*img;
	int		width;
	int		height;
}			t_sprite;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	unsigned int	player_a;
	t_point			player_curr;
	double			time;
	double			old_time;
	t_map			*map;
	t_img			img;
	t_sprite		*sprites;
}					t_game;

/*----------------------------map----------------------------*/
t_map	*new_map(unsigned int rows);
int		nr_lines(t_game *game, char *mapfile);
void	load_map(t_game *game, char *mapfile);

/*--------------------------checker--------------------------*/
void	validate_map(t_game *game);

/*---------------------------init----------------------------*/
void	init_graphics(t_game *game);
void	start_game(char	*mapfile);
void	load_sprites(t_game *game);

/*---------------------------clean---------------------------*/
void	error_msg(t_game *game, char *msg);
int		quit_prog(t_game *game);
void	destroy_game(t_game *game);
void	destroy_map(t_map *map);

/*--------------------------draw_line------------------------*/
void	put_pixel(t_img *img, int x, int y, int color);
void	draw_line(t_game *game, t_point *a, t_point *b);

/*--------------------------background-----------------------*/
void	draw_background(t_img *img);
void	draw_wall_test(t_game *game);

/*--------------------------raycasting-----------------------*/
void	draw_wall(t_game *game);

#endif

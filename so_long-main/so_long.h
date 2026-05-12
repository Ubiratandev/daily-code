#ifndef SO_LONG_H
 #define SO_LONG_H
#include <fcntl.h>    // to open()
#include <stdio.h>    // to perror()
#include <unistd.h>   // to close()
#include <errno.h>    // to errno
#include <stdlib.h>  
#include <mlx.h>
typedef struct s_p_sprites{
        void    *front;
        void    *back;
        void    *left;
        void    *rigth;
}t_p_sprites;
typedef struct s_images{
        void    *floor;
        void    *wall;
        void    *coletables;
        void    *exit;
        t_p_sprites     player;
}t_images;

typedef struct s_data{
        void    *img;
        char    *addr;
        int     bpp;
        int     line_len;
        int     endian;
}t_data;

typedef struct s_map{
        char    **arr;
        int     coletables;
        int     P_i;
        int     P_j;
        int     door;
        int     len_col;
        int     len_row;
}t_map;

typedef struct s_vars{
        void    *mlx;
        void    *win;
        t_map   *map;
        int     sprite_size;
}t_vars;

typedef struct s_key_press{
        t_vars *vars;
        t_images *sprite;
}t_keypress;
char    **create_array(int len_column, int len_row);
int     check_perimeter(char **arr, int row, int col);
int     check_itens(char **arr, int row, int col);
void	put_at_array(char *argv, t_map *map);
void    my_mlx_pixel_put(t_data *data, int x, int y, int color);
int     close_win(t_vars *vars);
int close_w_esc(int keycode, t_vars *vars);
void count_lines(char *argv, t_map *map);
int     count_coletables(char *argv);
int	calc_srite_size(int window_width,int window_heigth, t_map map);
void render_map(t_vars *vars, t_map *map, t_images *sprite, void *player, int sprite_size);
#endif

#include <fcntl.h>    // Para open()
#include <stdio.h>    // Para perror()
#include <unistd.h>   // Para close()
#include <errno.h>    // Para errno
#include <stdlib.h>
#include <mlx.h>

typedef struct s_vars{
                void    *mlx;
                void    *win;
		char	**arr;
}t_vars;


typedef struct vector_s
{
	int	row;
	int	col;
}vector_t;

typedef struct s_data{
	void    *img;
	char    *addr;
	int     bpp;
	int     line_len;
	int     endian;
}t_data;

char	**create_array(int len_column, int len_row)
{
	char	**arr;
	int	i;

	i = 0;
	arr = (char **) malloc((len_row + 1) * sizeof(char*));
	if(!arr)
		return(NULL);
	while(i < len_row)
	{
		arr[i] = (char *) malloc((len_column + 1) * sizeof(char));
		if(!arr[i])
			return (NULL);
		i++;
	}
	i = 0;
	while(i < len_row)
	{
		arr[i][len_column + 1] = '\0';
		i++;
	}
	arr[len_row + 1] = '\0';
	return (arr);
}

int	check_perimeter(char **arr, int row, int col)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(j < col)
		if(arr[0][j++] != '1')
			return (0);
	j = 0;
	while(j < col)
		if(arr[row -1][j++] != '1')
			return (0);
	while(i < row)
		if(arr[i++][0] != '1')
			return (0);
	i = 0;
	while(i < row)
		if(arr[i++][col -1] != '1')
			return(0);
	return(1);
}
int	check_itens(char **arr, int row, int col)
{
	int	i;
	int	j;
	int	character;
	int	dor;
	int	colect;

	character = 0;
	dor = 0;
	colect = 0;
	i = 0;
	while(i < row)
	{
		j = 0;
		while(j < col)
		{
			if(arr[i][j] == 'P')
				character++;
			else if(arr[i][j] == 'E')
				dor++;
			else if(arr[i][j] == 'c')
				colect++;
			j++;
		}
		i++;
	}
	if(character != 1)
		return (0);
	else if(dor != 1)
		return (0);
	else if(colect <= 0)
		return (0);
	return (1);
}

vector_t	count_vector(char **arr)
{
	vector_t	ret;
	int	control;
	char	str[1];
	int	fd;

	fd = 0;
	ret.row = 0;
	ret.col = 0;
	control =0;
	 fd = open("my_map.ber", O_RDONLY);
        /*if (fd == -1)
                perror("error to open a file");
        if(is_rectangular(fd) == 0)
                return (0);
        if(lenth_line(fd)== 0)
                return (0);*/

        //conta as linhas e colunas da matriz
        while(read(fd, str, 1) > 0)
        {
                if(str[0] != '\n' && control == 0)
                        ret.col++;
                else if(str[0] == '\n')
                {
                        ret.row++;
                        control = 1;
                }
        }
        close(fd);
	return (ret);
}
vector_t	find(char **arr, char c)
{
	vector_t	len;
	vector_t	ret;
	int	i;
	int	j;

	i = 0;
	len = count_vector(arr);
	while(i < len.row)
	{
		j = 0;
		while(j < len.col)
		{
			if (arr[i][j] == c)
			{
				ret.row = i;
				ret.col = j;
			}
				
			j++;
		}
		i++;
	}
	return (ret);
}
vector_t	find_c(char **arr, vector_t *C, int coletable, int i)
{
	int	n;
	int	j;

	n = 0;
	j = 0;
	(C[i]) = find(arr, 'c');
	n = (C[i]).row;
	j = (C[i]).col;
	arr[n][j] = '0';
	i++;
	if(i < coletable)
	{
		find_c(arr, C, coletable, i);
	}
}
int	find_path(char **arr, vector_t P, vector_t E)
{
	int	find;

	find = 1;
	 while(P.row != E.row && find == 1)
        {
                if(P.row < E.row)
                        while(P.row < E.row && P.row + 1 != '1')
                                P.row++;
                else if(P.row > E.row)
                        while(P.row > E.row && P.row -1 != '1')
                                P.row--;
                if(P.col < E.col)
                        while(P.col < E.col && P.col + 1 != '1')
                                P.col++;
                else if(P.col > E.col)
                        while(P.col > E.col && P.col -1 != '1')
                                P.col--;
		find = 0;
        }
	if(P.row  == E.row)
		find = 1;
	return(find);

}
int	play_the_game(char **arr, int row, int col, int coletable)
{
	int		i;
	vector_t	P;
	vector_t	E;
	vector_t	C[coletable];
	char	**arr2;

	arr2 = arr;
	i = 0;
	P = find(arr2,'P');
	E = find(arr2,'E');
	find_c(arr2, C,coletable, i);
	while(P.row != E.row)
	{
		if(P.row < E.row)
			while(P.row < E.row && P.row + 1 != '1')
				P.row++;
		else if(P.row > E.row)
			while(P.row > E.row && P.row -1 != '1')
				P.row--;
		if(P.col < E.col)
                        while(P.col < E.col && P.col + 1 != '1')
                                P.col++;
                else if(P.col > E.col)
                        while(P.col > E.col && P.col -1 != '1')
                                P.col--;
	}


	//hipoteticamente eu ja tenho todas as posiçoes
/*	printf("vector %d %d \n", (C[0]).row, (C[0]).col);
	printf("vector %d %d \n", (C[1]).row, (C[1]).col);
	printf("vector %d %d \n", (C[2]).row, (C[2]).col);*/

	

}

char   **put_at_array(char *argv[], char **arr)
{
	int     fd;
        char    str[1];
        int     len_colum;
        int     len_row;
        int     i;
        int     j;
        int     coletable;
	int	control_read;

	control_read = 0;
        coletable = 0;
        i = 0;
        j = 0;
        len_row = 0;
        len_colum = 0;
        str[0] = ' ';

	 fd = open(argv[1], O_RDONLY);

        //atrubui ao array os valores lidos do arquivo
        while ((control_read = read(fd, str, 1)) > 0)
        {
                if (str[0] == '\n')
                {
                        i++;
                        j = 0;  // Reinicia a linha ao encontrar '\n'
                        if (i > len_colum)
                                break;  // Prevenção contra estouro de memória

                }
                else
                {
                        if (len_row + 1 >= j)
                                arr[i][j] = str[0];
                        if(arr[i][j] == 'c')
                                coletable++;
                        j++;
                }
        }
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color){
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
*(unsigned int *)dst = color;
}

int	close_win(int keycode, t_vars *vars)
{
	/*
	int	i;
	
	i = 0;
	while(vars->arr[i])
	{
		free(vars->arr[i]);
		i++;
	}
	free(vars->arr);
	mlx_destroy_window(vars->mlx, vars->win);
	}*/

   
        int i;
	
	i = 0;
	if (!vars) // Proteção extra para evitar segfault
        	return (0);
        if (vars->arr)
        {
            while (vars->arr[i])
            {
                free(vars->arr[i]);
                i++;
            }
            free(vars->arr);
        }

        if (vars->win)
            mlx_destroy_window(vars->mlx, vars->win);

        exit(0);
     
    return (0);

}
int close_w_esc(int keycode, t_vars *vars)
{
    if (keycode == 65307) // 65307 é o código da tecla ESC
        close_win(65307, vars);
    return (0);
}

int	main(int argc, char *argv[])
{
	int	fd;
	char	str[1];
	int	len_colum;
	int	len_row;
	int	control;
	char	**arr;
	int	i;
	int	j;
	int	control_read;
	int	coletable;
	void	*mlx;
	t_data  img;
        t_vars vars;


	coletable = 0;
	control_read == 1;
	i = 0;
	j = 0;
	len_row = 0;
	control = 0;
	len_colum = 0;
	str[0] = ' ';
	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	/*if (fd == -1)
		perror("error to open a file");
	if(is_rectangular(fd) == 0)
		return (0);
	if(lenth_line(fd)== 0)
		return (0);*/

	//conta as linhas e colunas da matriz
	while((control_read = read(fd, str, 1)) > 0)
	{
		if(str[0] != '\n' && control == 0)
			len_colum++;
		else if(str[0] == '\n')
		{
			len_row++;
			control = 1;
		}
	}
	close(fd);
	vars.arr = (create_array(len_colum, len_row));
	arr = vars.arr;
	//atrubui ao array os valores lidos do arquivo
	//arr = put_at_array(argv, arr);

	fd = open(argv[1], O_RDONLY);
	while ((control_read = read(fd, str, 1)) > 0)
        {
                if (str[0] == '\n')
                {
                        i++;
                        j = 0;  // Reinicia a linha ao encontrar '\n'
                        if (i > len_colum)
                                break;  // Prevenção contra estouro de memória

                }
                else
                {
                        if (len_row + 1 >= j)
                                arr[i][j] = str[0];
                        if(arr[i][j] == 'c')
                                coletable++;
                        j++;
                }
        }
	close(fd);
	printf("%d \n",check_perimeter(arr, len_row, len_colum));
	printf("%d \n", check_itens(arr, len_row, len_colum));
	printf("%d \n", coletable);

	//printa a matriz
	
	i = 0;
	while (i < len_row) // Troquei len_colum por len_row aqui!
	{
		j = 0;
		 while (j < len_colum) // len_colum e len_row estavam trocados antes?
		{
        		printf("%c", arr[i][j]);
       			 j++;
    		}
		printf("\n"); // Adiciona quebra de linha para facilitar a visualização
		i++;
	}
	//renderização de imagem na tela
	/*void	*img;
	typedef struct s_data{
		void	*img;
		char	*addr;
		int	bpp;
		int	line_len;
		int	endian;
	}t_data;*/
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 320, 320, "Hello word");
	img.img = mlx_new_image(vars.mlx, 320, 320);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	my_mlx_pixel_put(&img, 5 ,5, 0x00FF0000);
	
	int	lx;
	int	ly;

	lx = 25;
	ly = 25;

	while(lx != 60)
	{
		my_mlx_pixel_put(&img, lx, ly, 0x00FF0000);
		lx++;
	}
	while(ly != 60)
	{
		my_mlx_pixel_put(&img, lx, ly, 0x00FF0000);
			ly++;
	}
	while(lx != 25)
	{
		my_mlx_pixel_put(&img, lx, ly, 0x00FF0000);
		lx--;
	}
	while(ly != 25)
		my_mlx_pixel_put(&img, lx, ly--, 0x00FF0000);

	lx = 25;
	ly = 25;
	while(ly != 60)
	{
		my_mlx_pixel_put(&img, lx, ly,0x00FF0000);
		while(lx != 60)
			my_mlx_pixel_put(&img, lx++, ly,0x00FF0000);
		ly++;
		lx = 25;
	}
		
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, close_w_esc, &vars);
	mlx_hook(vars.win, 17, 1L<<17, close_win, &vars);
	mlx_loop(vars.mlx);








}

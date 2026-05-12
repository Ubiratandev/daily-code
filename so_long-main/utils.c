#include "so_long.h"

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

void put_at_array(char *argv, t_map *map)
{
    int fd;
    char str[1];
    int control_read;
    int i = 0;
    int j = 0;

    fd = open(argv, O_RDONLY);
    if (fd == -1)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    while ((control_read = read(fd, str, 1)) > 0)
    {
        if (str[0] == '\n')
        {
            i++;
            j = 0;
            if (i >= map->len_row)
                break;
        }
        else
        {
            if (j >= map->len_col)
            {
                printf("Erro: Mapa tem mais colunas do que o esperado.\n");
                break;
            }
            map->arr[i][j] = str[0];
            if (map->arr[i][j] == 'C')
                map->coletables++;
            j++;
        }
    }

    i = 0;
    while (i < map->len_row)
    {
        j = 0;
        while (j < map->len_col)
        {
            if (map->arr[i][j] == 'P')
            {
                map->P_i = i;
                map->P_j = j;
                return;
            }
            j++;
        }
        i++;
    }
    close(fd);
}
void	my_mlx_pixel_put(t_data *data, int x, int y, int color){
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
*(unsigned int *)dst = color;
}
int close_w_esc(int keycode, t_vars *vars)
{
    if (keycode == 65307) // 65307 é o código da tecla ESC
        close_win(vars);
    return (0);
}

void count_lines(char *filename, t_map *map)
{
    int fd;
    char str[1];
    int control_read;
    int rows = 0, cols = 0, current_cols = 0;
    int control = 0;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        write(1,"Erro ao abrir o arquivo\n",24);
        return;
    }
    while ((control_read = read(fd, str, 1)) > 0)
    {
        if (str[0] != '\n' && control == 0)
            current_cols++;
        else if (str[0] == '\n')
        {
            rows++;
            if (current_cols > cols)
                cols = current_cols;
            current_cols = 0;
            control = 1;
        }
        else
            current_cols++;
    }
    if (current_cols > 0)
    {
        rows++;
        if (current_cols > cols)
            cols = current_cols;
    }
    close(fd);
    map->len_row = rows;
    map->len_col = cols;
}
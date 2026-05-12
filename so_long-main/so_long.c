#include "so_long.h"

int     close_win(t_vars *vars)
{ 
       /* int i;
        
        i = 0;
        if (!vars)
                return (0);
        if (vars->arr)
        {
            while (vars->arr[i])
            {
                free(vars->arr[i]);
                i++;
            }
            free(vars->arr);
        }*/

        if (vars->win)
            mlx_destroy_window(vars->mlx, vars->win);

        exit(0);
     
    return (0);

}

/*
void render_map(t_vars *vars, t_map *map, int sprite_size)
{
    int i, j;
    void *img_wall, *img_grass;
  //  char *relative_path;

    // Carrega as texturas uma vez
    img_wall = mlx_xpm_file_to_image(vars->mlx, "./wall.xpm", &sprite_size, &sprite_size);
    img_grass = mlx_xpm_file_to_image(vars->mlx, "./grass.xpm", &sprite_size, &sprite_size);

    if (!img_wall || !img_grass)
    {
        printf("Erro ao carregar imagens\n");
        return;
    }

    i = 0;
    while (i < map->len_row)  // Percorre as linhas
    {
        j = 0;
        while (j < map->len_col)  // Percorre as colunas
        {
            // Define a textura baseada no caractere do mapa
            if (map->arr[i][j] == '1')
                mlx_put_image_to_window(vars->mlx, vars->win, img_wall, j * sprite_size, i * sprite_size);
            else
                mlx_put_image_to_window(vars->mlx, vars->win, img_grass, j * sprite_size, i * sprite_size);

            j++;
        }
        i++;
    }

    // Libera as imagens após o uso
    mlx_destroy_image(vars->mlx, img_wall);
    mlx_destroy_image(vars->mlx, img_grass);
}
*/
void load_images(t_vars *vars, t_images *sprites)
{
	int	size;

	size = 48;
	sprites->floor = mlx_xpm_file_to_image(vars->mlx, "./floor.xpm", &size, &size);
	sprites->wall = mlx_xpm_file_to_image(vars->mlx, "./wall.xpm", &size, &size);
	
	//player front
	sprites->player.front = mlx_xpm_file_to_image(vars->mlx, 
		"./player_f.xpm", &size, &size);
	//player up
	sprites->player.back = mlx_xpm_file_to_image(vars->mlx, 
		"./player_up/player_b.xpm", &size, &size);


	sprites->player.left = mlx_xpm_file_to_image(vars->mlx,
		"player_l.xpm", &size, &size);

	sprites->player.rigth = mlx_xpm_file_to_image(vars->mlx,
			"player_r.xpm", &size, &size);
	sprites->coletables= mlx_xpm_file_to_image(vars->mlx,
         "coletable.xpm", &size, &size);
    sprites->exit = mlx_xpm_file_to_image(vars->mlx,"exit.xpm", &size, &size);
	
}	
void render_map(t_vars *vars, t_map *map,t_images *sprite, void *player, int sprite_size)
{
    int i;
	int j;
    i = 0;
	 // Limpa a janela
	//mlx_clear_window(vars->mlx, vars->win); //this line cause fliking
    while (i < map->len_row)
    {
        j = 0;
        while (j < map->len_col)
        {
            //printf("Rendering at (%d, %d)\n", j * sprite_size, i * sprite_size + offset_y); // Depuração
            if (map->arr[i][j] == '1')
                mlx_put_image_to_window(vars->mlx, vars->win,sprite->wall, j * sprite_size, i * sprite_size); // Parede vermelha
            else if (map->arr[i][j] == '0' )
                mlx_put_image_to_window(vars->mlx, vars->win,sprite->floor, j * sprite_size, i * sprite_size ); // Chão verde
			
			else if(map->arr[i][j] == 'c')
				mlx_put_image_to_window(vars->mlx, vars->win,sprite->coletables, j * sprite_size, i * sprite_size);
			else if (map->arr[i][j] == 'P')
			{
				//mlx_put_image_to_window(vars->mlx, vars->win,sprite->floor, j * sprite_size, i * sprite_size ); // Chão verde
				mlx_put_image_to_window(vars->mlx, vars->win,player
							, j * sprite_size, i * sprite_size );
			
			}
            else if (map->arr[i][j] == 'E')
            {
                mlx_put_image_to_window(vars->mlx, vars->win, sprite->exit,j * sprite_size, i * sprite_size);
            }
			j++;
        }
        i++;
    }
}
int	calc_sprite_size(int window_width,int window_heigth, t_map map)
{
	int	sprite_width;
	int sprint_heigth;

	sprite_width = window_width / map.len_col;
	sprint_heigth = window_heigth / map.len_row;

	if(sprite_width < sprint_heigth)
		return (sprite_width);
	return (sprint_heigth);

}


void move_on_up(t_vars *vars, t_images *sprites, int keycode)
{
	t_map *map = vars->map;
    int sprite_size = vars->sprite_size;
	int new_i = map->P_i; // Nova posição i (linha)
    int new_j = map->P_j; // Nova posição j (coluna)

    if (keycode == 119) // up (W)
		new_i--;
	else if (keycode == 17)
		close_win(vars);
    if (new_i >= 0 && new_i < map->len_row && // Verifica limites das linhas
        new_j >= 0 && new_j < map->len_col && // Verifica limites das colunas
        map->arr[new_i][new_j] != '1' 
        && map->arr[new_i][new_j] !='E')      // Verifica se não é uma parede
    {
      mlx_put_image_to_window(vars->mlx, vars->win, sprites->floor,
			 new_j * sprite_size, new_i *sprite_size);
		mlx_put_image_to_window(vars->mlx,vars->win,sprites->player.back,
			 new_j * sprite_size, new_i * sprite_size);
		 map->arr[map->P_i][map->P_j] = '0';
        map->P_i = new_i;
        map->P_j = new_j;
        map->arr[map->P_i][map->P_j] = 'P';
    }
	render_map(vars, map, sprites, sprites->player.back, sprite_size);
}



void move_on_donw(t_vars *vars, t_images *sprites, int keycode)
{
	t_map *map = vars->map;
    int sprite_size = vars->sprite_size;

    int new_i = map->P_i; // Nova posição i (linha)
    int new_j = map->P_j; // Nova posição j (coluna)

    // Calcula a nova posição com base na tecla pressionada
    if (keycode == 115) // down (S)
    {
		new_i++;
		//write(1, "d",1);
	}
	else if (keycode == 17)
		close_win(vars);
    // Verifica se a nova posição é válida (dentro dos limites e não é uma parede)
    if (new_i >= 0 && new_i < map->len_row && // Verifica limites das linhas
        new_j >= 0 && new_j < map->len_col && // Verifica limites das colunas
        map->arr[new_i][new_j] != '1' &&  
        map->arr[new_i][new_j] != 'E')       // Verifica se não é uma parede
    {
		mlx_put_image_to_window(vars->mlx, vars->win, sprites->floor,
			 new_j * sprite_size, new_i *sprite_size);
		mlx_put_image_to_window(vars->mlx,vars->win,sprites->player.front,
			 new_j * sprite_size, new_i * sprite_size);
        // Atualiza a matriz para remover o personagem da posição antiga
        map->arr[map->P_i][map->P_j] = '0';

        // Atualiza a posição do personagem
        map->P_i = new_i;
        map->P_j = new_j;

        // Atualiza a matriz para colocar o personagem na nova posição
        map->arr[map->P_i][map->P_j] = 'P';
    }
	render_map(vars, map, sprites,sprites->player.front, sprite_size);
}



void move_on_left(t_vars *vars, t_images *sprites, int keycode)
{
	t_map *map = vars->map;
    int sprite_size = vars->sprite_size;

    int new_i = map->P_i; // Nova posição i (linha)
    int new_j = map->P_j; // Nova posição j (coluna)

    // Calcula a nova posição com base na tecla pressionada
    if (keycode == 97) // left (A)
    {
		new_j--;
		//write(1, "d",1);
	}
	else if (keycode == 17)
		close_win(vars);
    // Verifica se a nova posição é válida (dentro dos limites e não é uma parede)
    if (new_i >= 0 && new_i < map->len_row && // Verifica limites das linhas
        new_j >= 0 && new_j < map->len_col && // Verifica limites das colunas
        map->arr[new_i][new_j] != '1')        // Verifica se não é uma parede
    {
		mlx_put_image_to_window(vars->mlx, vars->win, sprites->floor,
			 new_j * sprite_size, new_i *sprite_size);
		mlx_put_image_to_window(vars->mlx,vars->win,sprites->player.left,
			 new_j * sprite_size, new_i * sprite_size);
        // Atualiza a matriz para remover o personagem da posição antiga
        map->arr[map->P_i][map->P_j] = '0';

        // Atualiza a posição do personagem
        map->P_i = new_i;
        map->P_j = new_j;

        // Atualiza a matriz para colocar o personagem na nova posição
        map->arr[map->P_i][map->P_j] = 'P';
    }
	render_map(vars, map, sprites,sprites->player.left, sprite_size);
}





void move_on_rigth(t_vars *vars, t_images *sprites, int keycode)
{
	t_map *map = vars->map;
    int sprite_size = vars->sprite_size;
	int new_i = map->P_i; // Nova posição i (linha)
    int new_j = map->P_j; // Nova posição j (coluna)

    // Calcula a nova posição com base na tecla pressionada
    if (keycode == 100) // rigtg (D)
		new_j++;
	else if (keycode == 17)
		close_win(vars);
    // Verifica se a nova posição é válida (dentro dos limites e não é uma parede)
    if (new_i >= 0 && new_i < map->len_row && // Verifica limites das linhas
        new_j >= 0 && new_j < map->len_col && // Verifica limites das colunas
        map->arr[new_i][new_j] != '1')        // Verifica se não é uma parede
    {
		mlx_put_image_to_window(vars->mlx, vars->win, sprites->floor,
			 new_j * sprite_size, new_i *sprite_size);
		mlx_put_image_to_window(vars->mlx,vars->win,sprites->player.rigth,
			 new_j * sprite_size, new_i * sprite_size);
        // Atualiza a matriz para remover o personagem da posição antiga
        map->arr[map->P_i][map->P_j] = '0';
		// Atualiza a posição do personagem
        map->P_i = new_i;
        map->P_j = new_j;
		// Atualiza a matriz para colocar o personagem na nova posição
        map->arr[map->P_i][map->P_j] = 'P';
    }
	render_map(vars, map, sprites,sprites->player.rigth, sprite_size);
}

int key_press(int keycode, t_keypress *vars)
{
    // Chama a função para mover o personagem
	//write(1, "p",1);
	if (keycode == 115) // down (S)
    {
		move_on_donw(vars->vars, vars->sprite, keycode);
		//write(1, "d",1);
	}
    else if (keycode == 119) // up (W)
		move_on_up(vars->vars,vars->sprite, keycode);
    else if (keycode == 100) // right (D)
		move_on_rigth(vars->vars, vars->sprite, keycode); 
    else if (keycode == 97) // left (A)
        move_on_left(vars->vars, vars->sprite, keycode);
	// 	// else if (keycode == 17)
	// 	close_win(vars);
    // move_on(vars->vars, vars->sprite, keycode);
    return (0);
}

int main(int argc, char *argv[])
{
    t_vars vars;
    t_map map;
    int sprite_size;
 
    if (argc != 2)
        return (0);

    // Inicializa o mapa
    count_lines(argv[1], &map);
    printf("%d %d \n", map.len_col, map.len_row);
    map.arr = create_array(map.len_col, map.len_row);
    put_at_array(argv[1], &map);

    // Calcula o tamanho do sprite
    sprite_size = calc_sprite_size(1000, 1000, map);
	// Inicializa o MLX e a janela
    vars.mlx = mlx_init();
    int required_width = map.len_col * sprite_size;
    int required_height = map.len_row * sprite_size;
	
    vars.win = mlx_new_window(vars.mlx, required_width, required_height, "so_long");

    // Atribui o mapa e o tamanho do sprite à estrutura vars
    vars.map = &map;
    vars.sprite_size = sprite_size;
	// inicia a struct do sprite
	t_images sprites;
	load_images(&vars, &sprites);
    // Verifica se a janela é grande o suficiente
    if (required_width > 2800 || required_height > 900)
    {
        printf("Janela muito pequena para o mapa! Aumente a janela ou reduza o sprite_size.\n");
        return (0);
    }

    // Renderiza o mapa inicial
    render_map(&vars, &map, &sprites,sprites.player.front ,sprite_size);
	//
	
	t_keypress env;
	env.vars = &vars;
	env.sprite = &sprites;
    // Configura os hooks
    mlx_hook(vars.win, 2, 1L << 0, key_press, &env); // Captura teclas pressionadas
    mlx_hook(vars.win, 17, 1L << 17, close_win, &vars); // Captura fechamento da janela

    // Inicia o loop do MLX
    mlx_loop(vars.mlx);
    return (0);
}
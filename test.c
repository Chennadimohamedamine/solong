# include <mlx.h>

int main()
{
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 10000, 10000, "so_long");
    mlx_loop(mlx);
}
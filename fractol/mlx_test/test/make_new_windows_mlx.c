#include "mlx.h"

int	main(void)
{
	void	*mlx_instance1;
	void	*img;

	mlx_instance1 = mlx_init();
	img = mlx_new_window(mlx_instance1, 800, 800, "hello");
	mlx_loop(mlx_instance1);
	return (0);
}

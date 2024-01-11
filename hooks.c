
#include "fdf.h"

int	no_event(void *data)
{
	return (0);
}

int     win_close(int keysym, t_map_data *data)
{
        if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	}
        return(0);
}

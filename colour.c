
#include "fdf.h"

/*double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	return (placement / distance);
}

int	light(int start, int end, double percentage)
{
	return((int)((1 - percentage) * start + percentage * end));
}

int	colour(t_map_data current, t_map_data start, t_map_data end, t_map_data delta)
{
	int	red;
	int	green;
	int	blue;
	double	percentage;

	if (current->colour == end->colour)
		return (current->colour);
	if (delta->x > delta->y)
		percentage = percent(start->)
}*/

double        percent(int start, int end, int current)
{
        double  placement;
        double  distance;

        placement = current - start;
        distance = end - start;
        if (distance == 0)
                return (1.0);
        return (placement / distance);
}

int	get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int	get_colour(t_point current, t_point start, t_point end, t_point delta)
{
	int red;
	int green;
	int blue;
	double percentage;
	
	if (current.colour == end.colour)
		return (current.colour);
	if (delta.x > delta.y)
		percentage = percent(start.x, end.x, current.x);
	else
		percentage = percent(start.y, end.y, current.y);
	red = get_light((start.colour >> 16) & 0xFF, (end.colour >> 16) & 0xFF, percentage);
	green = get_light((start.colour >> 8) & 0xFF, (end.colour >> 8) & 0xFF, percentage);
	blue = get_light(start.colour & 0xFF, end.colour & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

int	colour(t_point current, t_point start, t_point end, t_point delta)
{
	return (get_colour(current, start, end, delta));
}
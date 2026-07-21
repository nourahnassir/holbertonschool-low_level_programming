#include "main.h"
#include <stdlib.h>

/**
 * free_grid - frees a 2 dimensional grid previously created by alloc_grid
 * @grid: the 2 dimensional grid to free
 * @height: height of the grid
 *
 * Return: Nothing.
 */
void free_grid(int **grid, int height)
{
	int h;

	if (grid == NULL || height <= 0)
		return;

	for (h = 0; h < height; h++)
	{
		free(grid[h]);
	}
	free(grid);
}


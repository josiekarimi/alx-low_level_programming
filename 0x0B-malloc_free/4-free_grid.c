#include "main.h"
#include <stdlib.h>

/**
 * free_grid - Frees a 2-dimensional grid previously created by alloc_grid.
 * @grid: Pointer to the 2-dimensional grid.
 * @height: The height of the grid.
 */
void free_grid(int **grid, int height)
{
int i;
if (grid == NULL || height <= 0)
return;
/* Free each row */
for (i = 0; i < height; i++)
free(grid[i]);
/* Free the row pointers */
free(grid);
}

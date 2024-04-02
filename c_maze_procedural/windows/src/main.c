#include <stdio.h>
#include "structs.h"
#include "defs.h"

static void loadTiles(void);

void initMap(void)
{
	loadTiles();
}

static void loadTiles(void)
{
	int			i;
	char		filename[MAX_FILENAME_LENGTH] = {0};
	AtlasImage	*tiles[MAX_TILES];
	AtlasImage	*darkTile;
	

	for (i = 1 ; i < MAX_TILES ; i++)
	{
		sprintf(filename, "../resources/tile%d.jpg", i);

		tiles[i] = getAtlasImage(filename, 0);
	}
	darkTile = getAtlasImage("../resources/darktiles.png", 1);
}

int initSDL(void)
{
    SDL_Init(SDL_INIT_VIDEO);
}

int	main(void)
{
	printf("Hi! I'm Temmy!\n");
	return (0);
}

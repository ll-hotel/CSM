#include <stdio.h>
#include <SDL2/SDL.h>
#include <structs.h>
#include <defs.h>

#define MAP_TITLE_SIZE 48

#define MAP_WIDTH 33
#define MAP_HEIGHT 19

#define MAP_RENDER_WIDTH 32
#define MAP_RENDER_HEIGHT 18

#define MAP_RENDER_X ((SCREEN_WIDTH - (MAP_RENDER_WIDTH * MAP_TITLE_SIZE)) /2)
#define MAP_RENDER_Y ((SCREEN_HEIGHT - (MAP_RENDER_HEIGHT * MAP_TITLE_SIZE)) /2)

#define TITLE_HOLE 0
#define TITLE_GROUND 1
#define TITLE_WALL 50

enum 
{
	ET_UKNOWN,
	ET_PLAYER
}

struct Entity
{
	int id;
	int type;
	char name[MAX_NAME_LENGTH];
	int x;
	int y;
	int facing;
	AtlasImage *texture;
	Entoty *next;
};

typedef struct
{
	int tile;
	int visible;
	int revealed;
} MapTile;

typedef struct 
{
	int entityId;
	Entity entityHead, *entityTail;
	Entity *player;
	MapTile map[MAP_WIDTH][MAP_HEIGHT];
	SDL_Point camera;
} Dungeon;

void initMap(void)
{
	loadTiles();
}

static void loadTiles(void)
{
	int i;
	char filename[MAX_FILENAME_LENGTH];

	for (i = 1 ; i < MAX_TILES ; i++)
	{
		sprintf(filename, "tiles.jpg", i);

		tiles[i] = getAtlasImage(filename, 0);
	}
	darkTile = getAtlasImage("darktiles.png", 1);
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

#ifndef STRUCTS_H
# define STRUCTS_H
# include <SDL2/SDL.h>
# include "AtlasImage.h"
# include "defs.h"

typedef struct s_entity	Entity;

struct s_entity
{
	int			id;
	int			type;
	char		name[MAX_NAME_LENGTH];
	int			x;
	int			y;
	int			facing;
	AtlasImage	*texture;
	Entity		*next;
};

typedef struct
{
	int tile;
	int visible;
	int revealed;
} MapTile;

typedef struct 
{
	int			entityId;
	Entity		entityHead, *entityTail;
	Entity		*player;
	MapTile		map[MAP_WIDTH][MAP_HEIGHT];
	SDL_Point	camera;
} Dungeon;
#endif

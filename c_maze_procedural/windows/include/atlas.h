#ifndef ATLAS_IMAGE_H
# define ATLAS_IMAGE_H
# include <SDL2/SDL.h>
# define MAX_FILENAME_LENGTH 100
# define NUM_ATLAS_BUCKETS 1

typedef struct AtlasImage	AtlasImage;

struct AtlasImage {
    char		filename[MAX_FILENAME_LENGTH];
    SDL_Rect	rect;
    SDL_Texture	*texture;
    AtlasImage	*next;
};

void initAtlas(AtlasImage *atlasImage);

#endif

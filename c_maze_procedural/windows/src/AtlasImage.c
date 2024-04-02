#include "atlas.h"
#include <stdlib.h> // for strcmp

void initAtlas(AtlasImage *atlases)
{
    memset(atlases, 0, sizeof(AtlasImage) * NUM_ATLAS_BUCKETS);

    atlasTexture = IMG_LoadTexture(app.renderer, "gfx/atlas.png");

    loadAtlasData();
}

static void loadAtlasData(void)
{
    AtlasImage		*atlasImage, *a;
    int				x,
					y,
					w,
					h;
    cJSON			*root;
	cJSON			*node;
    char			*text;
	char			*filename;
    unsigned long	i;

    text = readFile("data/atlas.json");

    root = cJSON_Parse(text);

    for (node = root->child ; node != NULL ; node = node->next)
    {
        filename = cJSON_GetObjectItem(node, "filename")->valuestring;
        x = cJSON_GetObjectItem(node, "x")->valueint;
        y = cJSON_GetObjectItem(node, "y")->valueint;
        w = cJSON_GetObjectItem(node, "w")->valueint;
        h = cJSON_GetObjectItem(node, "h")->valueint;

        i = hashcode(filename) % NUM_ATLAS_BUCKETS;

        a = &atlases[i];

        /* horrible bit to look for the tail */
        while (a->next)
        {
            a = a->next;
        }

        atlasImage = malloc(sizeof(AtlasImage));
        memset(atlasImage, 0, sizeof(AtlasImage));
        a->next = atlasImage;

        STRNCPY(atlasImage->filename, filename, MAX_FILENAME_LENGTH);
        atlasImage->rect.x = x;
        atlasImage->rect.y = y;
        atlasImage->rect.w = w;
        atlasImage->rect.h = h;

        atlasImage->texture = atlasTexture;
    }

    cJSON_Delete(root);

    free(text);
}

AtlasImage *getAtlasImage(AtlasImage *atlases, char *filename)
{
    AtlasImage		*a;
    unsigned long	i;

    i = hashcode(filename) % NUM_ATLAS_BUCKETS;

    for (a = atlases[i].next ; a != NULL ; a = a->next)
    {
        if (strcmp(a->filename, filename) == 0)
        {
            return a;
        }
    }

    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_CRITICAL, "No such atlas image '%s'", filename);
    exit(1);

    return NULL;
}

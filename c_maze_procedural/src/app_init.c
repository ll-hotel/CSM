#include "app.h"
#include <stdio.h>

int	app_init(t_app *app)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (dprintf(2, "Unable to init video subsystem\n"), 1);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	app->window = SDL_CreateWindow("A Maze-ing", \
				SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, \
				app->window_width, app->window_height, \
				SDL_WINDOW_SHOWN);
	if (app->window == NULL)
		return (dprintf(2, "Unable to create window\n"), 1);
	app->surface = SDL_GetWindowSurface(app->window);
	if (!app->surface)
		return (dprintf(2, "Unable to get window surface\n"), 1);
	app->renderer = SDL_CreateRenderer(app->window, -1, SDL_RENDERER_ACCELERATED);
	if (!app->renderer)
		return (dprintf(2, "Unable to create renderer\n"), 1);
	SDL_SetRenderDrawColor(app->renderer, 0x00, 0x00, 0x00, 0xFF);
	return 0;
}

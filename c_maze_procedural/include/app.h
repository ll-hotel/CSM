#ifndef APP_H
# define APP_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_render.h>
# include <SDL2/SDL_surface.h>
# include <SDL2/SDL_video.h>

typedef struct s_app	t_app;

struct	s_app
{
	const int		window_width;
	const int		window_height;
	SDL_Window		*window;
	SDL_Surface 	*surface;
	SDL_Renderer	*renderer;
	int				running;
};

int		app_init(t_app *app);
void	app_render(t_app *app);
void	app_cleanup(t_app *app);
void	app_on_event(SDL_Event *event);
void	app_loop(t_app *app);

#endif

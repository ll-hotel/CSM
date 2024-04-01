#include "app.h"

int	main(void)
{
	t_app	app = {.window_width = 1080, .window_height = 720};

	if (app_init(&app) == 1)
		return (1);

	app_render(&app);
	app_cleanup(&app);
	return (0);
}

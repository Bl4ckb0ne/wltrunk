#define _POSIX_C_SOURCE 200112L

#include <wayland-server.h>

#include <wlr/util/log.h>

#include "wltrunk/backend.h"

struct ts_server
{
	struct wl_display *wl_display;
};

struct ts_server *create_server(void)
{
	struct ts_server *server = malloc(sizeof(struct ts_server));

	server->wl_display = wl_display_create();

	return server;
}

void destroy_server(struct ts_server *server)
{
	wl_display_destroy(server->wl_display);

	free(server);
}

int main(int argc, char **argv)
{
	wlr_log_init(WLR_DEBUG, NULL);

	struct ts_server *server = create_server();
	assert(server);

	struct wlt_backend *backend = create_wlt_backend(server->wl_display);
	assert(backend);

	if (!init_wlt_backend(backend))
	{
		wlr_log(WLR_ERROR, "Failed to init wlt_backend %p", (void*)backend);
		goto end;
	}

	// TODO: init backend

	wl_display_run(server->wl_display);

end:
	destroy_wlt_backend(backend);
	destroy_server(server);

	return 0;
}

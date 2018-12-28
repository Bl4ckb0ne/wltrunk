#define _POSIX_C_SOURCE 200112L

#include <assert.h>
#include <wayland-server.h>

#include <wlr/util/log.h>

#include "wltrunk/backend.h"

struct ts_server
{
	struct wl_display *wl_display;
	struct wl_event_loop *wl_event_loop;
	struct wlt_backend *wlt_backend;
};

struct ts_server *create_server(void)
{
	struct ts_server *server = malloc(sizeof(struct ts_server));

	/* Init Wayland resources */
	server->wl_display = wl_display_create();
	server->wl_event_loop = wl_display_get_event_loop(server->wl_display);

	/* Init wltrunk resources */
	server->wlt_backend = create_wlt_backend(server->wl_display);
	assert(server->wlt_backend);

	return server;
}

void destroy_server(struct ts_server *server)
{
	/* Destroy wltrunk resources */
	destroy_wlt_backend(server->wlt_backend);

	/* Destroy Wayland resources */
	wl_display_destroy(server->wl_display);

	free(server);
}

bool init_server(struct ts_server *server)
{
	struct wlt_backend *backend = server->wlt_backend;
	(void)backend;

	// FIXME: Implement outputs
	return false;

	/*

	wlr_renderer_init_wl_display(backend->wlr_renderer, backend->wl_display);

	backend->wl_socket = wl_display_add_socket_auto(backend->wl_display);
	if (backend->wl_socket == NULL)
	{
		wlr_log(WLR_ERROR, "Unable to create Wayland socket");
		return false;
	}

	wlr_log(WLR_INFO, "Compositor running on Wayland display '%s'",
		backend->wl_socket);
	setenv("_WAYLAND_DISPLAY", backend->wl_socket, true);

	if (wlr_backend_start(backend->wlr_backend) == false)
	{
		wlr_log(WLR_ERROR, "Failed to start wlr_backend");
		return false;
	}

	setenv("WAYLAND_DISPLAY", backend->wl_socket, true);

	return true;
	*/
}

int main(int argc, char **argv)
{
	// Unused
	(void)argc;
	(void)argv[0];

	wlr_log_init(WLR_DEBUG, NULL);

	struct ts_server *server = create_server();
	assert(server);

	if (!init_server(server))
	{
		wlr_log(WLR_ERROR, "Failed to init server");
		destroy_server(server);
		return 1;
	}

	wl_display_run(server->wl_display);

	destroy_server(server);

	return 0;
}

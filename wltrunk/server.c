#include "wltrunk/server.h"

struct wlt_server *create_wlt_server()
{
	struct wlt_server *server = malloc(sizeof(struct wlt_server));
	if (server == NULL)
	{
		wlr_log(WLR_ERROR, "Failed to allocate wlt_server");
		return NULL;
	}

	/* Initializing Wayland resources */
	server->wl_display = wl_display_create();
	assert(server->wl_display);

	server->wl_event_loop = wl_display_get_event_loop(server->wl_display);
	assert(server->wl_event_loop);

	// FIXME: WLR_ALLOC
	wlr_log(WLR_DEBUG, "Creating wlt_server %p", (void*)server);

	return server;
}

void destroy_wlt_server(struct wlt_server *server)
{
	if(server == NULL)
	{
		wlr_log(WLR_ERROR, "Attemting to destroy null wlt_server");
		return;
	}

	// FIXME: WLR_ALLOC
	wlr_log(WLR_DEBUG, "Destroying wlt_server %p", (void*)server);

	wl_display_destroy_clients(server->wl_display);
	wl_display_destroy(server->wl_display);

	free(server);
}

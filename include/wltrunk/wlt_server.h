#ifndef WLT_SERVER_H
#define WLT_SERVER_H

#include <assert.h>
#include <stdlib.h>

#include <wayland-server.h>
#include <wlr/util/log.h>

struct wlt_server
{
	/* Wayland resources */
	struct wl_display *wl_display;
	struct wl_event_loop *wl_event_loop;
};

struct wlt_server *create_wlt_server();
void destroy_wlt_server(struct wlt_server *server);

#endif //WLT_SERVER_H

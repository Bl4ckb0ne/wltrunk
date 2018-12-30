#ifndef WLT_BACKEND_H
#define WLT_BACKEND_H

#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 200112L
#endif // _POSIX_C_SOURCE

#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

#include <wayland-server.h>
#include <wlr/backend.h>
#include <wlr/backend/session.h>
#include <wlr/render/wlr_renderer.h>
#include <wlr/types/wlr_compositor.h>
#include <wlr/types/wlr_output_layout.h>
#include <wlr/types/wlr_screenshooter.h>
#include <wlr/types/wlr_idle.h>
#include <wlr/types/wlr_pointer_constraints_v1.h>
#include <wlr/types/wlr_presentation_time.h>
#include <wlr/types/wlr_wl_shell.h>
#include <wlr/types/wlr_xdg_shell_v6.h>
#include <wlr/types/wlr_xdg_shell.h>
#include <wlr/types/wlr_xdg_output_v1.h>
#include <wlr/types/wlr_layer_shell_v1.h>
#include <wlr/types/wlr_data_device.h>
#include <wlr/util/log.h>
#include <wlr/xwayland.h>

struct wlt_backend
{
	/* Wayland resources */
	struct wl_display *wl_display;

	/* wlroots resources */
	struct wlr_backend *wlr_backend;
	struct wlr_renderer *wlr_renderer;
	struct wlr_compositor *wlr_compositor;
	struct wlr_output_layout *wlr_output_layout;

	struct wlr_screenshooter *wlr_screenshooter;
	struct wlr_idle *wlr_idle;
	struct wlr_pointer_constraints_v1 *wlr_pointer_constraints;
	struct wlr_presentation *wlr_presentation;

	struct wlr_wl_shell *wlr_wl_shell;
	struct wlr_xdg_shell_v6 *wlr_xdg_shell_v6;
	struct wlr_xdg_shell *wlr_xdg_shell;
	struct wlr_xwayland *wlr_xwayland;
	struct wlr_layer_shell_v1 *wlr_layer_shell;

	/* Global resources */
	struct wlr_data_device_manager *wlr_data_device_manager;

	/* Wayland listeners */
	//struct wl_listener new_output; TODO
	struct wl_listener layout_change;
	struct wl_listener pointer_constraint;
};

struct wlt_backend *create_wlt_backend(struct wl_display *display);
void destroy_wlt_backend(struct wlt_backend *backend);

void wlt_layout_change_handler(struct wl_listener *listener, void *data);

void wlt_backend_register_layout_change_handler(struct wlt_backend *backend,
	wl_notify_func_t handler);
void wlt_backend_register_default_handlers(struct wlt_backend *backend);

#endif // WLT_BACKEND_H

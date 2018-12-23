#ifndef WLT_BACKEND_H
#define WLT_BACKEND_H

#include <wlr/backend.h>
#include <wlr/backend/session.h>
#include <wlr/render/wlr_renderer.h>
#include <wlr/types/wlr_compositor.h>
#include <wlr/types/wlr_gamma_control.h>
#include <wlr/types/wlr_gamma_control_v1.h>
#include <wlr/types/wlr_screenshooter.h>
#include <wlr/types/wlr_export_dmabuf_v1.h>
#include <wlr/types/wlr_server_decoration.h>
#include <wlr/types/wlr_xdg_decoration_v1.h>
#include <wlr/types/wlr_gtk_primary_selection.h>
#include <wlr/types/wlr_idle.h>
#include <wlr/types/wlr_idle_inhibit_v1.h>
#include <wlr/types/wlr_input_inhibitor.h>
#include <wlr/types/wlr_input_method_v2.h>
#include <wlr/types/wlr_text_input_v3.h>
#include <wlr/types/wlr_virtual_keyboard_v1.h>
#include <wlr/types/wlr_screencopy_v1.h>
#include <wlr/types/wlr_tablet_v2.h>
#include <wlr/types/wlr_pointer_constraints_v1.h>
#include <wlr/types/wlr_presentation_time.h>
#include <wlr/types/wlr_foreign_toplevel_management_v1.h>
#include <wlr/types/wlr_wl_shell.h>
#include <wlr/types/wlr_xdg_shell_v6.h>
#include <wlr/types/wlr_xdg_shell.h>
#include <wlr/types/wlr_layer_shell_v1.h>
#include <wlr/types/wlr_data_device.h>
#include <wlr/xwayland.h>

#include "wltrunk/server.h"

struct wlt_backend
{
	/* wlroots resources */
	struct wlr_backend *wlr_backend;
	struct wlr_renderer *wlr_renderer;
	struct wlr_compositor *wlr_compositor;
	struct wlr_gamma_control_manager *wlr_gamma_control_manager;
	struct wlr_gamma_control_manager_v1 *wlr_gamma_control_manager_v1;
	struct wlr_screenshooter *wlr_screenshooter;
	struct wlr_export_dmabuf_manager_v1 *wlr_export_dmabuf_manager_v1;
	struct wlr_server_decoration_manager *wlr_server_decoration_manager;
	struct wlr_xdg_decoration_manager_v1 *wlr_xdg_decoration_manager_v1;
	struct wlr_gtk_primary_selection_device_manager
		*wlr_gtk_primary_selection_device_manager;
	struct wlr_idle *wlr_idle;
	struct wlr_idle_inhibit_manager_v1 *wlr_idle_inhibit_manager_v1;
	struct wlr_input_inhibit_manager *wlr_input_inhibit_manager;
	struct wlr_input_method_manager_v2 *wlr_input_method_manager_v2;
	struct wlr_text_input_manager_v3 *wlr_text_input_manager_v3;
	struct wlr_virtual_keyboard_manager_v1 *wlr_virtual_keyboard_manager_v1;
	struct wlr_screencopy_manager_v1 *wlr_screencopy_manager_v1;
	struct wlr_tablet_manager_v2 *wlr_tablet_manager_v2;
	struct wlr_pointer_constraints_v1 *wlr_pointer_constraints;
	struct wlr_presentation *wlr_presentation;
	struct wlr_foreign_toplevel_manager_v1 *wlr_foreign_toplevel_manager_v1;

	struct wlr_wl_shell *wlr_wl_shell;
	struct wlr_xdg_shell_v6 *wlr_xdg_shell_v6;
	struct wlr_xdg_shell *wlr_xdg_shell;
	struct wlr_xwayland *wlr_xwayland;
	struct wlr_layer_shell_v1 *wlr_layer_shell;

	/* Global resources */
	struct wlr_data_device_manager *wlr_data_device_manager;

	/* wltrunk resources */
	struct wlt_server *wlt_server;
};

struct wlt_backend *create_wlt_backend(struct wlt_server *server);
void destroy_wlt_backend(struct wlt_backend *backend);


#endif // WLT_BACKEND_H

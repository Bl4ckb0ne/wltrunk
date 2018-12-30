#ifndef WLT_MANAGER_HANDLER_H
#define WLT_MANAGER_HANDLER_H

#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 200112L
#endif // _POSIX_C_SOURCE

#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

#include <wlr/types/wlr_gamma_control.h>
#include <wlr/types/wlr_gamma_control_v1.h>
#include <wlr/types/wlr_export_dmabuf_v1.h>
#include <wlr/types/wlr_server_decoration.h>
#include <wlr/types/wlr_xdg_decoration_v1.h>
#include <wlr/types/wlr_gtk_primary_selection.h>
#include <wlr/types/wlr_idle_inhibit_v1.h>
#include <wlr/types/wlr_input_inhibitor.h>
#include <wlr/types/wlr_input_method_v2.h>
#include <wlr/types/wlr_text_input_v3.h>
#include <wlr/types/wlr_virtual_keyboard_v1.h>
#include <wlr/types/wlr_screencopy_v1.h>
#include <wlr/types/wlr_tablet_v2.h>
#include <wlr/types/wlr_foreign_toplevel_management_v1.h>
#include <wlr/util/log.h>

struct wlt_manager_handler
{
	struct wlr_gamma_control_manager *wlr_gamma_control_manager;
	struct wlr_gamma_control_manager_v1 *wlr_gamma_control_manager_v1;
	struct wlr_export_dmabuf_manager_v1 *wlr_export_dmabuf_manager_v1;
	struct wlr_server_decoration_manager *wlr_server_decoration_manager;
	struct wlr_xdg_decoration_manager_v1 *wlr_xdg_decoration_manager_v1;
	struct wlr_gtk_primary_selection_device_manager
		*wlr_gtk_primary_selection_device_manager;
	struct wlr_idle_inhibit_manager_v1 *wlr_idle_inhibit_manager_v1;
	struct wlr_input_inhibit_manager *wlr_input_inhibit_manager;
	struct wlr_input_method_manager_v2 *wlr_input_method_manager_v2;
	struct wlr_text_input_manager_v3 *wlr_text_input_manager_v3;
	struct wlr_virtual_keyboard_manager_v1 *wlr_virtual_keyboard_manager_v1;
	struct wlr_screencopy_manager_v1 *wlr_screencopy_manager_v1;
	struct wlr_tablet_manager_v2 *wlr_tablet_manager_v2;
	struct wlr_foreign_toplevel_manager_v1 *wlr_foreign_toplevel_manager_v1;
};

struct wlt_manager_handler *create_wlt_manager_handler(void);
bool init_wlt_manager_handler(struct wlt_manager_handler *manager);
void destroy_wlt_manager_handler(struct wlt_manager_handler *manager);

#endif // WLT_MANAGER_HANDLER_H

#include "wltrunk/manager_handler.h"

struct wlt_manager_handler *create_wlt_manager_handler(void)
{
	struct wlt_manager_handler *manager = malloc(sizeof(
		struct wlt_manager_handler));
	if (manager == NULL)
	{
		wlr_log(WLR_ERROR, "Failed to allocate wlt_manager_handler");
		return NULL;
	}

	if (!init_wlt_manager_handler(manager))
	{
		wlr_log(WLR_ERROR, "Failed to initialize wlt_manager_handler");
		destroy_wlt_manager_handler(manager);
		return NULL;
	}

	return manager;
}

bool init_wlt_manager_handler(struct wlt_manager_handler *manager)
{
	wlr_log(WLR_INFO, "Initializing wlt_manager_handler %p", (void*)manager);
	// FIXME: initialize managers
	memset(manager, 0, sizeof(struct wlt_manager_handler)); // to be removed

	/*
	backend->wlr_gamma_control_manager = wlr_gamma_control_manager_create(
		display);
	assert(backend->wlr_gamma_control_manager);

	backend->wlr_gamma_control_manager_v1 = wlr_gamma_control_manager_v1_create(
		display);
	assert(backend->wlr_gamma_control_manager_v1);

	backend->wlr_export_dmabuf_manager_v1 = wlr_export_dmabuf_manager_v1_create(
		display);
	assert(backend->wlr_export_dmabuf_manager_v1);

	backend->wlr_server_decoration_manager =
		wlr_server_decoration_manager_create(display);
	assert(backend->wlr_server_decoration_manager);

	backend->wlr_xdg_decoration_manager_v1 =
		wlr_xdg_decoration_manager_v1_create(display);
	assert(backend->wlr_xdg_decoration_manager_v1);

	backend->wlr_gtk_primary_selection_device_manager =
		wlr_gtk_primary_selection_device_manager_create(display);
	assert(backend->wlr_gtk_primary_selection_device_manager);

	backend->wlr_idle_inhibit_manager_v1 = wlr_idle_inhibit_v1_create(
		display);
	assert(backend->wlr_idle_inhibit_manager_v1);

	backend->wlr_input_inhibit_manager = wlr_input_inhibit_manager_create(
		display);
	assert(backend->wlr_input_inhibit_manager);

	backend->wlr_input_method_manager_v2 = wlr_input_method_manager_v2_create(
		display);
	assert(backend->wlr_input_method_manager_v2);

	backend->wlr_text_input_manager_v3 = wlr_text_input_manager_v3_create(
		display);
	assert(backend->wlr_text_input_manager_v3);

	backend->wlr_virtual_keyboard_manager_v1 =
		wlr_virtual_keyboard_manager_v1_create(display);
	assert(backend->wlr_virtual_keyboard_manager_v1);

	backend->wlr_screencopy_manager_v1 = wlr_screencopy_manager_v1_create(
		display);
	assert(backend->wlr_screencopy_manager_v1);

	backend->wlr_tablet_manager_v2 = wlr_tablet_v2_create(display);
	assert(backend->wlr_tablet_manager_v2);

	backend->wlr_foreign_toplevel_manager_v1 =
		wlr_foreign_toplevel_manager_v1_create(display);
	assert(backend->wlr_foreign_toplevel_manager_v1);
	 */
	return true;
}

void destroy_wlt_manager_handler(struct wlt_manager_handler *manager)
{
	// FIXME: properly delete managers
	free(manager);
}

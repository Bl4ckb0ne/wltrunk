#include "wltrunk/backend.h"

struct wlt_backend *create_wlt_backend(struct wl_display *display)
{
	struct wlt_backend *backend = malloc(sizeof(struct wlt_backend));
	if (backend == NULL)
	{
		wlr_log(WLR_ERROR, "Failed to allocate wlt_backend");
		return NULL;
	}

	backend->wlr_backend = wlr_backend_autocreate(display, NULL);
	if (backend->wlr_backend == NULL)
	{
		wlr_log(WLR_ERROR, "Failed to create wlr_backend");
		free(backend);
		return NULL;
	}

	backend->wlr_renderer = wlr_backend_get_renderer(backend->wlr_backend);
	assert(backend->wlr_backend);

	backend->wlr_compositor = wlr_compositor_create(display,
		backend->wlr_renderer);
	assert(backend->wlr_compositor);

	backend->wlr_gamma_control_manager = wlr_gamma_control_manager_create(
		display);
	assert(backend->wlr_gamma_control_manager);

	backend->wlr_gamma_control_manager_v1 = wlr_gamma_control_manager_v1_create(
		display);
	assert(backend->wlr_gamma_control_manager_v1);

	backend->wlr_screenshooter = wlr_screenshooter_create(display);
	assert(backend->wlr_screenshooter);

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

	backend->wlr_idle = wlr_idle_create(display);
	assert(backend->wlr_idle);

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

	backend->wlr_pointer_constraints = wlr_pointer_constraints_v1_create(
		display);
	assert(backend->wlr_pointer_constraints);

	/*
	// FIXME: user defined
	backend->pointer_constraint.notify = handle_pointer_constraint;
	wl_signal_add(&backend->wlr_pointer_constraints->events.new_constraint,
		&backend->pointer_constraint);
	*/

	backend->wlr_presentation = wlr_presentation_create(display,
		backend->wlr_backend);
	assert(backend->wlr_presentation);

	backend->wlr_foreign_toplevel_manager_v1 =
		wlr_foreign_toplevel_manager_v1_create(display);
	assert(backend->wlr_foreign_toplevel_manager_v1);

	// FIXME: Implement wayland shell
	backend->wlr_wl_shell = NULL;

	// FIXME: Implement xdg shell v6
	backend->wlr_xdg_shell_v6 = NULL;

	// FIXME: Implement xdg shell
	backend->wlr_xdg_shell = NULL;

	// FIXME: Implement xwayland shell
	backend->wlr_xwayland = NULL;

	// FIXME: Implement layer shell
	backend->wlr_layer_shell = NULL;

	backend->wlr_data_device_manager = wlr_data_device_manager_create(display);

	// FIXME: WLR_ALLOC
	wlr_log(WLR_DEBUG, "Creating wlt_backend %p", (void*)backend);

	return backend;
}

bool init_wlt_backend(struct wlt_backend *backend)
{
	wlr_log(WLR_DEBUG, "Initializing wlt_backend %p ...", (void*)backend);

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

	wlr_log(WLR_DEBUG, "wlt_backend %p initialized", (void*)backend);
	return true;
}

void destroy_wlt_backend(struct wlt_backend *backend)
{
	if(backend == NULL)
	{
		wlr_log(WLR_ERROR, "Attemting to destroy null wlt_backend");
		return;
	}

	// FIXME: WLR_ALLOC
	wlr_log(WLR_DEBUG, "Destroying wlt_backend %p", (void*)backend);

	wlr_backend_destroy(backend->wlr_backend);

	free(backend);
}

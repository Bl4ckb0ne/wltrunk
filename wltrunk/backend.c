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
	assert(backend->wlr_renderer);

	backend->wlr_compositor = wlr_compositor_create(display,
		backend->wlr_renderer);
	assert(backend->wlr_compositor);

	backend->wlr_screenshooter = wlr_screenshooter_create(display);
	assert(backend->wlr_screenshooter);

	backend->wlr_idle = wlr_idle_create(display);
	assert(backend->wlr_idle);

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

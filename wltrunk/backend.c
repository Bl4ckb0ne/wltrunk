#include "wlt_trunk/wlt_backend.h"

struct wlt_backend *create_wlt_backend(struct wlt_server *server)
{
	struct wlt_backend *backend = malloc(sizeof(struct wlt_backend));
	if (backend == NULL)
	{
		wlr_log(WLR_ERROR, "Failed to allocate wlt_backend");
		return NULL;
	}

	// FIXME: WLR_ALLOC
	wlr_log(WLR_DEBUG, "Creating wlt_backend %p", (void*)server);

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

	free(backend);
}

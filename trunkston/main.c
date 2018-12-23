#include "wltrunk/server.h"
#include "wltrunk/backend.h"

int main(int argc, char **argv)
{
	struct wlt_server *server = create_wlt_server();
	assert(server);

	struct wlt_backend *backend = create_wlt_backend(server);
	assert(backend);

	return 0;
}

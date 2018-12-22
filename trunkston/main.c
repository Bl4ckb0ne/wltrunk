#include "wltrunk/wlt_server.h"

int main(int argc, char **argv)
{
	struct wlt_server *server = create_wlt_server();
	assert(server);

	return 0;
}

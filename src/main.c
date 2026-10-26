#include <stdint.h>
#include <stdio.h>

#include <wayland-client-core.h>
#include <wayland-client-protocol.h>
#include <wayland-client.h>

static void registry_handle_global(void* data, struct wl_registry* registry,
				   uint32_t name, const char* interface, uint32_t version) {
	printf("interface: '%s', version: %d, name: %d\n",
	       interface, version, name);
}

static void registry_handle_global_remove(void *data, struct wl_registry *registry,
					  uint32_t name) {
	//blank?
}

static const struct wl_registry_listener registry_listener = {
	.global = registry_handle_global,
	.global_remove = registry_handle_global_remove
};

int main(void) {
	printf("guicube!\n");

	struct wl_display* display = wl_display_connect(NULL);
	if(!display) {
		fprintf(stderr, "main.c:8 connection failed\n");
		return 1;
	}

	return 0;
}

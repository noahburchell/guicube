#include <stdio.h>

#include <wayland-client-core.h>
#include <wayland-client.h>

int main(void) {
	printf("guicube!\n");

	struct wl_display* display = wl_display_connect(NULL);
	if(!display) {
		fprintf(stderr, "main.c:8 connection failed\n");
	}

	while(wl_display_dispatch(display) != -1) {
		// do something
	}

	return 0;
}

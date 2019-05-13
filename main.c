#include <pebble.h>

static Window *s_main_window;

static void main_window_load(Window *window) {

}

static void main_window_unload(Window *window) {

}

static void init() {
	s_main_window = window_create();

	// Compound literals! \ovo/
	window_set_window_handlers(s_main_window, (WindowHandlers) {
		.load = main_window_load,
		.unload = main_window_unload
	});

 	window_stack_push(s_main_window, true);
}

static void deinit() {

}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
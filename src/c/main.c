#include <pebble.h>

static Window *s_main_window;
static TextLayer *s_time_layer;

static void main_window_load(Window *window) {

	// Lets get the window later for later
	Layer *window_layer = window_get_root_layer(window);

	// Get the sizes for the text layer
	GRect bounds = layer_get_bounds(window_layer);
	
	// Make a text layer
	s_time_layer = text_layer_create(
		GRect(0, PBL_IF_ROUND_ELSE(58, 52), bounds.size.w, 50));

	// Set some properties for the text layer
	text_layer_set_background_color(s_time_layer, GColorClear);
	text_layer_set_text_color(s_time_layer, GColorBlack);
	text_layer_set_text(s_time_layer, "00:00");
	text_layer_set_font(
		s_time_layer,
		fonts_get_system_font(FONT_KEY_BITHAM_42_BOLD));
	text_layer_set_text_alignment(s_time_layer, GTextAlignmentCenter);

	// Attach it to the window layer
	layer_add_child(window_layer, text_layer_get_layer(s_time_layer));	
}

static void main_window_unload(Window *window) {
	text_layer_destroy(s_time_layer);
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
#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window {
	Lines_window(Point xy, int w, int h, const string& title );

	bool wait_for_button();

private:
	Open_polyline lines;
	
	Button next_button;
	Button quit_button;
	In_box next_x;
	In_box next_y;
	Out_box xy_out;
	Menu color_menu;
	Menu style_menu;
	Button menu_button;
	Button second_menu_button;

	
	void hide_color_menu() {
		color_menu.hide();
		menu_button.show();
	}

	void hide_style_menu() {
		style_menu.hide();
		second_menu_button.show();
	}
	
	void next();
	void quit();

	
};
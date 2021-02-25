/*
	g++ ch12drill.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;

	Point tl {100,100}; //top left corner


	Simple_window win(tl, 600, 400, "My window");

	//12.7.3 Axis
	Axis x {Axis::x, Point{20,380}, 280, 10, "x"};
	Axis y {Axis::y, Point{20,380}, 280, 10, "y"};

	//12.7.4 Function
	Function sine {sin, 0, 100, Point{20, 75}, 1000, 50, 50};

	//12.7.5 Polygon
	Polygon poly;
	poly.add(Point{40,300});
	poly.add(Point{140, 300});
	poly.add(Point{90,200});
	poly.set_color(Color::blue);
	poly.set_style(Line_style::dot);

	//12.7.6 Rectangle
	Rectangle r {Point{40, 300}, 100, 50};
	Closed_polyline poly_rect;
	poly_rect.add(Point{100,20});
	poly_rect.add(Point{250,20});
	poly_rect.add(Point{250,70});
	poly_rect.add(Point{100,70});
	poly_rect.add(Point{50,45});

	//12.7.7 Fill
	r.set_fill_color(Color::red);
	poly_rect.set_style(Line_style(Line_style::dash,2));
	poly_rect.set_fill_color(Color::cyan);

	//12.7.8 Text
	Text t {Point{70,50},"Hello, Prog1!"};
	t.set_font(Font::courier_bold);
	t.set_font_size(20);

	//12.7.9 Image
	Image pic {Point{200, 100},"badge.jpg"};

    //12.7.10
    Circle c {Point{100,200},50};
    Mark m {Point{100,200},'x'};


	win.attach(x);
	win.attach(y);
	win.attach(sine);
	win.attach(poly);
	win.attach(r);
	win.attach(poly_rect);
	win.attach(t);
	win.attach(pic);
    win.attach(c);
    win.attach(m);
	win.wait_for_button();

}

/*
    g++ ch15drill.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill `fltk-config --ldflags --use-images`
*/

#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

double one(double x) {return 1;}

double slope(double x) {return x/2;}

double square(double x) {return x*x;}

double sloping_cos(double x) {return slope(x) + cos(x);}

int main() {

    using namespace Graph_lib;

    int x_max = 600;
    int y_max = 600;
    int x_orig = x_max/2;
    int y_orig = y_max/2;
    
    Simple_window win (Point{100,100}, x_max, y_max, "Function graphs");

    Axis x {Axis::x, Point{100,y_orig}, 400, 20, "1 == 20 pixels"};
    Axis y {Axis::y, Point{x_orig,500}, 400, 20, "1 == 20 pixels"};

    x.set_color(Color::red);
    y.set_color(Color::red);

    win.attach(x);
    win.attach(y);

    int r_min = -10;
    int r_max = 11;
    int n_points = 400;
    int x_scale = 20;
    int y_scale = 20;

    Point orig {x_orig, y_orig};

    Function one_f (one, r_min, r_max, orig, n_points, x_scale, y_scale);

    Function slope_f (slope, r_min, r_max, orig, n_points, x_scale, y_scale);
    Text t {Point{100, 380}, "x/2"};

    Function square_f (square, r_min, r_max, orig, n_points, x_scale, y_scale);

    Function cos_f (cos, r_min, r_max, orig, n_points, x_scale, y_scale);
    cos_f.set_color(Color::blue);

    Function sloping_cos_f (sloping_cos, r_min, r_max, orig, n_points, x_scale, y_scale);


    win.attach(one_f);
    win.attach(slope_f);
    win.attach(t);
    win.attach(square_f);
    win.attach(cos_f);
    win.attach(sloping_cos_f);
    win.wait_for_button();
}

/*
    g++ exercises1-9.cpp Simple_window.cpp Graph.cpp Window.cpp GUI.cpp -o exercises `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"

int main() {

    int win_w = 1280;
    int win_h = 720;

    using namespace Graph_lib;


    Simple_window win(Point{100, 100}, win_w, win_h, "Exercises");

    //1.
    Rectangle r {Point{10,10}, 100, 50};
    r.set_color(Color::blue);

    Polygon poly;
    poly.add(Point{120, 10});
    poly.add(Point{220, 10});
    poly.add(Point{220, 60});
    poly.add(Point{120, 60});
    poly.set_color(Color::red);

    //2.
    Rectangle r2 {Point{230, 10}, 100, 30};
    Text t {Point{255,30}, "Howdy!"};

    //3.
    Text n {Point{340, 120}, "N"};
    n.set_font_size(150);
    n.set_font(Font::times_bold);
    n.set_color(Color::dark_blue);
    Text d {Point{480, 120}, "D"};
    d.set_font_size(150);
    d.set_font(Font::times_bold);
    d.set_color(Color::dark_cyan);

    //4.
    Rectangle s1 {Point{10, 70}, 50, 50};
    s1.set_fill_color(Color::white);
    Rectangle s2 {Point{60, 70}, 50, 50};
    s2.set_fill_color(Color::red);
    Rectangle s3 {Point{110, 70}, 50, 50};
    s3.set_fill_color(Color::white);
    Rectangle s4 {Point{10, 120}, 50, 50};
    s4.set_fill_color(Color::red);
    Rectangle s5 {Point{60, 120}, 50, 50};
    s5.set_fill_color(Color::white);
    Rectangle s6 {Point{110, 120}, 50, 50};
    s6.set_fill_color(Color::red);
    Rectangle s7 {Point{10, 170}, 50, 50};
    s7.set_fill_color(Color::white);
    Rectangle s8 {Point{60, 170}, 50, 50};
    s8.set_fill_color(Color::red);
    Rectangle s9 {Point{110, 170}, 50, 50};
    s9.set_fill_color(Color::white);

    //5.
    int inch=96;
    Rectangle r3 {Point{190, 150}, win_w/3*2, win_h/4*3};
    Rectangle frame {Point {190-inch/8, 150-inch/8}, win_w/3*2+inch/4, win_h/4*3+inch/4};
    frame.set_color(Color::red);
    frame.set_style(Line_style(Line_style::solid, inch/4));

    //6.
    Rectangle r4 {Point{1240, 30}, 100, 50}; //"levágja" ami nem fér el az ablakra
    r4.set_fill_color(Color::dark_red); //láthatóság miatt
    Simple_window win2(Point{1400,8000}, win_w, win_h, "Does not fit"); //Mindenképp megjelenik teljesen a képernyőn teljes méretében

    //7.
    int x=win_w/2;
    int y=win_h/2;
    Rectangle house {Point{x-60, y-60}, 120, 120};
    house.set_fill_color(Color::yellow);
    Rectangle door {Point{x-15, y+10},30, 50};
    door.set_fill_color(Color::green);
    Rectangle w1 {Point{x-50, y-30}, 30, 30};
    w1.set_fill_color(Color::cyan);
    Rectangle w2 {Point{x+20, y-30}, 30, 30};
    w2.set_fill_color(Color::cyan);
    Polygon roof;
    roof.add(Point{x-60, y-60});
    roof.add(Point{x+60, y-60});
    roof.add(Point{x, y-100});
    roof.set_fill_color(Color::red);
    Rectangle chimney {Point{x+20, y-100}, 20, 40};
    chimney.set_fill_color(Color::red);

    //8.
    Circle c1 {Point{x-400, y-80},30};
    c1.set_color(Color::blue);
    c1.set_style(Line_style(Line_style::solid, 5));
    Circle c2 {Point{x-330, y-80},30};
    c2.set_color(Color::black);
    c2.set_style(Line_style(Line_style::solid, 5));
    Circle c3 {Point{x-260, y-80},30};
    c3.set_color(Color::red);
    c3.set_style(Line_style(Line_style::solid, 5));
    Circle c4 {Point{x-365, y-50},30};
    c4.set_color(Color::yellow);
    c4.set_style(Line_style(Line_style::solid, 5));
    Circle c5 {Point{x-295, y-50},30};
    c5.set_color(Color::green);
    c5.set_style(Line_style(Line_style::solid, 5));

    //9.
    Simple_window win3(Point{1500, 100}, 500, 400, "Badge");
    Image ii {Point{0,0}, "badge.jpg"};
    Text t2 {Point{400, 30}, "Badge"};



    win.attach(r);
    win.attach(poly);
    win.attach(r2);
    win.attach(t);
    win.attach(n);
    win.attach(d);
    win.attach(s1);
    win.attach(s2);
    win.attach(s3);
    win.attach(s4);
    win.attach(s5);
    win.attach(s6);
    win.attach(s7);
    win.attach(s8);
    win.attach(s9);
    win.attach(r3);
    win.attach(frame);
    win.attach(r4);
    win.attach(house);
    win.attach(door);
    win.attach(w1);
    win.attach(w2);
    win.attach(chimney);
    win.attach(roof);
    win.attach(c1);
    win.attach(c2);
    win.attach(c3);
    win.attach(c4);
    win.attach(c5);
    win3.attach(ii);
    win3.attach(t2);
    win.wait_for_button();
}
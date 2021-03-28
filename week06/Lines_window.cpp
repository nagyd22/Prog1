#include "Lines_window.h"

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window{xy,w,h,title},
    next_button{Point{x_max()-300,0}, 150, 40, "Next point",
        [](Address, Address pw) {reference_to<Lines_window>(pw).next();}},
    
    quit_button{Point{x_max()-150,0}, 150, 40, "Quit",
        [](Address, Address pw) {reference_to<Lines_window>(pw).quit();}},

    next_x{Point{300,0}, 50, 40, "next x:"},
    next_y{Point{450,0}, 50, 40, "next y:"},
    xy_out{Point{100,0}, 100, 40, "current (x,y):"},


    color_menu{ Point{x_max()-150,120},150,40,Menu::vertical,"color"},

    menu_button{ Point{x_max()-150,80},150,40, "color menu", [](Address, Address adr) {
    reference_to<Lines_window>(adr).color_menu.show();
    }},

    style_menu{ Point{x_max()-150,320},150,40,Menu::vertical,"style" },

    second_menu_button{ Point{x_max()-150,280},150,40, "style menu", [](Address, Address adr) {
    reference_to<Lines_window>(adr).style_menu.show();

    } }

{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    xy_out.put("no point");
    attach(lines);

    
    color_menu.attach(new Button{ Point{0,0},0,0,"red",[](Address, Address adr) 
    {
        reference_to<Lines_window>(adr).lines.set_color(Color::red);  
        reference_to<Lines_window>(adr).hide_color_menu();
        reference_to<Lines_window>(adr).redraw();
    } });

    color_menu.attach(new Button{ Point{0,0},0,0,"blue",[](Address, Address adr) 
    {
        reference_to<Lines_window>(adr).lines.set_color(Color::blue);
        reference_to<Lines_window>(adr).hide_color_menu();
        reference_to<Lines_window>(adr).redraw();
    } });

    color_menu.attach(new Button{ Point{0,0},0,0,"black",[](Address, Address adr) 
    {
        reference_to<Lines_window>(adr).lines.set_color(Color::black);
        reference_to<Lines_window>(adr).hide_color_menu();
        reference_to<Lines_window>(adr).redraw();
    } });

    style_menu.attach(new Button{ Point{0,0},0,0,"dot",[](Address, Address adr) 
    {
     reference_to<Lines_window>(adr).lines.set_style(Line_style::dot);
     reference_to<Lines_window>(adr).hide_style_menu();
     reference_to<Lines_window>(adr).redraw();
    } });

    style_menu.attach(new Button{ Point{0,0},0,0,"solid",[](Address, Address adr) 
    {
     reference_to<Lines_window>(adr).lines.set_style(Line_style::solid);
     reference_to<Lines_window>(adr).hide_style_menu();
     reference_to<Lines_window>(adr).redraw();
    } });

    style_menu.attach(new Button{ Point{0,0},0,0,"dash",[](Address, Address adr) 
    {
     reference_to<Lines_window>(adr).lines.set_style(Line_style::dash);
     reference_to<Lines_window>(adr).hide_style_menu();
     reference_to<Lines_window>(adr).redraw();
    } });


    attach(color_menu);
    color_menu.hide();
    attach(style_menu);
    style_menu.hide();
    attach(menu_button);
    attach(second_menu_button);
        
}

void Lines_window::quit()
{
    hide();
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point{x,y});

    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

    redraw();
}
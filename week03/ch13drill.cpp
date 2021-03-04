/*
	g++ ch13drill.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ch13drill `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;

    //1.
    Simple_window win (Point{100,100}, 800, 1000, "Chapter 13 drill");


    //2.
    int grid_size=800;
    int onesquare=100;

    Lines grid;
    for (int i = onesquare; i <= grid_size; i+=onesquare)
    {
        grid.add(Point{i,0}, Point{i, grid_size});
    }
    for (int j= onesquare; j<= grid_size; j+=onesquare) 
    {
        grid.add(Point{0, j}, Point{grid_size, j});
    }

    win.attach(grid);


    //3.
    for(int i=0; i < 8; i++)
    {
        for(int j=0; j < 8; j++)
        {
            if(i==j)
            {
                Rectangle * rec = new Rectangle {Point{i*100, j*100}, onesquare, onesquare};
                rec->set_color(Color::red);
                win.attach(*rec);
            }
        }
    }


    //4.
    Image pic1{Point{300,0}, "200x200.jpg"};
    Image pic2{Point{0,500}, "200x200.jpg"};
    Image pic3{Point{300,600}, "200x200.jpg"};

    win.attach(pic1);
    win.attach(pic2);
    win.attach(pic3);


    //5.
    for (int i=0; i<grid_size; i+=onesquare)
    {
        for (int j = 0; j < grid_size; j+=onesquare)
        {
            Image pic4{Point{j,i}, "100x100.jpg"};
            win.attach(pic4);
            win.wait_for_button();
        }
        
    }

}




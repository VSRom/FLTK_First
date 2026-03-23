#include "PPP/Point.h"
#include "PPP/Simple_window.h"
#include "PPP/Graph.h"
#include "PPP/GUI.h"
#include "PPP/Window.h"

//=======================================================================================================
int main()
{
	Point tl(100, 100); // левый верхний угол нашего окна
	Simple_window win(tl, 600, 400, "MyWindow");
	Axis xa(Axis::x, Point(20, 300), 280, 10, "x axis"); // создаем
	Axis ya(Axis::y, Point(20, 300), 280, 10, "y axis");
	ya.set_color(Color::red);
	ya.label.set_color(Color::dark_green);

	xa.set_color(Color::red);
	xa.label.set_color(Color::dark_green);

	win.attach(ya);
	win.attach(xa);

	Function sine(sin, 0, 100, Point(20, 150), 1000, 50, 50); // график синуса
	win.attach(sine);
	sine.set_color(Color::dark_green);

	Polygon poly;
	poly.add(Point(400, 192));
	poly.add(Point(250, 110));
	poly.add(Point(350, 150));

	poly.set_color(Color::red);
	poly.set_style(Line_style::dash);
	win.attach(poly);

	Rectangle r(Point(200, 200), 100, 50); // левый верхний угол,
	// ширина, высота
	win.attach(r);

	Closed_polyline poly_rect;
	poly_rect.add(Point(100, 50));
	poly_rect.add(Point(200, 50));
	poly_rect.add(Point(200, 100));
	poly_rect.add(Point(100, 100));
	poly_rect.add(Point(50, 75));
	win.attach(poly_rect);

	r.set_fill_color(Color::yellow); // цвет внутри прямоугольника
	poly.set_style(Line_style(Line_style::dash, 4));
	poly_rect.set_style(Line_style(Line_style::dash, 2));
	poly_rect.set_fill_color(Color::green);

	Text t(Point(150, 150), "Hello, graphical world!");
	win.attach(t);
	t.set_font(Font::times_bold);
	t.set_font_size(20);

	Image ii(Point(100, 50), "image.jpg"); // файл 400×212 пикселей
	// в формате jpg
	win.attach(ii);
	ii.move(100, 200);
	Circle c(Point(200, 320), 50);
	Ellipse e(Point(250, 320), 75, 25);
	e.set_color(Color::dark_red);
	Mark m(Point(100, 200), 'x');
	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max()
		<< "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes(Point(100, 20), oss.str());
	Image cal(Point(225, 225), "snow_cpp.gif");
	// формат gif
	cal.set_mask(Point(40, 40), 200, 150);
	// в центре
	win.attach(c);
	win.attach(m);
	win.attach(e);
	win.attach(sizes);
	win.attach(cal);

	win.set_label("MyWindow #12"); // изменяем метку окна
	win.wait_for_button(); // изобразить!
}
//=======================================================================================================
/*
//=======================================================================================================
	V	2. Добавьте примеры из раздела 12.7 один за другим, сравнивая их друг с другом.
//=======================================================================================================
	V	3. Выполните программу, внеся небольшие изменения (например, измените цвет, местоположение фигур или количество точек) в каждом из примеров.
//=======================================================================================================
*/

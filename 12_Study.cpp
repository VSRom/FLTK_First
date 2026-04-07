#include "PPP/Point.h"
#include "PPP/Simple_window.h"
#include "PPP/Graph.h"
#include "PPP/GUI.h"
#include "PPP/Window.h"
//=======================================================================================================

//=======================================================================================================
int main()
{
	Simple_window win9I(Point(100, 100), 800, 800, "Hello");


	win9I.wait_for_button();
}
//=======================================================================================================
/*
//=======================================================================================================
	V	5. Определите функции из упр. 4 для классов Circle и Ellipse.
Поместите точки соединения на границах и внутри этих фигур,
но не за пределами окаймляющего их прямоугольника.
//=======================================================================================================
Point n(Circle &c)
{
	Point t(c.center());
	t.y -= c.radius();
	return t;
}
Point s(Circle &c)
{
	Point t(c.center());
	t.y += c.radius();
	return t;
}
Point e(Circle &c)
{
	Point t(c.center());
	t.x += c.radius();
	return t;
}
Point w(Circle &c)
{
	Point t(c.center());
	t.x -= c.radius();
	return t;
}
Point center(Circle &c)
{
	Point t(c.center());
	return t;
}
Point ne(Circle &c)		//45a
{
	Point t(c.center());
	double angle = 45;
	angle = angle * PI / 180;
	t.x += c.radius() * sin(angle);
	t.y -= c.radius() * cos(angle);
	return t;
}
Point se(Circle &c)		//135a
{
	Point t(c.center());
	double angle = 135;
	angle = angle * PI / 180;
	t.x -= c.radius() * sin(angle);
	t.y += c.radius() * cos(angle);

	return t;
}
Point sw(Circle &c)		//225a
{
	Point t(c.center());
	double angle = 225;
	angle = angle * PI / 180;
	t.x -= c.radius() * sin(angle);
	t.y += c.radius() * cos(angle);

	return t;
}
Point nw(Circle &c)		//315a
{
	Point t(c.center());
	double angle = 315;
	angle = angle * PI / 180;
	t.x += c.radius() * sin(angle);
	t.y -= c.radius() * cos(angle);

	return t;
}
//=======================================================================================================
Point n(Ellipse &e)
{
	Point t(e.center());
	t.y -= e.minor();
	return t;
}
Point s(Ellipse &e)
{
	Point t(e.center());
	t.y += e.minor();
	return t;
}
Point e(Ellipse &e)
{
	Point t(e.center());
	t.x += e.major();
	return t;
}
Point w(Ellipse &e)
{
	Point t(e.center());
	t.x -= e.major();
	return t;
}
Point center(Ellipse &e)
{
	Point t(e.center());
	return t;
}
Point ne(Ellipse &e)		//45a
{
	Point t(e.center());
	double angle = 45;
	angle = angle * PI / 180;
	t.x += e.major() * sin(angle);
	t.y -= e.minor() * cos(angle);
	return t;
}
Point se(Ellipse &e)		//135a
{
	Point t(e.center());
	double angle = 135;
	angle = angle * PI / 180;
	t.x -= e.major() * sin(angle);
	t.y += e.minor() * cos(angle);

	return t;
}
Point sw(Ellipse &e)		//225a
{
	Point t(e.center());
	double angle = 225;
	angle = angle * PI / 180;
	t.x -= e.major() * sin(angle);
	t.y += e.minor() * cos(angle);

	return t;
}
Point nw(Ellipse &e)		//315a
{
	Point t(e.center());
	double angle = 315;
	angle = angle * PI / 180;
	t.x += e.major() * sin(angle);
	t.y -= e.minor() * cos(angle);

	return t;
}

//=======================================================================================================
	V	4. Определите функции n(), s(), e(), w(), center(), ne(), se(), sw() и nw().
Каждая из них должна получать аргумент типа Rectangle и возвращать объект типа Point.
Эти функции должны определять точки соединения, расположенные на границах и внутри прямоугольника.
Например, nw(r) — это левый верхний угол объекта класса Rectangle с именем r.
//=======================================================================================================
Point n(Rectangle &r)
{
	Point t(r.po());
	t.y += r.width() / 2;

	return t;
}
Point s(Rectangle &r)
{
	Point t(r.po());
	t.x += r.width();
	t.y += r.height() / 2;

	return t;
}
Point e(Rectangle &r)
{
	Point t(r.po());
	t.x += r.width() / 2;
	t.y += r.height();

	return t;
}
Point w(Rectangle &r)
{
	Point t(r.po());
	t.x += r.width() / 2;

	return t;
}
Point center(Rectangle &r)
{
	Point t(r.po());
	t.x += r.width() / 2;
	t.y += r.height() / 2;

	return t;
}
Point ne(Rectangle &r)
{
	Point t(r.po());
	t.y += r.height();

	return t;
}
Point se(Rectangle &r)
{
	Point t(r.po());
	t.x += r.width();
	t.y += r.height();

	return t;
}
Point sw(Rectangle &r)
{
	Point t(r.po());
	t.x += r.width();

	return t;
}
Point nw(Rectangle &r)
{
	return r.po();
}
//=======================================================================================================
	V	3. Определите класс Arrow, рисующий стрелки.

	Arrow ar(tl1, tl2, 100, 0);
	ar.set_color(Color::dark_green);
	ar.set_style(Line_style(Line_style::solid, 10));
	win9I.attach(ar);
//=======================================================================================================
	V	2. Нарисуйте окно с закругленными углами. Определите класс Box, состоящий из четырех линий и четырех дуг.

	Point tl1(50, 225);
	Point tl2(50, 475);

	Point tl3(75, 500);
	Point tl4(375, 500);

	Point tl5(400, 475);
	Point tl6(400, 225);

	Point tl7(375, 200);
	Point tl8(75, 200);

	Arc arc1(Point(75, 225), 25, 25, 90, 180);

	Arc arc2(Point(75, 465), 25, 25, 180, 270);

	Arc arc3(Point(365, 465), 25, 25, 270, 360);

	Arc arc4(Point(365, 225), 25, 25, 0, 90);

	Box box(tl1, tl2, tl3, tl4, tl5, tl6, tl7, tl8, arc1, arc2, arc3, arc4);
	box.set_color(Color::red);
	box.set_style(Line_style(Line_style::solid, 20));


//=======================================================================================================
	V	1. Определите класс Arc, рисующий часть эллипса.Подсказка: fl_arc().

	Arc arc(Point(200, 200), 100, 150, 30, 290);
	arc.set_style(Line_style(Line_style::solid, 2));
	arc.set_color(Color::dark_green);
	win9I.attach(arc);
	*/
//=======================================================================================================
/*
//=======================================================================================================
	//				Task:2
//										int x_size = win3.x_max();
//										int y_size = win3.y_max();
//										int xy_grid = 100;
//									
//										Lines grid;
//										for (int x = xy_grid; x < x_size; x += xy_grid)
//											grid.add(Point(x, 0), Point(x, y_size));
//										
//										for (int y = xy_grid; y < y_size; y += xy_grid)
//											grid.add(Point(0, y), Point(x_size, y));
//									
//										grid.set_style(Line_style(Line_style::solid, 2));
//										grid.set_color(Color(99));
//									
//										win3.attach(grid);
	//				Task:3
//					Simple_window win3(Point(100, 100), 800, 800, "Two lines");
//					int x_rect = 0;
//					int move_rect = 50;
//					int x_size = win3.x_max();
//					int y_size = win3.y_max();
//					win3.color(Color::black);
//				
//					for (int x = x_rect; x < x_size && x < y_size; x += move_rect)
//					{
//						Rectangle rect(Point(x, x), 50, 50);
//						rect.set_style(Line_style(Line_style::solid, 2));
//						rect.set_color(Color(99));
//						rect.set_fill_color(Color::red);
//						win3.attach(rect);
//					}
//				
//					win3.wait_for_button();
//				}
	////////////////////////////////////////////////////////////////////////////////////////////////
//												Vector_ref<Rectangle> rect;
//												Rectangle x(Point(100, 200), Point(200, 300));
//												rect.push_back(x);
//												rect.push_back(new Rectangle(Point(50, 60), Point(80, 90)));
//											
//												for (int i = 0; i < rect.size(); ++i)
//												{
//													rect[i].move(10, 10);
//													win3.attach(rect[i]);
//												}
//					
//									Vector_ref<Rectangle> vr;
//								
//									for (int i = 0; i < 16; ++i)
//									{
//										for (int j = 0; j < 16; ++j)
//										{
//											vr.push_back(new Rectangle(Point(i * 40, j * 40), 40, 40));
//					
//											vr[vr.size() - 1].set_fill_color(Color(i * 16 + j));
//										}
//									}
//=======================================================================================================/*
//											// рисуем две линии
//											int x_size = win3.x_max(); // определяем размер нашего окна
//											int y_size = win3.y_max();
//											int x_grid = 80;
//											int y_grid = 40;
//											
//											Lines grid;
//											for (int x = x_grid; x < x_size; x += x_grid)
//												grid.add(Point(x, 0), Point(x, y_size)); // вертикальная линия
//											
//											for (int y = y_grid; y < y_size; y += y_grid)
//												grid.add(Point(0, y), Point(x_size, y)); // горизонтальная линия
//											
//											grid.set_style(Line_style(Line_style::dash, 2));
//											grid.set_color(Color(99));
//											
//											Closed_polyline cpl;
//											cpl.add(Point(100, 100));
//											cpl.add(Point(150, 200));
//											cpl.add(Point(250, 250));
//											cpl.add(Point(300, 200));
//											cpl.add(Point(100, 250));
//											cpl.set_style(Line_style(Line_style::solid, 4));
//											cpl.set_color(Color::red);
//											win3.attach(cpl);
//											
//											//	Polygon poly;
//											//	poly.add(Point(100, 100));
//											//	poly.add(Point(150, 200));
//											//	poly.add(Point(250, 250));
//											//	poly.add(Point(300, 200));
//											//	poly.set_style(Line_style(Line_style::solid, 4));
//											//	poly.set_color(Color::red);
//											//	win3.attach(poly);
//											
//											Text t(Point(200, 200), "A closed polyline that isn't a polygon");
//											t.set_color(Color::blue);
//											win3.attach(t);
//											
//											win3.attach(grid);

//								Rectangle rect00(Point(150, 100), 200, 100);
//								Rectangle rect11(Point(50, 50), Point(250, 150));
//								Rectangle rect12(Point(50, 150), Point(250, 250));
//								Rectangle rect21(Point(250, 50), 200, 100);
//								Rectangle rect22(Point(250, 150), 200, 100);
//									// 447 page
//								rect00.set_fill_color(Color::yellow);
//								rect11.set_fill_color(Color::blue);
//								rect11.move(400, 0); // вправо от rect21
//								rect11.set_fill_color(Color::white);
//								
//								win3.set_label("rectangles 2");
//							
//								rect12.set_fill_color(Color::red);
//								rect21.set_fill_color(Color::green);
//							
//								win3.attach(rect00);
//								win3.attach(rect11);
//								win3.attach(rect12);
//								win3.attach(rect21);
//							
//								win3.put_on_top(rect00);
//							
//								rect00.set_color(Color::invisible);
//								rect11.set_color(Color::invisible);
//								rect12.set_color(Color::invisible);
//								rect21.set_color(Color::invisible);
//								rect22.set_color(Color::invisible);
//							
//								Vector_ref<Rectangle> rect;
//								Rectangle x(Point(100, 200), Point(200, 300));
//								rect.push_back(x);
//								rect.push_back(new Rectangle(Point(50, 60), Point(80, 90)));
//							
//								for (int i = 0; i < rect.size(); ++i)
//									rect[i].move(10, 10);
//							
//								win3.attach(x);

//					Vector_ref<Rectangle> vr;
//				
//					for (int i = 0; i < 16; ++i)
//						for (int j = 0; j < 16; ++j)
//						{
//							vr.push_back(new Rectangle(Point(i * 40, j * 40), 40, 40));
//				
//							vr[vr.size()-1].set_fill_color(Color(i * 16 + j));
//				
//							win3.attach(vr[vr.size()-1]);
//						}

//			Circle c1(Point(100, 200), 50);
//			Circle c2(Point(150, 200), 100);
//			Circle c3(Point(200, 200), 150);
//			win3.attach(c1);
//			win3.attach(c2);
//			win3.attach(c3);

//										Ellipse e1(Point(200, 200), 50, 50);
//										Ellipse e2(Point(200, 200), 100, 50);
//										Ellipse e3(Point(200, 200), 100, 150);
//										win3.attach(e1);
//										win3.attach(e2);
//										win3.attach(e3);
//		
//										Ellipse e4(Point(600, 200), 50, 50);
//										Ellipse e5(Point(600, 200), 100, 50);
//										Ellipse e6(Point(600, 200), 100, 150);
//										win3.attach(e4);
//										win3.attach(e5);
//										win3.attach(e6);

//			Marked_polyline mpl("1234");
//			mpl.add(Point(100, 100));
//			mpl.add(Point(150, 200));
//			mpl.add(Point(250, 250));
//			mpl.add(Point(300, 200));
//			win3.attach(mpl);


//	Marks pp("x");
//	pp.add(Point(100, 100));
//	pp.add(Point(150, 200));
//	pp.add(Point(250, 250));
//	pp.add(Point(300, 200));
//	win3.attach(pp);

//		Image rita(Point(0, 0), "rita.jpg");
//		Image path(Point(0, 0), "rita_path.gif");
//		path.set_mask(Point(50, 250), 600, 400); // выбираем желательную область
//		win3.attach(path);
//		win3.attach(rita);
//=======================================================================================================
/*
//=======================================================================================================
	8. Нарисуйте пять олимпийских колец. Если помните их цвета, то раскрасьте их.
use fl_arc()
//=======================================================================================================
Point t1(100, 100);
	Point t2(200, 200);
	Point t3(325, 200);
	Point t4(450, 200);
	Point t5(390, 250);
	Point t6(265, 250);

	Simple_window win(t1, 800, 600, "MyHome");

	Circle c1(t2, 50);
	c1.set_style(Line_style(Line_style::solid, 10));
	c1.set_color(Color::blue);
	win.attach(c1);

	Circle c2(t3, 50);
	c2.set_style(Line_style(Line_style::solid, 10));
	c2.set_color(Color::black);
	win.attach(c2);

	Circle c3(t4, 50);
	c3.set_style(Line_style(Line_style::solid, 10));
	c3.set_color(Color::red);
	win.attach(c3);

	Circle c4(t5, 50);
	c4.set_style(Line_style(Line_style::solid, 10));
	c4.set_color(Color::green);
	win.attach(c4);

	Circle c5(t6, 50);
	c5.set_style(Line_style(Line_style::solid, 10));
	c5.set_color(Color::yellow);
	win.attach(c5);

	win.wait_for_button();
//=======================================================================================================
	V	7. Нарисуйте двумерный дом анфас, как это делают дети: дверь, два окна и крыша с дымовой трубой.
Детали можете выбрать сами, можете даже нарисовать дымок из трубы.
//=======================================================================================================
	Point t1(200, 200);
	Point t2(240, 240);
	Point t3(440, 240);
	Point t4(325, 285);

	Point tl1(265, 240);
	Point tl2(265, 310);
	Point tl3(465, 240);
	Point tl4(465, 310);
	Point tl5(240, 275);
	Point tl6(290, 275);
	Point tl7(440, 275);
	Point tl8(490, 275);

	Simple_window win(t1, 800, 600, "MyHome");

	Polygon p1;
	p1.add(Point(135, 200));
	p1.add(Point(615, 200));
	p1.add(Point(365, 30));
	p1.set_style(Line_style(Line_style::solid, 5));
	p1.set_fill_color(Color::red);
	win.attach(p1);

	Rectangle r1(t1, 350, 200);
	r1.set_fill_color(Color::blue);
	r1.set_style(Line_style(Line_style::solid, 5));
	win.attach(r1);

	Rectangle r2(t2, 50, 70);
	r2.set_fill_color(Color::yellow);
	r2.set_style(Line_style(Line_style::solid, 3));
	win.attach(r2);

	Rectangle r3(t3, 50, 70);
	r3.set_fill_color(Color::yellow);
	r3.set_style(Line_style(Line_style::solid, 3));
	win.attach(r3);

	Line l1(tl1, tl2);
	l1.set_style(Line_style(Line_style::solid, 3));
	win.attach(l1);

	Line l2(tl3, tl4);
	l2.set_style(Line_style(Line_style::solid, 3));
	win.attach(l2);

	Line l3(tl5, tl6);
	l3.set_style(Line_style(Line_style::solid, 3));
	win.attach(l3);

	Line l4(tl7, tl8);
	l4.set_style(Line_style(Line_style::solid, 3));
	win.attach(l4);

	Rectangle r4(t4, 80, 115);
	r4.set_style(Line_style(Line_style::solid, 3));
	r4.set_fill_color(Color::dark_yellow);
	win.attach(r4);

	Polygon p2;
	p2.add(Point(459, 92));
	p2.add(Point(459, 15));
	p2.add(Point(480, 15));
	p2.add(Point(480, 108));
	p2.set_style(Line_style(Line_style::solid, 3));
	p2.set_fill_color(Color::black);
	win.attach(p2);

	Function sine1(sin, 0, 10, Point(474, 20), 5, 10, 20);
	sine1.set_style(Line_style(Line_style::solid, 2));
	win.attach(sine1);

	Function sine2(sin, 0, 10, Point(469, 20), 5, 10, 20);
	sine2.set_style(Line_style(Line_style::solid, 2));
	win.attach(sine2);

	Function sine3(sin, 0, 10, Point(464, 20), 5, 10, 20);
	sine3.set_style(Line_style(Line_style::solid, 2));
	win.attach(sine3);

	Function sine4(sin, 0, 10, Point(459, 20), 5, 10, 20);
	sine4.set_style(Line_style(Line_style::solid, 2));
	win.attach(sine4);

	Function sine5(sin, 0, 10, Point(458, 17), 5, 10, 20);
	sine5.set_style(Line_style(Line_style::solid, 2));
	win.attach(sine5);

	win.wait_for_button();
//=======================================================================================================
	V	6. Что произойдет, если вы нарисуете фигуру, которая не помещается в окне?
Что произойдет, если вы нарисуете окно, которое не помещается на экране?
Напишите две программы, иллюстрирующие эти эффекты.
//=======================================================================================================
	Point tl(-10, -10);
	Simple_window win(tl, 7500, 9200, "MyWindow");


	Rectangle r(tl, 70000, 100000);
	r.set_color(Color::blue);
	win.attach(r);
//=======================================================================================================
	V	5. Нарисуйте красную рамку шириной один дюйм вокруг прямоугольника,
высота которого составляет три четверти высоты вашего экрана, а ширина — две трети ширины экрана.
//=======================================================================================================
Point tl(50, 50);
	Point t2(49, 49);
	Simple_window win(tl, 600, 400, "MyWindow");

	int width = 600 / 1.5;
	int height = 400 - 100;

	Rectangle r(tl, width, height);
	r.set_color(Color::blue);
	win.attach(r);

	Rectangle r2(t2, width + 2, height + 2);
	r2.set_color(Color::red);
	win.attach(r2);
//=======================================================================================================
	V	4. Нарисуйте доску для игры в крестики-нолики размером 3×3, чередуя белые и красные квадраты.
//=======================================================================================================
Можно сделать через Rectangle

	Point t1(50, 50);
	Point t2(50, 100);
	Point t3(50, 150);
	Point t4(100, 50);
	Point t5(100, 100);
	Point t6(100, 150);
	Point t7(150, 50);
	Point t8(150, 100);
	Point t9(150, 150);
	Simple_window win(t1, 800, 600, "MyWindow");

	Rectangle r1(t1, 50, 50);
	r1.set_color(Color::red);
	r1.set_fill_color(Color::red);
	win.attach(r1);

	Rectangle r2(t2, 50, 50);
	r2.set_color(Color::white);
	r2.set_fill_color(Color::white);
	win.attach(r2);

	Rectangle r3(t3, 50, 50);
	r3.set_color(Color::red);
	r3.set_fill_color(Color::red);
	win.attach(r3);

	Rectangle r4(t4, 50, 50);
	r4.set_color(Color::white);
	r4.set_fill_color(Color::white);
	win.attach(r4);

	Rectangle r5(t5, 50, 50);
	r5.set_color(Color::red);
	r5.set_fill_color(Color::red);
	win.attach(r5);

	Rectangle r6(t6, 50, 50);
	r6.set_color(Color::white);
	r6.set_fill_color(Color::white);
	win.attach(r6);

	Rectangle r7(t7, 50, 50);
	r7.set_color(Color::red);
	r7.set_fill_color(Color::red);
	win.attach(r7);

	Rectangle r8(t8, 50, 50);
	r8.set_color(Color::white);
	r8.set_fill_color(Color::white);
	win.attach(r8);

	Rectangle r9(t9, 50, 50);
	r9.set_color(Color::red);
	r9.set_fill_color(Color::red);
	win.attach(r9);
	
	ИЛИ

Polygon poly_1;
	poly_1.add(Point(150, 200));
	poly_1.add(Point(150, 250));
	poly_1.add(Point(200, 250));
	poly_1.add(Point(200, 200));
	poly_1.set_color(Color::red);
	poly_1.set_fill_color(Color::red);
	win.attach(poly_1);

	Polygon poly_2;
	poly_2.add(Point(150, 250));
	poly_2.add(Point(150, 300));
	poly_2.add(Point(200, 300));
	poly_2.add(Point(200, 250));
	poly_2.set_color(Color::white);
	poly_2.set_fill_color(Color::white);
	win.attach(poly_2);

	Polygon poly_3;
	poly_3.add(Point(150, 300));
	poly_3.add(Point(150, 350));
	poly_3.add(Point(200, 350));
	poly_3.add(Point(200, 300));
	poly_3.set_color(Color::red);
	poly_3.set_fill_color(Color::red);
	win.attach(poly_3);

	Polygon poly_4;
	poly_4.add(Point(200, 200));
	poly_4.add(Point(200, 250));
	poly_4.add(Point(250, 250));
	poly_4.add(Point(250, 200));
	poly_4.set_color(Color::white);
	poly_4.set_fill_color(Color::white);
	win.attach(poly_4);

	Polygon poly_5;
	poly_5.add(Point(200, 250));
	poly_5.add(Point(200, 300));
	poly_5.add(Point(250, 300));
	poly_5.add(Point(250, 250));
	poly_5.set_color(Color::red);
	poly_5.set_fill_color(Color::red);
	win.attach(poly_5);

	Polygon poly_6;
	poly_6.add(Point(200, 300));
	poly_6.add(Point(200, 350));
	poly_6.add(Point(250, 350));
	poly_6.add(Point(250, 300));
	poly_6.set_color(Color::white);
	poly_6.set_fill_color(Color::white);
	win.attach(poly_6);

	Polygon poly_7;
	poly_7.add(Point(250, 200));
	poly_7.add(Point(250, 250));
	poly_7.add(Point(300, 250));
	poly_7.add(Point(300, 200));
	poly_7.set_color(Color::red);
	poly_7.set_fill_color(Color::red);
	win.attach(poly_7);

	Polygon poly_8;
	poly_8.add(Point(250, 250));
	poly_8.add(Point(250, 300));
	poly_8.add(Point(300, 300));
	poly_8.add(Point(300, 250));
	poly_8.set_color(Color::white);
	poly_8.set_fill_color(Color::white);
	win.attach(poly_8);

	Polygon poly_9;
	poly_9.add(Point(250, 300));
	poly_9.add(Point(250, 350));
	poly_9.add(Point(300, 350));
	poly_9.add(Point(300, 300));
	poly_9.set_color(Color::red);
	poly_9.set_fill_color(Color::red);
	win.attach(poly_9);
//=======================================================================================================
	V доп	2. Добавьте примеры из раздела 12.7 один за другим, сравнивая их друг с другом.
//=======================================================================================================
	V доп	3. Выполните программу, внеся небольшие изменения (например, измените цвет, местоположение фигур или количество точек) в каждом из примеров.
//=======================================================================================================
//=======================================================================================================
	V	1. Нарисуйте прямоугольник как объект класса Rectangle и как объект класса Polygon.
Сделайте линии объекта класса Polygon красными, а линии объекта класса Rectangle синими.
//=======================================================================================================
Rectangle r(tl, 300, 100);
	r.set_color(Color::dark_blue);
	win.attach(r);
	Polygon p;
	p.add(Point(200, 200));
	p.add(Point(300, 200));
	p.add(Point(300, 250));
	p.add(Point(200, 250));
	p.set_color(Color::dark_red);
	win.attach(p);
//=======================================================================================================
	V	2. Нарисуйте объект класса Rectangle с размерами 100×300 и поместите в него слово “Привет!”.
//=======================================================================================================
	Polygon p;
	p.add(Point(200, 200));
	p.add(Point(300, 200));
	p.add(Point(300, 250));
	p.add(Point(200, 250));
	p.set_color(Color::dark_red);
	win.attach(p);

	Text v(Point(220, 220), "HELLO");
	v.set_color(Color::dark_green);
	v.set_font_size(15);
	win.attach(v);
//=======================================================================================================
	V	3. Нарисуйте ваши инициалы высотой 150 пикселей. Используйте толстую линию. Нарисуйте каждый инициал другим цветом.
//=======================================================================================================
Text v(Point(120, 120), "V");
	v.set_style(Line_style(Line_style::solid, 20));
	v.set_color(Color::dark_green);
	v.set_font_size(150);
	win.attach(v);

	Text s(Point(240, 120), "S");
	s.set_style(Line_style(Line_style::solid, 20));
	s.set_color(Color::dark_blue);
	s.set_font_size(150);
	win.attach(s);

	Text r(Point(360, 120), "R");
	r.set_style(Line_style(Line_style::solid, 20));
	r.set_color(Color::dark_red);
	r.set_font_size(150);
	win.attach(r);
//=======================================================================================================
*/

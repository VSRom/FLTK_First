#include "PPP/Point.h"
#include "PPP/Simple_window.h"
#include "PPP/Graph.h"
#include "PPP/GUI.h"
#include "PPP/Window.h"

//=======================================================================================================
int main()
{
	Simple_window win{ Point{100, 100}, 600, 400, "My Window" };


	win.wait_for_button();
}
//=======================================================================================================

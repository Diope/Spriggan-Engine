#include "Window.h"



Window::Window()
{
}

bool Window::init()
{

	WNDCLASSEX wc;
	wc.cbClsExtra = NULL;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = NULL;
	wc.lpszClassName = "MyWindowClass";
	wc.lpszMenuName = "";
	wc.style = NULL;
	if (!::RegisterClassEx(&wc))
		return false;

	::CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, "MyWindowClass", "3DDX11 Application", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1024, 768, NULL, NULL, NULL, NULL);

	return true;
}


bool Window::release()
{
	return true;
}

Window::~Window()
{
}

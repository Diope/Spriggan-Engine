#include "Window.h"

//Window* window = nullptr;


Window::Window()
{
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg)
	{
	case WM_CREATE:
	{
		Window *window = (Window*)((LPCREATESTRUCT)lparam)->lpCreateParams;

		SetWindowLongPtr(hwnd, GWL_USERDATA, (LONG_PTR)window);
		window->onCreate();
		break;
	}

	case WM_DESTROY:
	{
		Window* window = (Window*)GetWindowLong(hwnd, GWL_USERDATA);
		window->onDestroy();
		::PostQuitMessage(0);
		break;
	}

	default:
		return ::DefWindowProc(hwnd, msg, wparam, lparam);
	}

	return NULL;

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
	wc.lpfnWndProc = &WndProc;

	if (!::RegisterClassEx(&wc))
		return false;

	/*if (!window)
		window = this;*/

	// Creation of the window
	m_hwnd = ::CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, "MyWindowClass", "D3D11 Application",
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1024, 768,
		NULL, NULL, NULL, this);

	if (!m_hwnd)
		return false;

	// Bring up window
	::ShowWindow(m_hwnd, SW_SHOW);
	::UpdateWindow(m_hwnd);

	// Window is initialized and running
	m_is_running = true;
	return true;
}

bool Window::broadcast()
{
	MSG msg;

	this->onUpdate();

	while (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	Sleep(1);

	return true;
}


bool Window::release()
{

	// Destroy Window
	if (!::DestroyWindow(m_hwnd))
		return false;

	return true;
}

bool Window::isRunning()
{

	return m_is_running;
}

void Window::onCreate()
{

}

void Window::onUpdate()
{

}

void Window::onDestroy()
{
	m_is_running = false;
}

Window::~Window()
{
}

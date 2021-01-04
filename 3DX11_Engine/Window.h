#pragma once
#include <Windows.h>



class Window
{
public:
	// Initialize the window
	Window();
	bool isRunning();
	RECT getClientWindowRect();


	// Events
	virtual void onCreate();
	virtual void onUpdate();
	virtual void onDestroy();
	virtual void onFocus();
	virtual void onKillFocus();

	// Release Window
	~Window();
private:
	bool broadcast();
protected:
	HWND m_hwnd;
	bool m_is_running;
	bool m_is_init = false;
};


#include "AppWindow.h"
#include "InputSystem.h"


int main()
{
	try
	{
		GraphicsEngine::create();
		InputSystem::create();
	}
	catch (...)
	{
		return -1;
	}
	
	{
		AppWindow app;
		if (app.init())
		{
			while (app.isRunning())
			{
				app.broadcast();
			}
		}
	}
	InputSystem::release();
	GraphicsEngine::release();

	return 0;
}